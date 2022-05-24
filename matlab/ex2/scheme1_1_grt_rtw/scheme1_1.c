/*
 * scheme1_1.c
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

#include "scheme1_1.h"
#include "scheme1_1_private.h"

/* Block signals (default storage) */
B_scheme1_1_T scheme1_1_B;

/* Continuous states */
X_scheme1_1_T scheme1_1_X;

/* Real-time model */
static RT_MODEL_scheme1_1_T scheme1_1_M_;
RT_MODEL_scheme1_1_T *const scheme1_1_M = &scheme1_1_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  scheme1_1_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void scheme1_1_step(void)
{
  real_T rtb_Integrator;
  real_T rtb_ZeroOrderHold1;
  real_T rtb_u;
  if (rtmIsMajorTimeStep(scheme1_1_M)) {
    /* set solver stop time */
    if (!(scheme1_1_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&scheme1_1_M->solverInfo,
                            ((scheme1_1_M->Timing.clockTickH0 + 1) *
        scheme1_1_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&scheme1_1_M->solverInfo,
                            ((scheme1_1_M->Timing.clockTick0 + 1) *
        scheme1_1_M->Timing.stepSize0 + scheme1_1_M->Timing.clockTickH0 *
        scheme1_1_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(scheme1_1_M)) {
    scheme1_1_M->Timing.t[0] = rtsiGetT(&scheme1_1_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(scheme1_1_M)) {
    /* Step: '<Root>/Step' */
    if ((((scheme1_1_M->Timing.clockTick1+scheme1_1_M->Timing.clockTickH1*
           4294967296.0)) * 0.01) < scheme1_1_P.Step_Time) {
      /* Step: '<Root>/Step' */
      scheme1_1_B.Step = scheme1_1_P.Step_Y0;
    } else {
      /* Step: '<Root>/Step' */
      scheme1_1_B.Step = scheme1_1_P.Step_YFinal;
    }

    /* End of Step: '<Root>/Step' */
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  scheme1_1_B.y = 0.0;
  scheme1_1_B.y += scheme1_1_P.TransferFcn1_C * scheme1_1_X.TransferFcn1_CSTATE;

  /* Sum: '<Root>/Sum' */
  rtb_u = scheme1_1_B.Step - scheme1_1_B.y;

  /* Gain: '<Root>/kp1' */
  rtb_Integrator = scheme1_1_P.kp * rtb_u;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Integrator: '<Root>/Integrator3'
   */
  scheme1_1_B.Sum2 = scheme1_1_X.Integrator3_CSTATE + rtb_Integrator;
  if (rtmIsMajorTimeStep(scheme1_1_M)) {
  }

  /* Integrator: '<Root>/Integrator1' */
  scheme1_1_B.ISE = scheme1_1_X.Integrator1_CSTATE;

  /* Integrator: '<Root>/Integrator2' */
  scheme1_1_B.IAE = scheme1_1_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(scheme1_1_M)) {
    /* Step: '<Root>/Step1' */
    if ((((scheme1_1_M->Timing.clockTick1+scheme1_1_M->Timing.clockTickH1*
           4294967296.0)) * 0.01) < scheme1_1_P.Step1_Time) {
      /* Step: '<Root>/Step1' */
      scheme1_1_B.Step1 = scheme1_1_P.Step1_Y0;
    } else {
      /* Step: '<Root>/Step1' */
      scheme1_1_B.Step1 = scheme1_1_P.Step1_YFinal;
    }

    /* End of Step: '<Root>/Step1' */
  }

  /* Abs: '<Root>/Abs' */
  scheme1_1_B.Abs = fabs(rtb_u);

  /* Math: '<Root>/Math Function'
   *
   * About '<Root>/Math Function':
   *  Operator: magnitude^2
   */
  scheme1_1_B.MathFunction = rtb_u * rtb_u;

  /* TransferFcn: '<Root>/Transfer Fcn' */
  scheme1_1_B.TransferFcn = 0.0;
  scheme1_1_B.TransferFcn += scheme1_1_P.TransferFcn_C *
    scheme1_1_X.TransferFcn_CSTATE;

  /* Gain: '<Root>/ki' */
  scheme1_1_B.ki = 1.0 / scheme1_1_P.Ti * rtb_Integrator;

  /* TransferFcn: '<Root>/Transfer Fcn3' */
  scheme1_1_B.y_h = 0.0;
  scheme1_1_B.y_h += scheme1_1_P.TransferFcn3_C *
    scheme1_1_X.TransferFcn3_CSTATE;

  /* Sum: '<Root>/Sum1' */
  scheme1_1_B.Sum1 = scheme1_1_B.Step1 - scheme1_1_B.y_h;
  if (rtmIsMajorTimeStep(scheme1_1_M)) {
    /* ZeroOrderHold: '<Root>/Zero-Order Hold1' */
    rtb_ZeroOrderHold1 = scheme1_1_B.Sum1;

    /* Math: '<Root>/Math Function1'
     *
     * About '<Root>/Math Function1':
     *  Operator: magnitude^2
     */
    scheme1_1_B.MathFunction1 = rtb_ZeroOrderHold1 * rtb_ZeroOrderHold1;

    /* Abs: '<Root>/Abs1' */
    scheme1_1_B.Abs1 = fabs(rtb_ZeroOrderHold1);
  }

  /* TransferFcn: '<Root>/Transfer Fcn4' */
  scheme1_1_B.ISE_b = 0.0;
  scheme1_1_B.ISE_b += scheme1_1_P.TransferFcn4_D * scheme1_1_B.MathFunction1;

  /* TransferFcn: '<Root>/Transfer Fcn5' */
  scheme1_1_B.IAE_e = 0.0;
  scheme1_1_B.IAE_e += scheme1_1_P.TransferFcn5_D * scheme1_1_B.Abs1;
  if (rtmIsMajorTimeStep(scheme1_1_M)) {
    /* Gain: '<S27>/Derivative Gain' */
    scheme1_1_B.DerivativeGain = scheme1_1_P.PIDController1_D *
      rtb_ZeroOrderHold1;

    /* Gain: '<S30>/Integral Gain' */
    scheme1_1_B.IntegralGain = scheme1_1_P.PIDController1_I * rtb_ZeroOrderHold1;

    /* Gain: '<S38>/Proportional Gain' */
    scheme1_1_B.ProportionalGain = scheme1_1_P.PIDController1_P *
      rtb_ZeroOrderHold1;
  }

  /* Gain: '<S36>/Filter Coefficient' incorporates:
   *  Integrator: '<S28>/Filter'
   *  Sum: '<S28>/SumD'
   */
  scheme1_1_B.FilterCoefficient = (scheme1_1_B.DerivativeGain -
    scheme1_1_X.Filter_CSTATE) * scheme1_1_P.PIDController1_N;

  /* Sum: '<S42>/Sum' incorporates:
   *  Integrator: '<S33>/Integrator'
   */
  scheme1_1_B.Sum = (scheme1_1_B.ProportionalGain +
                     scheme1_1_X.Integrator_CSTATE) +
    scheme1_1_B.FilterCoefficient;

  /* TransferFcn: '<Root>/Transfer Fcn2' */
  scheme1_1_B.TransferFcn2 = 0.0;
  scheme1_1_B.TransferFcn2 += scheme1_1_P.TransferFcn2_C *
    scheme1_1_X.TransferFcn2_CSTATE;
  if (rtmIsMajorTimeStep(scheme1_1_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(scheme1_1_M->rtwLogInfo, (scheme1_1_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(scheme1_1_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(scheme1_1_M)!=-1) &&
          !((rtmGetTFinal(scheme1_1_M)-(((scheme1_1_M->Timing.clockTick1+
               scheme1_1_M->Timing.clockTickH1* 4294967296.0)) * 0.01)) >
            (((scheme1_1_M->Timing.clockTick1+scheme1_1_M->Timing.clockTickH1*
               4294967296.0)) * 0.01) * (DBL_EPSILON))) {
        rtmSetErrorStatus(scheme1_1_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&scheme1_1_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++scheme1_1_M->Timing.clockTick0)) {
      ++scheme1_1_M->Timing.clockTickH0;
    }

    scheme1_1_M->Timing.t[0] = rtsiGetSolverStopTime(&scheme1_1_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      scheme1_1_M->Timing.clockTick1++;
      if (!scheme1_1_M->Timing.clockTick1) {
        scheme1_1_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void scheme1_1_derivatives(void)
{
  XDot_scheme1_1_T *_rtXdot;
  _rtXdot = ((XDot_scheme1_1_T *) scheme1_1_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = scheme1_1_B.ki;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += scheme1_1_P.TransferFcn1_A *
    scheme1_1_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += scheme1_1_B.TransferFcn;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = scheme1_1_B.MathFunction;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = scheme1_1_B.Abs;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += scheme1_1_P.TransferFcn_A *
    scheme1_1_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += scheme1_1_B.Sum2;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE = 0.0;
  _rtXdot->TransferFcn3_CSTATE += scheme1_1_P.TransferFcn3_A *
    scheme1_1_X.TransferFcn3_CSTATE;
  _rtXdot->TransferFcn3_CSTATE += scheme1_1_B.TransferFcn2;

  /* Derivatives for Integrator: '<S28>/Filter' */
  _rtXdot->Filter_CSTATE = scheme1_1_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S33>/Integrator' */
  _rtXdot->Integrator_CSTATE = scheme1_1_B.IntegralGain;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += scheme1_1_P.TransferFcn2_A *
    scheme1_1_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += scheme1_1_B.Sum;
}

/* Model initialize function */
void scheme1_1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)scheme1_1_M, 0,
                sizeof(RT_MODEL_scheme1_1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&scheme1_1_M->solverInfo,
                          &scheme1_1_M->Timing.simTimeStep);
    rtsiSetTPtr(&scheme1_1_M->solverInfo, &rtmGetTPtr(scheme1_1_M));
    rtsiSetStepSizePtr(&scheme1_1_M->solverInfo, &scheme1_1_M->Timing.stepSize0);
    rtsiSetdXPtr(&scheme1_1_M->solverInfo, &scheme1_1_M->derivs);
    rtsiSetContStatesPtr(&scheme1_1_M->solverInfo, (real_T **)
                         &scheme1_1_M->contStates);
    rtsiSetNumContStatesPtr(&scheme1_1_M->solverInfo,
      &scheme1_1_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&scheme1_1_M->solverInfo,
      &scheme1_1_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&scheme1_1_M->solverInfo,
      &scheme1_1_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&scheme1_1_M->solverInfo,
      &scheme1_1_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&scheme1_1_M->solverInfo, (&rtmGetErrorStatus
      (scheme1_1_M)));
    rtsiSetRTModelPtr(&scheme1_1_M->solverInfo, scheme1_1_M);
  }

  rtsiSetSimTimeStep(&scheme1_1_M->solverInfo, MAJOR_TIME_STEP);
  scheme1_1_M->intgData.f[0] = scheme1_1_M->odeF[0];
  scheme1_1_M->contStates = ((X_scheme1_1_T *) &scheme1_1_X);
  rtsiSetSolverData(&scheme1_1_M->solverInfo, (void *)&scheme1_1_M->intgData);
  rtsiSetSolverName(&scheme1_1_M->solverInfo,"ode1");
  rtmSetTPtr(scheme1_1_M, &scheme1_1_M->Timing.tArray[0]);
  rtmSetTFinal(scheme1_1_M, 25.0);
  scheme1_1_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    scheme1_1_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(scheme1_1_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(scheme1_1_M->rtwLogInfo, (NULL));
    rtliSetLogT(scheme1_1_M->rtwLogInfo, "tout");
    rtliSetLogX(scheme1_1_M->rtwLogInfo, "");
    rtliSetLogXFinal(scheme1_1_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(scheme1_1_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(scheme1_1_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(scheme1_1_M->rtwLogInfo, 0);
    rtliSetLogDecimation(scheme1_1_M->rtwLogInfo, 1);
    rtliSetLogY(scheme1_1_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(scheme1_1_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(scheme1_1_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &scheme1_1_B), 0,
                sizeof(B_scheme1_1_T));

  /* states (continuous) */
  {
    (void) memset((void *)&scheme1_1_X, 0,
                  sizeof(X_scheme1_1_T));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(scheme1_1_M->rtwLogInfo, 0.0, rtmGetTFinal
    (scheme1_1_M), scheme1_1_M->Timing.stepSize0, (&rtmGetErrorStatus
    (scheme1_1_M)));

  /* InitializeConditions for Integrator: '<Root>/Integrator3' */
  scheme1_1_X.Integrator3_CSTATE = scheme1_1_P.Integrator3_IC;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  scheme1_1_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  scheme1_1_X.Integrator1_CSTATE = scheme1_1_P.Tp;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  scheme1_1_X.Integrator2_CSTATE = scheme1_1_P.Integrator2_IC;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  scheme1_1_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */
  scheme1_1_X.TransferFcn3_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S28>/Filter' */
  scheme1_1_X.Filter_CSTATE = scheme1_1_P.PIDController1_InitialCondition;

  /* InitializeConditions for Integrator: '<S33>/Integrator' */
  scheme1_1_X.Integrator_CSTATE = scheme1_1_P.PIDController1_InitialConditi_l;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  scheme1_1_X.TransferFcn2_CSTATE = 0.0;
}

/* Model terminate function */
void scheme1_1_terminate(void)
{
  /* (no terminate code required) */
}
