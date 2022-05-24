/*
 * scheme1_1.h
 *
 * Code generation for model "scheme1_1".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue May 24 13:42:47 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_scheme1_1_h_
#define RTW_HEADER_scheme1_1_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef scheme1_1_COMMON_INCLUDES_
#define scheme1_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* scheme1_1_COMMON_INCLUDES_ */

#include "scheme1_1_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Step;                         /* '<Root>/Step' */
  real_T y;                            /* '<Root>/Transfer Fcn1' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T ISE;                          /* '<Root>/Integrator1' */
  real_T IAE;                          /* '<Root>/Integrator2' */
  real_T Abs;                          /* '<Root>/Abs' */
  real_T MathFunction;                 /* '<Root>/Math Function' */
  real_T TransferFcn;                  /* '<Root>/Transfer Fcn' */
  real_T ki;                           /* '<Root>/ki' */
  real_T Step1;                        /* '<Root>/Step1' */
  real_T y_h;                          /* '<Root>/Transfer Fcn3' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T MathFunction1;                /* '<Root>/Math Function1' */
  real_T ISE_b;                        /* '<Root>/Transfer Fcn4' */
  real_T Abs1;                         /* '<Root>/Abs1' */
  real_T IAE_e;                        /* '<Root>/Transfer Fcn5' */
  real_T DerivativeGain;               /* '<S27>/Derivative Gain' */
  real_T IntegralGain;                 /* '<S30>/Integral Gain' */
  real_T FilterCoefficient;            /* '<S36>/Filter Coefficient' */
  real_T ProportionalGain;             /* '<S38>/Proportional Gain' */
  real_T Sum;                          /* '<S42>/Sum' */
  real_T TransferFcn2;                 /* '<Root>/Transfer Fcn2' */
} B_scheme1_1_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T TransferFcn3_CSTATE;          /* '<Root>/Transfer Fcn3' */
  real_T Filter_CSTATE;                /* '<S28>/Filter' */
  real_T Integrator_CSTATE;            /* '<S33>/Integrator' */
  real_T TransferFcn2_CSTATE;          /* '<Root>/Transfer Fcn2' */
} X_scheme1_1_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T TransferFcn3_CSTATE;          /* '<Root>/Transfer Fcn3' */
  real_T Filter_CSTATE;                /* '<S28>/Filter' */
  real_T Integrator_CSTATE;            /* '<S33>/Integrator' */
  real_T TransferFcn2_CSTATE;          /* '<Root>/Transfer Fcn2' */
} XDot_scheme1_1_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator3_CSTATE;        /* '<Root>/Integrator3' */
  boolean_T TransferFcn1_CSTATE;       /* '<Root>/Transfer Fcn1' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
  boolean_T TransferFcn3_CSTATE;       /* '<Root>/Transfer Fcn3' */
  boolean_T Filter_CSTATE;             /* '<S28>/Filter' */
  boolean_T Integrator_CSTATE;         /* '<S33>/Integrator' */
  boolean_T TransferFcn2_CSTATE;       /* '<Root>/Transfer Fcn2' */
} XDis_scheme1_1_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_scheme1_1_T_ {
  real_T Ti;                           /* Variable: Ti
                                        * Referenced by: '<Root>/ki'
                                        */
  real_T Tp;                           /* Variable: Tp
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T kp;                           /* Variable: kp
                                        * Referenced by: '<Root>/kp1'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S27>/Derivative Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S30>/Integral Gain'
                                        */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S28>/Filter'
                               */
  real_T PIDController1_InitialConditi_l;
                              /* Mask Parameter: PIDController1_InitialConditi_l
                               * Referenced by: '<S33>/Integrator'
                               */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S36>/Filter Coefficient'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S38>/Proportional Gain'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  real_T Step_Time;                    /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T Step1_Time;                   /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T TransferFcn3_A;               /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C;               /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  real_T TransferFcn4_D;               /* Computed Parameter: TransferFcn4_D
                                        * Referenced by: '<Root>/Transfer Fcn4'
                                        */
  real_T TransferFcn5_D;               /* Computed Parameter: TransferFcn5_D
                                        * Referenced by: '<Root>/Transfer Fcn5'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_scheme1_1_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_scheme1_1_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][9];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_scheme1_1_T scheme1_1_P;

/* Block signals (default storage) */
extern B_scheme1_1_T scheme1_1_B;

/* Continuous states (default storage) */
extern X_scheme1_1_T scheme1_1_X;

/* Model entry point functions */
extern void scheme1_1_initialize(void);
extern void scheme1_1_step(void);
extern void scheme1_1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_scheme1_1_T *const scheme1_1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'scheme1_1'
 * '<S1>'   : 'scheme1_1/PID Controller1'
 * '<S2>'   : 'scheme1_1/PID Controller1/Anti-windup'
 * '<S3>'   : 'scheme1_1/PID Controller1/D Gain'
 * '<S4>'   : 'scheme1_1/PID Controller1/Filter'
 * '<S5>'   : 'scheme1_1/PID Controller1/Filter ICs'
 * '<S6>'   : 'scheme1_1/PID Controller1/I Gain'
 * '<S7>'   : 'scheme1_1/PID Controller1/Ideal P Gain'
 * '<S8>'   : 'scheme1_1/PID Controller1/Ideal P Gain Fdbk'
 * '<S9>'   : 'scheme1_1/PID Controller1/Integrator'
 * '<S10>'  : 'scheme1_1/PID Controller1/Integrator ICs'
 * '<S11>'  : 'scheme1_1/PID Controller1/N Copy'
 * '<S12>'  : 'scheme1_1/PID Controller1/N Gain'
 * '<S13>'  : 'scheme1_1/PID Controller1/P Copy'
 * '<S14>'  : 'scheme1_1/PID Controller1/Parallel P Gain'
 * '<S15>'  : 'scheme1_1/PID Controller1/Reset Signal'
 * '<S16>'  : 'scheme1_1/PID Controller1/Saturation'
 * '<S17>'  : 'scheme1_1/PID Controller1/Saturation Fdbk'
 * '<S18>'  : 'scheme1_1/PID Controller1/Sum'
 * '<S19>'  : 'scheme1_1/PID Controller1/Sum Fdbk'
 * '<S20>'  : 'scheme1_1/PID Controller1/Tracking Mode'
 * '<S21>'  : 'scheme1_1/PID Controller1/Tracking Mode Sum'
 * '<S22>'  : 'scheme1_1/PID Controller1/Tsamp - Integral'
 * '<S23>'  : 'scheme1_1/PID Controller1/Tsamp - Ngain'
 * '<S24>'  : 'scheme1_1/PID Controller1/postSat Signal'
 * '<S25>'  : 'scheme1_1/PID Controller1/preSat Signal'
 * '<S26>'  : 'scheme1_1/PID Controller1/Anti-windup/Passthrough'
 * '<S27>'  : 'scheme1_1/PID Controller1/D Gain/Internal Parameters'
 * '<S28>'  : 'scheme1_1/PID Controller1/Filter/Cont. Filter'
 * '<S29>'  : 'scheme1_1/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S30>'  : 'scheme1_1/PID Controller1/I Gain/Internal Parameters'
 * '<S31>'  : 'scheme1_1/PID Controller1/Ideal P Gain/Passthrough'
 * '<S32>'  : 'scheme1_1/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S33>'  : 'scheme1_1/PID Controller1/Integrator/Continuous'
 * '<S34>'  : 'scheme1_1/PID Controller1/Integrator ICs/Internal IC'
 * '<S35>'  : 'scheme1_1/PID Controller1/N Copy/Disabled'
 * '<S36>'  : 'scheme1_1/PID Controller1/N Gain/Internal Parameters'
 * '<S37>'  : 'scheme1_1/PID Controller1/P Copy/Disabled'
 * '<S38>'  : 'scheme1_1/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S39>'  : 'scheme1_1/PID Controller1/Reset Signal/Disabled'
 * '<S40>'  : 'scheme1_1/PID Controller1/Saturation/Passthrough'
 * '<S41>'  : 'scheme1_1/PID Controller1/Saturation Fdbk/Disabled'
 * '<S42>'  : 'scheme1_1/PID Controller1/Sum/Sum_PID'
 * '<S43>'  : 'scheme1_1/PID Controller1/Sum Fdbk/Disabled'
 * '<S44>'  : 'scheme1_1/PID Controller1/Tracking Mode/Disabled'
 * '<S45>'  : 'scheme1_1/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S46>'  : 'scheme1_1/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S47>'  : 'scheme1_1/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S48>'  : 'scheme1_1/PID Controller1/postSat Signal/Forward_Path'
 * '<S49>'  : 'scheme1_1/PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_scheme1_1_h_ */
