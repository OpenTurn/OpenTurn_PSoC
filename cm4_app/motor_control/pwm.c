/*
 * pwm.c
 *
 *  Created on: 23.01.2021
 *      Author: achim
 */

#include "resources.h"
#include "utils.h"

void PWM_Init(void)
{
    // PWM Init
    Cy_TCPWM_PWM_Init(PWM_A_HW, PWM_A_NUM, &PWM_A_config);
    Cy_TCPWM_PWM_Init(PWM_B_HW, PWM_B_NUM, &PWM_B_config);
    Cy_TCPWM_PWM_Init(PWM_C_HW, PWM_C_NUM, &PWM_C_config);
    Cy_TCPWM_PWM_Init(PWM_Timer_HW, PWM_Timer_NUM, &PWM_Timer_config);

    // Stop PWM on Debug
    //Cy_TCPWM_SetDebugFreeze(PWMA_HW, PWMA_NUM, true);
    //Cy_TCPWM_SetDebugFreeze(PWMB_HW, PWMB_NUM, true);
    //Cy_TCPWM_SetDebugFreeze(PWMC_HW, PWMC_NUM, true);
    //Cy_TCPWM_SetDebugFreeze(PWM_Timer_HW, PWM_Timer_NUM, true);
    //Cy_TrigMux_Connect(TRIG_IN_MUX_7_CTI_TR_OUT0, TRIG_OUT_MUX_7_TCPWM_DEBUG_FREEZE_TR_IN, false, TRIGGER_TYPE_LEVEL);

    // Enable all PWM
    Cy_TCPWM_Enable_Single(PWM_A_HW, PWM_A_NUM);
    Cy_TCPWM_Enable_Single(PWM_B_HW, PWM_B_NUM);
    Cy_TCPWM_Enable_Single(PWM_C_HW, PWM_C_NUM);
    Cy_TCPWM_Enable_Single(PWM_Timer_HW, PWM_Timer_NUM);

    // Connect TCPWM Swap Signal to constant 0 (0x00000400u), will be used for SW triggering all swap inputs simultaneous
    // This will disconnect Pin 10.0 (NC_0) from the trigger.
    Cy_TrigMux_Connect(0x00000300u, PWM_A_capture0_0_TRIGGER_OUT, false, TRIGGER_TYPE_EDGE);
    Cy_TrigMux_Connect(0x00000300u, PWM_B_capture0_0_TRIGGER_OUT, false, TRIGGER_TYPE_EDGE);
    Cy_TrigMux_Connect(0x00000300u, PWM_C_capture0_0_TRIGGER_OUT, false, TRIGGER_TYPE_EDGE);

}

void PWM_SetVectorDirect(uint8_t vector, float power)
{
  float alpha_val, beta_val;
  power = limit_F32(power, 1.0f);

  switch (vector)
  {
    case 1:
      alpha_val = power;
      beta_val = 0.0f;
      break;
    case 2:
      alpha_val = power/2.0f;
      beta_val = power * FP_SQRT3HALF;
      break;
    case 3:
      alpha_val = -power/2.0f;
      beta_val = power * FP_SQRT3HALF;
      break;
    case 4:
      alpha_val = -power;
      beta_val = 0.0f;
      break;
    case 5:
      alpha_val = -power/2.0f;
      beta_val = -power * FP_SQRT3HALF;
      break;
    case 6:
      alpha_val = power/2.0f;
      beta_val = -power * FP_SQRT3HALF;
      break;
    default:
      alpha_val = 0.0f;
      beta_val = 0.0f;
      break;
  }

  PWM_SetVector(alpha_val, beta_val);
}





