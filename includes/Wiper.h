/*
 * File: Wiper.h
 *
 * Code generated for Simulink model 'Wiper'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sat Sep  2 03:35:56 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Wiper_h_
#define RTW_HEADER_Wiper_h_
#ifndef Wiper_COMMON_INCLUDES_
#define Wiper_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Wiper_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Model entry point functions */
extern void Wiper_initialize(void);
extern void Wiper_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion' : Unused code path elimination
 * Block '<Root>/Data Type Conversion1' : Unused code path elimination
 * Block '<Root>/Data Type Conversion2' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S1>/FromWs' : Unused code path elimination
 * Block '<S3>/AND' : Unused code path elimination
 * Block '<S3>/Active_flag' : Unused code path elimination
 * Block '<S3>/Auto_Mode_SpeedReq' : Unused code path elimination
 * Block '<S3>/D_0' : Unused code path elimination
 * Block '<S3>/Mode_Selection' : Unused code path elimination
 * Block '<S4>/Add' : Unused code path elimination
 * Block '<S4>/Add1' : Unused code path elimination
 * Block '<S4>/Saturation' : Unused code path elimination
 * Block '<S4>/Unit Delay' : Unused code path elimination
 * Block '<S3>/SpeedReq0' : Unused code path elimination
 * Block '<S3>/SpeedReq1' : Unused code path elimination
 * Block '<S3>/SpeedReq2' : Unused code path elimination
 * Block '<S3>/SpeedReq3' : Unused code path elimination
 * Block '<S3>/SpeedReq4' : Unused code path elimination
 * Block '<S3>/SpeedReq5' : Unused code path elimination
 * Block '<S3>/SpeedReq6' : Unused code path elimination
 * Block '<S3>/SpeedReq7' : Unused code path elimination
 * Block '<S3>/Switch' : Unused code path elimination
 * Block '<S3>/high_speed' : Unused code path elimination
 * Block '<S3>/low_speed' : Unused code path elimination
 * Block '<S3>/off' : Unused code path elimination
 */

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
 * '<Root>' : 'Wiper'
 * '<S1>'   : 'Wiper/Signal Builder'
 * '<S2>'   : 'Wiper/WiperMotorControl'
 * '<S3>'   : 'Wiper/WiperMotorControl/WiperControlAlgorithm'
 * '<S4>'   : 'Wiper/WiperMotorControl/WiperControlAlgorithm/Smoothing_SybSys'
 */
#endif                                 /* RTW_HEADER_Wiper_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
