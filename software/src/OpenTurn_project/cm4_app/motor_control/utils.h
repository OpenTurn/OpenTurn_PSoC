/*
 * utils.h
 *
 *  Created on: 21.02.2021
 *      Author: achim
 */

#ifndef MOTOR_CONTROL_UTILS_H_
#define MOTOR_CONTROL_UTILS_H_

#include "resources.h"

float limit_F32(float val, float limit);
int32_t limit_I32(int32_t val, int32_t limit);
uint32_t limit_U32(uint32_t val, uint32_t limit);
float facosf(float x);
float fatanf(float x);

char* ftoa(float n, int afterpoint);

void Print_MotorParamHeader(void);
void Print_MotorParam(stc_motor_param_t params);


#endif /* MOTOR_CONTROL_UTILS_H_ */