uint8_t PWM_SetVector(float alpha, float beta)
{
	// inverse clarke transformation
  uint32_t psectable[]={0,2,6,1,4,3,5};
  int32_t t_v1, t_v2;
  uint32_t tmin, tmax, tvar;
  float norm;

  norm = (alpha * alpha + beta * beta);
  if(norm > 1.0f)
  {
    alpha = alpha / norm;
    beta  = beta / norm;
  }

  // swapped alpha and beta for easier SVPWM calculation and sector detection
  volatile float v_pwm1 = beta;
	volatile float beta_nhalf = beta/-2.0f;
	volatile float v_pwm2 = beta_nhalf - (FP_SQRT3HALF * alpha);
	volatile float v_pwm3 = beta_nhalf + (FP_SQRT3HALF * alpha);

	// bit order ABC --> 100 = A powered
	//
	//  B+ V3 101 ----- 001 V2
	//        / \       / \
	//       /   \  2  /   \
	//      /  3  \   /  1  \
	//     /       \ /       \
	// V4 100 ------+------- 011 V1 A+
	//     \       / \       /
	//      \  4  /   \  6  /
	//       \   /  5  \   /
	//        \ /       \ /
	//  C+ V5 110 ----- 010 V6

	uint8_t sector = 0;
	if (v_pwm1 > 0) sector += 1;
	if (v_pwm2 > 0) sector += 4;
	if (v_pwm3 > 0) sector += 2;

	// sector identification:
	// 'pseudo'sector: 1 2 3 4 5 6
	// 'real' sector:  2 6 1 4 3 5

	sector = psectable[sector];                       // lookup 'real' sector from pseudo sector

	//sector = 0;
	switch (sector) {
  case 1:                                             // 'real' sector 1, pseudo sector 3 011 to 001
      t_v1 = (v_pwm1 * PWM_PERIOD);                   // vector 1 active time
      t_v2 = (v_pwm3 * PWM_PERIOD);                   // vector 2 active time
      tmin = (PWM_PERIOD - t_v1 - t_v2) / 2;         // shortest duty cycle (last switch on)
      tvar = tmin + t_v2;                              // switching time for active vector 1->2
      tmax = tvar + t_v1;                                 // longest duty cycle (first switch on)

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_A_HW, PWM_A_NUM, tmin);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_A_HW, PWM_A_NUM, tmin);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_B_HW, PWM_B_NUM, tvar);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_B_HW, PWM_B_NUM, tvar);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_C_HW, PWM_C_NUM, tmax);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_C_HW, PWM_C_NUM, tmax);

      break;
  case 2:                                             // 'real' sector 2, pseudo sector 1 001 to 101
      t_v1 = (-v_pwm3 * PWM_PERIOD);                   // vector 1 active time
      t_v2 = (-v_pwm2 * PWM_PERIOD);                   // vector 2 active time
      tmin = (PWM_PERIOD - t_v1 - t_v2) / 2;         // shortest duty cycle (last switch on)
      tvar = tmin + t_v1;                              // switching time for active vector 1->2
      tmax = tvar + t_v2;                                 // longest duty cycle (first switch on)

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_A_HW, PWM_A_NUM, tvar);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_A_HW, PWM_A_NUM, tvar);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_B_HW, PWM_B_NUM, tmin);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_B_HW, PWM_B_NUM, tmin);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_C_HW, PWM_C_NUM, tmax);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_C_HW, PWM_C_NUM, tmax);

      break;
  case 3:                                             // 'real' sector 3, pseudo sector 5 101 to 100
      t_v1 = (v_pwm2 * PWM_PERIOD);                   // vector 1 active time
      t_v2 = (v_pwm1 * PWM_PERIOD);                   // vector 2 active time
      tmin = (PWM_PERIOD - t_v1 - t_v2) / 2;         // shortest duty cycle (last switch on)
      tvar = tmin + t_v2;                              // switching time for active vector 1->2
      tmax = tvar + t_v1;                                 // longest duty cycle (first switch on)

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_A_HW, PWM_A_NUM, tmax);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_A_HW, PWM_A_NUM, tmax);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_B_HW, PWM_B_NUM, tmin);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_B_HW, PWM_B_NUM, tmin);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_C_HW, PWM_C_NUM, tvar);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_C_HW, PWM_C_NUM, tvar);

      break;
  case 4:                                             // 'real' sector 4, pseudo sector 4 100 to 110
      t_v1 = (-v_pwm1 * PWM_PERIOD);                   // vector 1 active time
      t_v2 = (-v_pwm3 * PWM_PERIOD);                   // vector 2 active time
      tmin = (PWM_PERIOD - t_v1 - t_v2) / 2;         // shortest duty cycle (last switch on)
      tvar = tmin + t_v1;                              // switching time for active vector 1->2
      tmax = tvar + t_v2;                                 // longest duty cycle (first switch on)

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_A_HW, PWM_A_NUM, tmax);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_A_HW, PWM_A_NUM, tmax);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_B_HW, PWM_B_NUM, tvar);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_B_HW, PWM_B_NUM, tvar);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_C_HW, PWM_C_NUM, tmin);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_C_HW, PWM_C_NUM, tmin);

      break;
  case 5:                                             // 'real' sector 5, pseudo sector 6 110 to 010
      t_v1 = (v_pwm3 * PWM_PERIOD);                   // vector 1 active time
      t_v2 = (v_pwm2 * PWM_PERIOD);                   // vector 2 active time
      tmin = (PWM_PERIOD - t_v1 - t_v2) / 2;         // shortest duty cycle (last switch on)
      tvar = tmin + t_v2;                              // switching time for active vector 1->2
      tmax = tvar + t_v1;                                 // longest duty cycle (first switch on)

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_A_HW, PWM_A_NUM, tvar);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_A_HW, PWM_A_NUM, tvar);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_B_HW, PWM_B_NUM, tmax);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_B_HW, PWM_B_NUM, tmax);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_C_HW, PWM_C_NUM, tmin);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_C_HW, PWM_C_NUM, tmin);

      break;
  case 6:                                             // 'real' sector 6, pseudo sector 2 010 to 011
      t_v1 = (-v_pwm2 * PWM_PERIOD);                   // vector 1 active time
      t_v2 = (-v_pwm1 * PWM_PERIOD);                   // vector 2 active time
      tmin = (PWM_PERIOD - t_v1 - t_v2) / 2;         // shortest duty cycle (last switch on)
      tvar = tmin + t_v1;                              // switching time for active vector 1->2
      tmax = tvar + t_v2;                                 // longest duty cycle (first switch on)

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_A_HW, PWM_A_NUM, tmin);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_A_HW, PWM_A_NUM, tmin);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_B_HW, PWM_B_NUM, tmax);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_B_HW, PWM_B_NUM, tmax);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_C_HW, PWM_C_NUM, tvar);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_C_HW, PWM_C_NUM, tvar);

      break;
  default:                                         // if e.g. all values are zero
      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_A_HW, PWM_A_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_A_HW, PWM_A_NUM, 0);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_B_HW, PWM_B_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_B_HW, PWM_B_NUM, 0);

      Cy_TCPWM_PWM_SetCompare0BufVal(PWM_C_HW, PWM_C_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1BufVal(PWM_C_HW, PWM_C_NUM, 0);

      //PrintDebugAlarm(sector);

      break;
	}

	Cy_TrigMux_SwTrigger(PWM_A_capture0_0_TRIGGER_OUT, CY_TRIGGER_TWO_CYCLES);

	MotorParameter.MotorSVPWM.v_pwm1 = v_pwm1;
	MotorParameter.MotorSVPWM.v_pwm2 = v_pwm2;
	MotorParameter.MotorSVPWM.v_pwm3 = v_pwm3;
	//Cy_TCPWM_TriggerCaptureOrSwap_Single(PWM_A_HW, PWM_A_NUM);
	//Cy_TCPWM_TriggerCaptureOrSwap_Single(PWM_B_HW, PWM_B_NUM);
	//Cy_TCPWM_TriggerCaptureOrSwap_Single(PWM_C_HW, PWM_C_NUM);

	/*union {
	  float    fl;
	  uint32_t ui;
	  int32_t si;
	  uint8_t ba[4];
	} temp;

	temp.fl = tmin * 1.0f;
  PrintDebugChar(temp.ba[0]);
  PrintDebugChar(temp.ba[1]);
  PrintDebugChar(temp.ba[2]);
  PrintDebugChar(temp.ba[3]);

  temp.fl = tmax * 1.0f;
  PrintDebugChar(temp.ba[0]);
  PrintDebugChar(temp.ba[1]);
  PrintDebugChar(temp.ba[2]);
  PrintDebugChar(temp.ba[3]);

  temp.fl = tvar * 1.0f;
  PrintDebugChar(temp.ba[0]);
  PrintDebugChar(temp.ba[1]);
  PrintDebugChar(temp.ba[2]);
  PrintDebugChar(temp.ba[3]);*/

	return sector;
}

