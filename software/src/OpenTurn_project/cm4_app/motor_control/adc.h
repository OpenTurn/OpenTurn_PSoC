/*
 * adc.h
 *
 *  Created on: 07.02.2021
 *      Author: achim
 */

#ifndef MOTOR_CONTROL_ADC_H_
#define MOTOR_CONTROL_ADC_H_

#include "resources.h"

#define ADC_CHANNEL_A_POS		0
#define ADC_CHANNEL_B_POS		1
#define ADC_CHANNEL_C_POS		2

typedef enum
{
  CH_MASK_AB,
  CH_MASK_AC,
  CH_MASK_BC,
  CH_MASK_ABC
} e_adc_ch_t;

void ADC_Init(void);
void ADC_InterruptEnable(void);
void ADC_InterruptDisable(void);
void ADC_EnableChannels(e_adc_ch_t mask);
void ADC_EnableAveraging(void);
void ADC_DisableAveraging(void);
void ADC_InjectionTrigger(void);
float ADC_GetTemperatureC(void);
float ADC_GetBusVoltage(void);


extern float phi;
extern float i_a, i_b;
extern volatile float i_c;
extern float i_d, i_q;
extern float i_d_error, i_q_error;
extern float v_d, v_q;
extern float sin_phi, cos_phi;
extern float i_alpha, i_beta;
extern float v_alpha, v_beta;
extern float v_pwm1, v_pwm2, v_pwm3;

#endif /* MOTOR_CONTROL_ADC_H_ */
