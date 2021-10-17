/*
 * encoder.h
 *
 *  Created on: 23.01.2021
 *      Author: achim
 */


#include "resources.h"
#include "tle5012b_reg.h"

#ifndef MOTOR_CONTROL_TLE5012B_H_
#define MOTOR_CONTROL_TLE5012B_H_

e_errorTypes_t tle5012b_Init(void);
float limit_f32(float val, float limit);

void tle5012b_InitDMA(uint8_t address, uint8_t count, uint16_t *data, bool buffered, uint32_t trigger);
void tle5012b_EnableDMA(void);
void tle5012b_DisableDMA(void);
void tle5012b_SetSrcAddress(uint8_t address, uint8_t count, bool buffered);
void tle5012b_SetDesAddress(uint16_t *data);
void tle5012b_SetTrigger(uint32_t trigger);
void tle5012b_SoftTrigger(void);
uint32_t tle5012b_GetResolution(bool buffer);

e_errorTypes_t tle5012b_WriteDataArray(uint8_t address, uint8_t count, uint16_t *data, bool buffered);
e_errorTypes_t tle5012b_WriteDataOne(uint8_t address, uint16_t data, bool stats);
e_errorTypes_t tle5012b_ReadDataArray(uint8_t address, uint8_t count, uint16_t *data, bool buffered);
e_errorTypes_t tle5012b_ReadDataOne(uint8_t address, uint16_t *data, bool buffered, bool stats);

e_errorTypes_t tle5012b_UpdateAll();
e_interfaceType_t tle5012b_GetInterfaceType();
e_errorTypes_t tle5012b_SetInterfaceType(e_interfaceType_t iface);
e_errorTypes_t tle5012b_ResetFirmware();

e_errorTypes_t tle5012b_SetAutoCal(e_calibrationMode_t calMode);
e_errorTypes_t tle5012b_SetZeroPos(void);
e_errorTypes_t tle5012b_UpdateCRC(void);

#endif /* MOTOR_CONTROL_TLE5012B_H_ */
