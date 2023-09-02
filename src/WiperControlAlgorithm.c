/*
 * File: WiperControlAlgorithm.c
 *
 * Code generated for Simulink model 'WiperControlAlgorithm'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sat Sep  2 03:43:29 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "WiperControlAlgorithm.h"

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
void WiperControlAlgorithm_step(void)
{
  real_T rtb_Saturation;
  real_T rtb_UnitDelay;

  /* Outputs for Atomic SubSystem: '<Root>/WiperControlAlgorithm' */
  /* UnitDelay: '<S2>/Unit Delay' */
  rtb_UnitDelay = rtDW.UnitDelay_DSTATE;

  /* MultiPortSwitch: '<S1>/Mode_Selection' incorporates:
   *  Constant: '<S1>/high_speed'
   *  Constant: '<S1>/low_speed'
   *  Constant: '<S1>/off'
   *  Inport: '<Root>/WiperMode'
   */
  switch (rtU.Mode) {
   case 0:
    rtb_UnitDelay = 0.0;
    break;

   case 1:
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/D_0'
     *  Inport: '<Root>/RainSensorError'
     *  Sum: '<S2>/Add1'
     */
    if (rtU.RainErr) {
      rtb_UnitDelay = 0.0;
    } else {
      /* MultiPortSwitch: '<S1>/Auto_Mode_SpeedReq' incorporates:
       *  Constant: '<S1>/SpeedReq0'
       *  Constant: '<S1>/SpeedReq1'
       *  Constant: '<S1>/SpeedReq2'
       *  Constant: '<S1>/SpeedReq3'
       *  Constant: '<S1>/SpeedReq4'
       *  Constant: '<S1>/SpeedReq5'
       *  Constant: '<S1>/SpeedReq6'
       *  Constant: '<S1>/SpeedReq7'
       *  Inport: '<Root>/WiperSpeed'
       */
      switch (rtU.Speed_Req_AutoMode) {
       case 0:
        rtb_Saturation = 0.0;
        break;

       case 1:
        rtb_Saturation = 0.4;
        break;

       case 2:
        rtb_Saturation = 0.45;
        break;

       case 3:
        rtb_Saturation = 0.5;
        break;

       case 4:
        rtb_Saturation = 0.55;
        break;

       case 5:
        rtb_Saturation = 0.6;
        break;

       case 6:
        rtb_Saturation = 0.65;
        break;

       default:
        rtb_Saturation = 0.7;
        break;
      }

      /* End of MultiPortSwitch: '<S1>/Auto_Mode_SpeedReq' */

      /* Sum: '<S2>/Add' */
      rtb_Saturation -= rtb_UnitDelay;

      /* Saturate: '<S2>/Saturation' */
      if (rtb_Saturation > 0.005) {
        rtb_Saturation = 0.005;
      } else if (rtb_Saturation < -0.005) {
        rtb_Saturation = -0.005;
      }

      /* End of Saturate: '<S2>/Saturation' */
      rtb_UnitDelay += rtb_Saturation;
    }

    /* End of Switch: '<S1>/Switch' */
    break;

   case 2:
    rtb_UnitDelay = 0.4;
    break;

   default:
    rtb_UnitDelay = 0.7;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Mode_Selection' */

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_UnitDelay;

  /* End of Outputs for SubSystem: '<Root>/WiperControlAlgorithm' */

  /* Outport: '<Root>/MotorDutyCycle-PWM' */
  rtY.MotorDutyCyclePWM = rtb_UnitDelay;

  /* Outputs for Atomic SubSystem: '<Root>/WiperControlAlgorithm' */
  /* Outport: '<Root>/SysState' incorporates:
   *  Logic: '<S1>/AND'
   */
  rtY.SysState = (rtb_UnitDelay != 0.0);

  /* End of Outputs for SubSystem: '<Root>/WiperControlAlgorithm' */
}

/* Model initialize function */
void WiperControlAlgorithm_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
