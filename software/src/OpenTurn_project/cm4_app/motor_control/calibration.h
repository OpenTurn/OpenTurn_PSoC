/*
 * calibration.h
 *
 *  Created on: 28.09.2021
 *      Author: micro
 */

#ifndef MOTOR_CONTROL_CALIBRATION_H_
#define MOTOR_CONTROL_CALIBRATION_H_

uint32_t calibration_PI_motor(void);
uint32_t calibration_PI_torque(void);
uint32_t calibration_PI_speed(void);
uint32_t calibration_PI_position(void);
uint32_t calibration_polepairs_and_direction(void);

#endif /* MOTOR_CONTROL_CALIBRATION_H_ */
