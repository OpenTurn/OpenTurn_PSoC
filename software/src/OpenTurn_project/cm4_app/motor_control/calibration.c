/*
 * calibration.c
 *
 *  Created on: 28.09.2021
 *      Author: micro
 */

#include "resources.h"

uint32_t calibration_PI_motor(void)
{
  //todo
  return 0;
}

uint32_t calibration_PI_torque(void)
{
  //todo
  return 0;
}

uint32_t calibration_PI_speed(void)
{
  //todo
  return 0;
}

uint32_t calibration_PI_position(void)
{
  //todo
  return 0;
}

uint32_t calibration_polepairs_and_direction(void)
{
  uint32_t polepairs;
  uint32_t i;
  int32_t  position;
  e_errorTypes_t ret;

  PrintDebug("\r\nStarting Motor calibration");

  PWM_SetVectorDirect(0,0.1);

  // enable FET driver
  Cy_GPIO_Set(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);
  Cy_GPIO_Set(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN);

  Cy_SysLib_Delay(250);

  PrintDebug("\r\nZero rotor position");
  // set zero position
  ret = tle5012b_SetZeroPos();
  if(ret)
  {
    PrintDebugAlarm(ret);
    return -1;
  }

  Cy_TCPWM_QuadDec_SetCounter(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM, 0x80000000);
  MotorParameter.position_set = 0.0f;
  MotorParameter.position = 0.0f;

  PrintDebug("\r\nCounting polepairs");
  polepairs = 1;
  i = 1;
  while (true) {
    PWM_SetVectorDirect(i,0.05);

    Cy_SysLib_Delay(100);

    position = 0x80000000 - (int32_t)Cy_TCPWM_QuadDec_GetCounter(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM);

    if (abs(position) > (tle5012b_GetResolution(true) * 0.95f)) {
      break;
    }

    i++;
    if (i > 6) {
      i = 1;
      polepairs++;
      PrintDebug(".");
    }
  }

  Cy_GPIO_Clr(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);
  Cy_GPIO_Clr(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN);

  PrintDebug("\r\n\r\nCalibration done:");
  PrintDebug("\r\n  - Polepairs: ");
  PrintDebugU32(polepairs);
  MotorParameter.pole_count = polepairs;
  PrintDebug("\r\n  - Direction: ");
  if (position > 0) {
    PrintDebug("cw");
    MotorParameter.speed_cwccw = 1.0f;
  } else {
    PrintDebug("ccw");
    MotorParameter.speed_cwccw = -1.0f;
  }

  return 0;
}

