/*
 * File: WiperMotorControl.c
 *
 * Code generated for Simulink model 'WiperMotorControl'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sat Sep  2 04:17:57 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "WiperMotorControl.h"

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
void WiperMotorControl_step(void)
{
  real_T rtb_Auto_Mode_SpeedReq;
  real_T rtb_UnitDelay;

  /* Outputs for Atomic SubSystem: '<S1>/WiperControlAlgorithm' */
  /* MultiPortSwitch: '<S2>/Auto_Mode_SpeedReq' incorporates:
   *  Constant: '<S2>/SpeedReq0'
   *  Constant: '<S2>/SpeedReq1'
   *  Constant: '<S2>/SpeedReq2'
   *  Constant: '<S2>/SpeedReq3'
   *  Constant: '<S2>/SpeedReq4'
   *  Constant: '<S2>/SpeedReq5'
   *  Constant: '<S2>/SpeedReq6'
   *  Constant: '<S2>/SpeedReq7'
   *  Inport: '<Root>/WiperSpeed'
   */
  switch (rtU.Speed_Req_AutoMode) {
   case 0:
    rtb_Auto_Mode_SpeedReq = 0.0;
    break;

   case 1:
    rtb_Auto_Mode_SpeedReq = 0.4;
    break;

   case 2:
    rtb_Auto_Mode_SpeedReq = 0.45;
    break;

   case 3:
    rtb_Auto_Mode_SpeedReq = 0.5;
    break;

   case 4:
    rtb_Auto_Mode_SpeedReq = 0.55;
    break;

   case 5:
    rtb_Auto_Mode_SpeedReq = 0.6;
    break;

   case 6:
    rtb_Auto_Mode_SpeedReq = 0.65;
    break;

   default:
    rtb_Auto_Mode_SpeedReq = 0.7;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Auto_Mode_SpeedReq' */

  /* Outputs for Atomic SubSystem: '<S2>/Smoothing_SybSys' */
  /* UnitDelay: '<S3>/Unit Delay' */
  rtb_UnitDelay = rtDW.UnitDelay_DSTATE;

  /* End of Outputs for SubSystem: '<S2>/Smoothing_SybSys' */

  /* MultiPortSwitch: '<S2>/Mode_Selection' incorporates:
   *  Constant: '<S2>/high_speed'
   *  Constant: '<S2>/low_speed'
   *  Constant: '<S2>/off'
   *  Inport: '<Root>/WiperMode'
   */
  switch (rtU.Mode) {
   case 0:
    rtb_Auto_Mode_SpeedReq = 0.0;
    break;

   case 1:
    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/D_0'
     *  Inport: '<Root>/RainSensorError'
     *  Sum: '<S3>/Add1'
     */
    if (rtU.RainErr) {
      rtb_Auto_Mode_SpeedReq = 0.0;
    } else {
      /* Outputs for Atomic SubSystem: '<S2>/Smoothing_SybSys' */
      /* Sum: '<S3>/Add' */
      rtb_Auto_Mode_SpeedReq -= rtb_UnitDelay;

      /* Saturate: '<S3>/Saturation' */
      if (rtb_Auto_Mode_SpeedReq > 0.005) {
        rtb_Auto_Mode_SpeedReq = 0.005;
      } else if (rtb_Auto_Mode_SpeedReq < -0.005) {
        rtb_Auto_Mode_SpeedReq = -0.005;
      }

      /* End of Saturate: '<S3>/Saturation' */
      rtb_Auto_Mode_SpeedReq += rtb_UnitDelay;

      /* End of Outputs for SubSystem: '<S2>/Smoothing_SybSys' */
    }

    /* End of Switch: '<S2>/Switch' */
    break;

   case 2:
    rtb_Auto_Mode_SpeedReq = 0.4;
    break;

   default:
    rtb_Auto_Mode_SpeedReq = 0.7;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Mode_Selection' */

  /* Update for Atomic SubSystem: '<S2>/Smoothing_SybSys' */
  /* Update for UnitDelay: '<S3>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Auto_Mode_SpeedReq;

  /* End of Update for SubSystem: '<S2>/Smoothing_SybSys' */
  /* End of Outputs for SubSystem: '<S1>/WiperControlAlgorithm' */

  /* Outport: '<Root>/PWM_D' */
  rtY.PWM_D = rtb_Auto_Mode_SpeedReq;

  /* Outputs for Atomic SubSystem: '<S1>/WiperControlAlgorithm' */
  /* Outport: '<Root>/SysState' incorporates:
   *  Logic: '<S2>/AND'
   */
  rtY.SysState = (rtb_Auto_Mode_SpeedReq != 0.0);

  /* End of Outputs for SubSystem: '<S1>/WiperControlAlgorithm' */
}

/* Model initialize function */
void WiperMotorControl_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
