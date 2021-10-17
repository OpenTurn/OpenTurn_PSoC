/*
 * resources.h
 *
 *  Created on: 07.02.2021
 *      Author: achim
 */



#ifndef MOTOR_CONTROL_RESOURCES_H_
#define MOTOR_CONTROL_RESOURCES_H_
#include "stdlib.h"
#include "stdbool.h"
#include "stdint.h"

#include "arm_math.h"
#include "math.h"

#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"

#include "float_sincos.h"
#include "settings.h"

#include "led.h"
#include "pwm.h"
#include "adc.h"
#include "DebugUart.h"
#include "tle5012b.h"
#include "6EDL7141.h"
#include "calibration.h"




#define FP_SQRT3                        1.73205080756f
#define FP_SQRT3HALF                    0.8660254039f
#define FP_ONE_DIV_SQRT3                0.57735026919f
#define FP_TWO_DIV_SQRT3                1.15470053838f
#define FP_TWO_PI                       (2.0f * 3.14159265358979323846f)


typedef struct
{
        float32_t I;
        float32_t Kp;          /**< The proportional gain. */
        float32_t Ki;          /**< The integral gain. */
} pid_f32;



typedef enum {
    MOTOR_INIT = 0x00,
    MOTOR_CAL,
    MOTOR_OFF,
    MOTOR_TEST,
    SPEED_CTRL,
    TORQUE_CTRL,
    POSITION_CTRL,
    CRITICAL_ERROR = 0xff
} e_motor_state_t;

typedef enum {
    INIT_PWM = 0x00,
    ADC_CAL,
    ZERO_PWM,
    ENCODER_ZERO,
    CAL_END
} e_adc_cal_state_t;

typedef enum {
    SPEED_INIT_PWM = 0x00,
    SPEED_ADC_INT_EN,
    SPEED_LOOP,
    SPEED_END
} e_speed_state_t;

typedef enum {
    POS_INIT_PWM = 0x00,
    POS_ADC_INT_EN,
    POS_LOOP,
    POS_END
} e_position_state_t;

typedef enum {
    TORQUE_INIT_PWM = 0x00,
    TORQUE_ADC_INT_EN,
    TORQUE_LOOP,
    TORQUE_END
} e_torque_state_t;

typedef struct {
  // sine and cosine values of electrical angle
  float sin_phi;
  float cos_phi;
  // phase current (some might not be used)
  float i_a;
  float i_b;
  float i_c;
  int32_t adc0_i_a_offset;
  int32_t adc0_i_b_offset;
  int32_t adc0_i_c_offset;
  int32_t adc1_i_a_offset;
  int32_t adc1_i_b_offset;
  int32_t adc1_i_c_offset;
  // 2d stator current (Clarke)
  float i_alpha;
  float i_beta;
  // 2d rotor current (Park)
  float i_d;
  float i_q;
  // PID control values
  float i_d_set;
  float i_q_set;
  // PID param
  pid_f32 pid_d;
  pid_f32 pid_q;
  // PID error values
  float i_q_error;
  float i_q_error_limit;
  float i_d_error;
  float i_d_error_limit;

  float v_bus;
  // DQ frame (Inv Park)
  float v_d;
  float v_q;
  float v_limit;
  // alpha beta frame (Inv Clarke)
  float v_alpha;
  float v_beta;
  // SVPWM
  float v_pwm1;
  float v_pwm2;
  float v_pwm3;
  uint32_t sector;

  uint32_t ADC_CFG;
} stc_motor_svpwm_t;

typedef struct {
    // PWM settings
    e_calibrationMode_t calibration_mode;


} stc_settings_t;

typedef struct
{
    // PID param
    pid_f32 pid_iq;
    pid_f32 pid_id;
    //
    uint32_t pole_count;
    //
    stc_motor_svpwm_t MotorSVPWM;

    float speed_set;
    float torque_set;
    float position_set;

    float position;

    float speed_cwccw;

    e_motor_state_t MotorCtrlState;

} stc_motor_param_t;

#define PWM_PERIOD          2500

#define STEP_RESPONSE_SIZE    500
#define STEP_RESPONSE_MUL     20

stc_motor_param_t DEBUG_ARRAY[STEP_RESPONSE_SIZE];

extern stc_motor_param_t MotorParameter;
extern stc_settings_t Settings;
extern reg6EDL7141_t _6EDL7141_Register;
extern regSensor_t tle5012b_Register;




#endif /* MOTOR_CONTROL_RESOURCES_H_ */
