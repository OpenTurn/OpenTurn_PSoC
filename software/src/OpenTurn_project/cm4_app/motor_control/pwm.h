/*
 * pwm.h
 *
 *  Created on: 23.01.2021
 *      Author: achim
 */

#ifndef MOTOR_CONTROL_PWM_H_
#define MOTOR_CONTROL_PWM_H_

void PWM_Init(void);
void PWM_SetVectorDirect(uint8_t vector, float power);
uint8_t PWM_SetVector(float alpha, float beta);


#endif /* MOTOR_CONTROL_PWM_H_ */
