/*
 * File: WiperControlAlgorithm.h
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

#ifndef RTW_HEADER_WiperControlAlgorithm_h_
#define RTW_HEADER_WiperControlAlgorithm_h_
#ifndef WiperControlAlgorithm_COMMON_INCLUDES_
#define WiperControlAlgorithm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                              /* WiperControlAlgorithm_COMMON_INCLUDES_ */

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
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T Mode;                        /* '<Root>/WiperMode' */
  boolean_T RainErr;                   /* '<Root>/RainSensorError' */
  uint8_T Speed_Req_AutoMode;          /* '<Root>/WiperSpeed' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T MotorDutyCyclePWM;            /* '<Root>/MotorDutyCycle-PWM' */
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
extern void WiperControlAlgorithm_initialize(void);
extern void WiperControlAlgorithm_step(void);

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
 * hilite_system('Wiper/WiperMotorControl/WiperControlAlgorithm')    - opens subsystem Wiper/WiperMotorControl/WiperControlAlgorithm
 * hilite_system('Wiper/WiperMotorControl/WiperControlAlgorithm/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Wiper/WiperMotorControl'
 * '<S1>'   : 'Wiper/WiperMotorControl/WiperControlAlgorithm'
 * '<S2>'   : 'Wiper/WiperMotorControl/WiperControlAlgorithm/Smoothing_SybSys'
 */
#endif                                 /* RTW_HEADER_WiperControlAlgorithm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
