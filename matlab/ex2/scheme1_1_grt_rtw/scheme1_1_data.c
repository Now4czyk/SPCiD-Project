/*
 * scheme1_1_data.c
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

/* Block parameters (default storage) */
P_scheme1_1_T scheme1_1_P = {
  /* Variable: Ti
   * Referenced by: '<Root>/ki'
   */
  2.5,

  /* Variable: Tp
   * Referenced by: '<Root>/Integrator1'
   */
  0.01,

  /* Variable: kp
   * Referenced by: '<Root>/kp1'
   */
  1.5,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S27>/Derivative Gain'
   */
  0.7,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S30>/Integral Gain'
   */
  0.8,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S28>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_l
   * Referenced by: '<S33>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S36>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S38>/Proportional Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  -1.25,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  1.25,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -0.16949152542372881,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  1.0169491525423728,

  /* Expression: 0
   * Referenced by: '<Root>/Step1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step1'
   */
  1.0,

  /* Computed Parameter: TransferFcn3_A
   * Referenced by: '<Root>/Transfer Fcn3'
   */
  -1.25,

  /* Computed Parameter: TransferFcn3_C
   * Referenced by: '<Root>/Transfer Fcn3'
   */
  1.25,

  /* Computed Parameter: TransferFcn4_D
   * Referenced by: '<Root>/Transfer Fcn4'
   */
  0.01,

  /* Computed Parameter: TransferFcn5_D
   * Referenced by: '<Root>/Transfer Fcn5'
   */
  0.01,

  /* Computed Parameter: TransferFcn2_A
   * Referenced by: '<Root>/Transfer Fcn2'
   */
  -0.16949152542372881,

  /* Computed Parameter: TransferFcn2_C
   * Referenced by: '<Root>/Transfer Fcn2'
   */
  1.0169491525423728
};
