/*
 * File: Smoothing_SybSys.c
 *
 * Code generated for Simulink model 'Smoothing_SybSys'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sat Sep  2 03:41:23 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Smoothing_SybSys.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Smoothing_SybSys_step(void)
{
  real_T u0;

  /* Sum: '<S1>/Add' incorporates:
   *  Inport: '<Root>/Auto_Req_Value'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  u0 = rtU.Auto_Req_Value - rtDW.UnitDelay_DSTATE;

  /* Saturate: '<S1>/Saturation' */
  if (u0 > 0.005) {
    u0 = 0.005;
  } else if (u0 < -0.005) {
    u0 = -0.005;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Outport: '<Root>/Auto_D_Out' incorporates:
   *  Sum: '<S1>/Add1'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtY.Auto_D_Out = u0 + rtDW.UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  Inport: '<Root>/Prev_D_Value'
   */
  rtDW.UnitDelay_DSTATE = rtU.Duty_Cycle;
}

/* Model initialize function */
void Smoothing_SybSys_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
