/*
 * settings.c
 *
 *  Created on: 21.02.2021
 *      Author: achim
 */

#include "settings.h"

void settings_LoadDefault(void)
{
	memset(&MotorParameter, 0, sizeof(MotorParameter));

  MotorParameter.pid_id.Kp = 0.15f;
	MotorParameter.pid_id.Ki = 0.03f;
	MotorParameter.pid_id.I = 0.0f;

	MotorParameter.pid_iq.Kp = 0.15f;
	MotorParameter.pid_iq.Ki = 0.03f;
	MotorParameter.pid_iq.I = 0.0f;

	MotorParameter.MotorSVPWM.pid_d.Kp = 0.77f;
	MotorParameter.MotorSVPWM.pid_d.Ki = 0.001667f;
	MotorParameter.MotorSVPWM.pid_d.I = 0.0f;

	MotorParameter.MotorSVPWM.pid_q.Kp = 0.77f;
	MotorParameter.MotorSVPWM.pid_q.Ki = 0.001667f;
	MotorParameter.MotorSVPWM.pid_q.I = 0.0f;

	MotorParameter.MotorSVPWM.v_limit = 0.55f;

	MotorParameter.MotorSVPWM.v_bus = 0.0;

	MotorParameter.pole_count = 21u;
	MotorParameter.position = 0.0f;
	MotorParameter.speed_cwccw = -1.0f;

	MotorParameter.MotorSVPWM.adc0_i_a_offset = 2048;
	MotorParameter.MotorSVPWM.adc0_i_b_offset = 2048;
	MotorParameter.MotorSVPWM.adc0_i_c_offset = 2048;
	MotorParameter.MotorSVPWM.adc1_i_a_offset = 2048;
	MotorParameter.MotorSVPWM.adc1_i_b_offset = 2048;
	MotorParameter.MotorSVPWM.adc1_i_c_offset = 2048;

	MotorParameter.MotorSVPWM.sector = 0;

	MotorParameter.MotorSVPWM.ADC_CFG = CH_MASK_AB;
	ADC_EnableChannels(CH_MASK_AB);


}
