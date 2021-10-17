/*
 * encoder.h
 *
 *  Created on: 23.01.2021
 *      Author: achim
 */


#include "resources.h"
#include "6EDL7141_reg.h"

#ifndef MOTOR_CONTROL_6EDL7141_H_
#define MOTOR_CONTROL_6EDL7141_H_

#ifdef FETDRV_ENABLE_PORT
  #define IFX_6EDL7141_SetEnable       Cy_GPIO_Set(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);
  #define IFX_6EDL7141_ClrEnable       Cy_GPIO_Clr(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);
#endif
#ifdef FETDRV_BRAKE_PORT
  #define IFX_6EDL7141_SetBrake        Cy_GPIO_Set(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN);
  #define IFX_6EDL7141_ClrBrake        Cy_GPIO_Clr(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN);
#endif


e_6EDL7141_errorTypes_t   IFX_6EDL7141_Init(void);
e_6EDL7141_errorTypes_t   IFX_6EDL7141_ReadAllRegister(void);
fault_st_t                IFX_6EDL7141_ReadFaults(void);
supply_st_t               IFX_6EDL7141_ReadSupplyStatus(void);
e_6EDL7141_errorTypes_t   IFX_6EDL7141_ClearFaults(void);
e_6EDL7141_errorTypes_t   IFX_6EDL7141_ClearLatchedFaults(void);
e_6EDL7141_errorTypes_t   IFX_6EDL7141_ReadRegister(e_reg_6EDL7141_t reg, uint16_t *data);
e_6EDL7141_errorTypes_t   IFX_6EDL7141_WriteRegister(e_reg_6EDL7141_t red, uint16_t *data);

e_6EDL7141_errorTypes_t   IFX_6EDL7141_EnableCalibrationMode(void);
e_6EDL7141_errorTypes_t   IFX_6EDL7141_DisableCalibrationMode(void);

float IFX_6EDL7141_CalcPVDD(void);
float IFX_6EDL7141_CalcTemp(void);
float IFX_6EDL7141_CalcVCCLS(void);
float IFX_6EDL7141_CalcVCCHS(void);
float IFX_6EDL7141_CalcDeviceCurrent(void);
float IFX_6EDL7141_CalcDVDD(void);
float IFX_6EDL7141_CalcVDDB(void);

#endif /* MOTOR_CONTROL_6EDL7141_H_ */
