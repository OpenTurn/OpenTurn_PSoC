/*
 * float_sincos_table.h
 *
 *  Created on: 25.02.2021
 *      Author: achim
 */

#ifndef MOTOR_CONTROL_FLOAT_SINCOS_H_
#define MOTOR_CONTROL_FLOAT_SINCOS_H_

#include "resources.h"

#define SINETABLE_STEPS_PER_PERIOD              4096

void f32SinCos(uint32_t index, float *sin_val, float *cos_val);

#endif /* MOTOR_CONTROL_FLOAT_SINCOS_H_ */
