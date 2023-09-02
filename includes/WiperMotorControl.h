/*
 * File: WiperMotorControl.h
 *
 * Code generated for Simulink model 'WiperMotorControl'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sat Sep  2 03:45:18 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_WiperMotorControl_h_
#define RTW_HEADER_WiperMotorControl_h_
#ifndef WiperMotorControl_COMMON_INCLUDES_
#define WiperMotorControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* WiperMotorControl_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S3>/Unit Delay' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T Mode;                        /* '<Root>/WiperMode' */
  boolean_T RainErr;                   /* '<Root>/RainSensorError' */
  uint8_T Speed_Req_AutoMode;          /* '<Root>/WiperSpeed' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T PWM_D;                        /* '<Root>/PWM_D' */
  boolean_T SysState;                  /* '<Root>/SysState' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void WiperMotorControl_initialize(void);
extern void WiperMotorControl_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Wiper/WiperMotorControl')    - opens subsystem Wiper/WiperMotorControl
 * hilite_system('Wiper/WiperMotorControl/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Wiper'
 * '<S1>'   : 'Wiper/WiperMotorControl'
 * '<S2>'   : 'Wiper/WiperMotorControl/WiperControlAlgorithm'
 * '<S3>'   : 'Wiper/WiperMotorControl/WiperControlAlgorithm/Smoothing_SybSys'
 */
#endif                                 /* RTW_HEADER_WiperMotorControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
