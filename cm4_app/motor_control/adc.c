/*
 * adc.c
 *
 *  Created on: 07.02.2021
 *      Author: achim
 */

#include "adc.h"
#include "utils.h"

const uint32_t psectable[]={0,2,6,1,4,3,5};


/* ISR function to handle all SAR interrupts.
 * This same routine gets called when any of the enabled SAR interrupt sources
 * are enabled (EOS, overflow, FW collision, saturation detection, or range detection). */
//todo  __attribute__((section( .ramfunc )))
void SAR0_Interrupt(void)
{

  //  V\     |beta
  //    \    |
  //     \   |
  //      \  |
  //       \ |
  //        \|_________________ U
  //        /                   alpha
  //       /
  //      /
  //     /
  //    /
  //  W/

  stc_motor_param_t *motor_param_ptr;
  stc_motor_svpwm_t *svpwm_ptr;
  uint32_t intr_status = 0u;
  uint32_t intr_range_status = 0u;
  static uint32_t timeout = STEP_RESPONSE_SIZE * STEP_RESPONSE_MUL;

  intr_status = Cy_SAR_GetInterruptStatus(ADC0_HW);
  intr_range_status = SAR_RANGE_INTR(ADC0_HW);
  Cy_SAR_ClearInterrupt(ADC0_HW, CY_SAR_INTR);
  SAR_RANGE_INTR(ADC0_HW) = intr_range_status;

  motor_param_ptr = &MotorParameter;
  svpwm_ptr = &MotorParameter.MotorSVPWM;

  if((SPEED_CTRL == motor_param_ptr->MotorCtrlState) || (POSITION_CTRL == motor_param_ptr->MotorCtrlState) || (TORQUE_CTRL == motor_param_ptr->MotorCtrlState))
  {
    if(0x00000003 & intr_range_status)
    {
      //Disable PWM
      Cy_TCPWM_PWM_SetCompare0Val(PWM_A_HW, PWM_A_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1Val(PWM_A_HW, PWM_A_NUM, 0);

      Cy_TCPWM_PWM_SetCompare0Val(PWM_B_HW, PWM_B_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1Val(PWM_B_HW, PWM_B_NUM, 0);

      Cy_TCPWM_PWM_SetCompare0Val(PWM_C_HW, PWM_C_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1Val(PWM_C_HW, PWM_C_NUM, 0);

      //Disable FET driver
      Cy_GPIO_Clr(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);
      Cy_GPIO_Clr(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN);

      SAR_RANGE_INTR(ADC0_HW) = intr_range_status;
      PrintDebugAlarm(intr_range_status);

      PrintDebug("#");
      PrintDebugStrH16("\r\nA: ", Cy_SAR_GetResult16(ADC0_HW, 0));
      PrintDebugStrH16("\r\nB: ", Cy_SAR_GetResult16(ADC0_HW, 1));
      PrintDebugStrH16("\r\nC: ", Cy_SAR_GetResult16(ADC0_HW, 2));
      motor_param_ptr->MotorCtrlState = CRITICAL_ERROR;

      return;
    }

    //todo remove
    LED0_ON();


    if ((intr_status & (uint32_t) CY_SAR_INTR_EOS) == (uint32_t) CY_SAR_INTR_EOS)
    {
      // get phase currents
      switch(svpwm_ptr->ADC_CFG)
      {
        case CH_MASK_AB:
          svpwm_ptr->i_a = (Cy_SAR_GetResult16(ADC0_HW, 0) - MotorParameter.MotorSVPWM.adc0_i_a_offset) / 2048.0f; // current in percent
          svpwm_ptr->i_b = (Cy_SAR_GetResult16(ADC1_HW, 1) - MotorParameter.MotorSVPWM.adc1_i_b_offset) / 2048.0f; // current in percent
          svpwm_ptr->i_c = -(svpwm_ptr->i_a + svpwm_ptr->i_b);
        break;
        case CH_MASK_AC:
          svpwm_ptr->i_a = (Cy_SAR_GetResult16(ADC0_HW, 0) - MotorParameter.MotorSVPWM.adc0_i_a_offset) / 2048.0f; // current in percent
          svpwm_ptr->i_c = (Cy_SAR_GetResult16(ADC1_HW, 2) - MotorParameter.MotorSVPWM.adc1_i_c_offset) / 2048.0f; // current in percent
          svpwm_ptr->i_b = -(svpwm_ptr->i_a + svpwm_ptr->i_c);
        break;
        case CH_MASK_BC:
          svpwm_ptr->i_b = (Cy_SAR_GetResult16(ADC0_HW, 1) - MotorParameter.MotorSVPWM.adc0_i_b_offset) / 2048.0f; // current in percent
          svpwm_ptr->i_c = (Cy_SAR_GetResult16(ADC1_HW, 2) - MotorParameter.MotorSVPWM.adc1_i_c_offset) / 2048.0f; // current in percent
          svpwm_ptr->i_a = -(svpwm_ptr->i_b + svpwm_ptr->i_c);
        break;
        case CH_MASK_ABC:
        default:
          //Disable PWM
          Cy_TCPWM_PWM_SetCompare0Val(PWM_A_HW, PWM_A_NUM, 0);
          Cy_TCPWM_PWM_SetCompare1Val(PWM_A_HW, PWM_A_NUM, 0);

          Cy_TCPWM_PWM_SetCompare0Val(PWM_B_HW, PWM_B_NUM, 0);
          Cy_TCPWM_PWM_SetCompare1Val(PWM_B_HW, PWM_B_NUM, 0);

          Cy_TCPWM_PWM_SetCompare0Val(PWM_C_HW, PWM_C_NUM, 0);
          Cy_TCPWM_PWM_SetCompare1Val(PWM_C_HW, PWM_C_NUM, 0);

          //Disable FET driver
          Cy_GPIO_Clr(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);
          Cy_GPIO_Clr(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN);

          SAR_RANGE_INTR(ADC0_HW) = intr_range_status;
          PrintDebugAlarm(intr_range_status);
          motor_param_ptr->MotorCtrlState = CRITICAL_ERROR;
          return;
        break;
      }

      // clarke transformation
      svpwm_ptr->i_alpha = svpwm_ptr->i_a;
      svpwm_ptr->i_beta = FP_ONE_DIV_SQRT3 * (svpwm_ptr->i_b - svpwm_ptr->i_c);


      // get mechanical position
      //uint32_t mec_pos = Cy_TCPWM_QuadDec_GetCounter(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM);
      uint32_t mec_pos = Cy_TCPWM_QuadDec_GetCapture0Val(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM) & 0x3FFF;
      motor_param_ptr->position = ((mec_pos * 360) / 16384.0f);
      //todo rewrite to use pole pairs
      uint32_t elec_pos = (mec_pos * SINETABLE_STEPS_PER_PERIOD) / 780;

      // park transformation
      f32SinCos(elec_pos, &svpwm_ptr->sin_phi, &svpwm_ptr->cos_phi);
      svpwm_ptr->i_d = (svpwm_ptr->i_alpha * svpwm_ptr->cos_phi) + (svpwm_ptr->i_beta * svpwm_ptr->sin_phi);
      svpwm_ptr->i_q = (svpwm_ptr->i_beta * svpwm_ptr->cos_phi) - (svpwm_ptr->i_alpha * svpwm_ptr->sin_phi);

      // ERROR CALC
      svpwm_ptr->i_d_error = svpwm_ptr->i_d_set - svpwm_ptr->i_d;
      svpwm_ptr->i_q_error = svpwm_ptr->i_q_set - svpwm_ptr->i_q;


      // PI D
      svpwm_ptr->v_d = svpwm_ptr->i_d_error * svpwm_ptr->pid_d.Kp + svpwm_ptr->pid_d.I;
      svpwm_ptr->v_d = limit_F32(svpwm_ptr->v_d, svpwm_ptr->v_limit);
      svpwm_ptr->pid_d.I += svpwm_ptr->i_q_error * svpwm_ptr->pid_d.Ki;
      svpwm_ptr->pid_d.I = limit_F32(svpwm_ptr->pid_d.I, svpwm_ptr->v_limit);


      // PI Q
      svpwm_ptr->v_q = svpwm_ptr->i_q_error * svpwm_ptr->pid_q.Kp + svpwm_ptr->pid_q.I;
      //svpwm_ptr->v_q = limit_F32(svpwm_ptr->v_q, svpwm_ptr->v_limit - fabsf(svpwm_ptr->v_d));
      svpwm_ptr->v_q = limit_F32(svpwm_ptr->v_q, svpwm_ptr->v_limit);
      svpwm_ptr->pid_q.I += svpwm_ptr->i_q_error * svpwm_ptr->pid_q.Ki;
      svpwm_ptr->pid_q.I = limit_F32(svpwm_ptr->pid_q.I, svpwm_ptr->v_limit);

      // inverse Park transformation
      svpwm_ptr->v_alpha = (svpwm_ptr->v_d * svpwm_ptr->cos_phi) - (svpwm_ptr->v_q * svpwm_ptr->sin_phi);
      svpwm_ptr->v_beta  = (svpwm_ptr->v_d * svpwm_ptr->sin_phi) + (svpwm_ptr->v_q * svpwm_ptr->cos_phi);

      PWM_SetVector(svpwm_ptr->v_alpha, svpwm_ptr->v_beta);

      if((timeout & (STEP_RESPONSE_MUL - 1)) == 0)
      {
        memcpy(&DEBUG_ARRAY[STEP_RESPONSE_SIZE - (timeout / STEP_RESPONSE_MUL)], &MotorParameter, sizeof(MotorParameter));
      }

      if(timeout > 0)
      {
        timeout--;
      }else{
        timeout = STEP_RESPONSE_SIZE * STEP_RESPONSE_MUL;
        svpwm_ptr->i_d_set = 0.0f;
        svpwm_ptr->i_q_set = 0.0f;
        svpwm_ptr->pid_d.I = 0.0f;
        svpwm_ptr->pid_q.I = 0.0f;
        motor_param_ptr->MotorCtrlState = MOTOR_TEST;
      }
    }
  }

  LED0_OFF();

  return;
}


void SAR1_Interrupt(void)
{
  uint32_t intr_range_status = 0u;

  intr_range_status = SAR_RANGE_INTR(ADC1_HW);
  SAR_RANGE_INTR(ADC1_HW) = intr_range_status;
  Cy_SAR_ClearInterrupt(ADC1_HW, CY_SAR_INTR);

  if((SPEED_CTRL == MotorParameter.MotorCtrlState) || (POSITION_CTRL == MotorParameter.MotorCtrlState) || (TORQUE_CTRL == MotorParameter.MotorCtrlState))
  {
    if(0x00000003 & intr_range_status)
    {
      //Disable PWM
      Cy_TCPWM_PWM_SetCompare0Val(PWM_A_HW, PWM_A_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1Val(PWM_A_HW, PWM_A_NUM, 0);

      Cy_TCPWM_PWM_SetCompare0Val(PWM_B_HW, PWM_B_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1Val(PWM_B_HW, PWM_B_NUM, 0);

      Cy_TCPWM_PWM_SetCompare0Val(PWM_C_HW, PWM_C_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1Val(PWM_C_HW, PWM_C_NUM, 0);

      //Disable FET driver
      Cy_GPIO_Clr(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);
      Cy_GPIO_Clr(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN);


      SAR_RANGE_INTR(ADC1_HW) = intr_range_status;
      PrintDebugAlarm(intr_range_status);
      PrintDebug("#");
      PrintDebugStrH16("\r\nA: ", Cy_SAR_GetResult16(ADC1_HW, 0));
      PrintDebugStrH16("\r\nB: ", Cy_SAR_GetResult16(ADC1_HW, 1));
      PrintDebugStrH16("\r\nC: ", Cy_SAR_GetResult16(ADC1_HW, 2));

      MotorParameter.MotorCtrlState = CRITICAL_ERROR;
    }
  }

  return;
}

const cy_stc_sysint_t ADC0_IRQ_cfg = {
  /* .intrSrc         = */ pass_interrupt_sar_0_IRQn,   /* Interrupt source is the SAR interrupt */
  /* .intrPriority    = */ 3UL                        /* Interrupt priority is 3 */
};

const cy_stc_sysint_t ADC1_IRQ_cfg = {
  /* .intrSrc         = */ pass_interrupt_sar_1_IRQn,   /* Interrupt source is the SAR interrupt */
  /* .intrPriority    = */ 3UL                        /* Interrupt priority is 3 */
};

void ADC_Init(void)
{
  // ADC Init
  Cy_SysAnalog_Init(&AREF_config);
  Cy_SysAnalog_Enable();

  Cy_SAR_Init(ADC0_HW, &ADC0_config);
  Cy_SAR_Init(ADC1_HW, &ADC1_config);
  Cy_SAR_CommonInit(PASS, &ADC_config);

  // ADC Enable
  Cy_SAR_Enable(ADC0_HW);
  Cy_SAR_Enable(ADC1_HW);

  Cy_SAR_ClearInterrupt(ADC0_HW, CY_SAR_INTR);
  Cy_SAR_ClearInterrupt(ADC1_HW, CY_SAR_INTR);

  (void)Cy_SysInt_Init(&ADC0_IRQ_cfg, SAR0_Interrupt);
  (void)Cy_SysInt_Init(&ADC1_IRQ_cfg, SAR1_Interrupt);

  return;
}

void ADC_InterruptEnable(void)
{
  uint32_t intr0_range_status = 0u;
  uint32_t intr1_range_status = 0u;

  Cy_SAR_ClearInterrupt(ADC0_HW, CY_SAR_INTR);
  Cy_SAR_ClearInterrupt(ADC1_HW, CY_SAR_INTR);

  intr0_range_status = SAR_RANGE_INTR(ADC0_HW);
  intr1_range_status = SAR_RANGE_INTR(ADC1_HW);

  SAR_RANGE_INTR(ADC0_HW) = intr0_range_status;
  SAR_RANGE_INTR(ADC1_HW) = intr1_range_status;

  NVIC_EnableIRQ(ADC0_IRQ_cfg.intrSrc);
  NVIC_EnableIRQ(ADC1_IRQ_cfg.intrSrc);

  return;
}

void ADC_InterruptDisable(void)
{
  NVIC_DisableIRQ(ADC0_IRQ_cfg.intrSrc);
  NVIC_DisableIRQ(ADC1_IRQ_cfg.intrSrc);

  return;
}

void ADC_InjectionTrigger(void)
{
	Cy_SAR_EnableInjection(ADC0_HW, true);
	Cy_SAR_EnableInjection(ADC1_HW, true);
}


void ADC_EnableChannels(e_adc_ch_t mask)
{
	switch(mask)
	{
		case CH_MASK_AB:
			Cy_SAR_SetChanMask(ADC0_HW, (1 << ADC_CHANNEL_A_POS));
			Cy_SAR_SetChanMask(ADC1_HW, (1 << ADC_CHANNEL_B_POS));
			MotorParameter.MotorSVPWM.ADC_CFG = CH_MASK_AB;
    break;
		case CH_MASK_AC:
			Cy_SAR_SetChanMask(ADC0_HW, (1 << ADC_CHANNEL_A_POS));
			Cy_SAR_SetChanMask(ADC1_HW, (1 << ADC_CHANNEL_C_POS));
			MotorParameter.MotorSVPWM.ADC_CFG = CH_MASK_AC;
    break;
		case CH_MASK_BC:
			Cy_SAR_SetChanMask(ADC0_HW, (1 << ADC_CHANNEL_B_POS));
			Cy_SAR_SetChanMask(ADC1_HW, (1 << ADC_CHANNEL_C_POS));
			MotorParameter.MotorSVPWM.ADC_CFG = CH_MASK_BC;
    break;
		case CH_MASK_ABC:
			Cy_SAR_SetChanMask(ADC0_HW, (1 << ADC_CHANNEL_A_POS) | (1 << ADC_CHANNEL_B_POS) | (1 << ADC_CHANNEL_C_POS));
			Cy_SAR_SetChanMask(ADC1_HW, (1 << ADC_CHANNEL_A_POS) | (1 << ADC_CHANNEL_B_POS) | (1 << ADC_CHANNEL_C_POS));
			MotorParameter.MotorSVPWM.ADC_CFG = CH_MASK_ABC;
    break;
	}

	return;
}

inline void ADC_EnableAveraging(void)
{
	SAR_CHAN_CONFIG(ADC0_HW, 0) |= (SAR_V2_CHAN_CONFIG_AVG_EN_Msk);
	SAR_CHAN_CONFIG(ADC0_HW, 1) |= (SAR_V2_CHAN_CONFIG_AVG_EN_Msk);
	SAR_CHAN_CONFIG(ADC0_HW, 2) |= (SAR_V2_CHAN_CONFIG_AVG_EN_Msk);

	SAR_CHAN_CONFIG(ADC1_HW, 0) |= (SAR_V2_CHAN_CONFIG_AVG_EN_Msk);
	SAR_CHAN_CONFIG(ADC1_HW, 1) |= (SAR_V2_CHAN_CONFIG_AVG_EN_Msk);
	SAR_CHAN_CONFIG(ADC1_HW, 2) |= (SAR_V2_CHAN_CONFIG_AVG_EN_Msk);

	return;
}

inline void ADC_DisableAveraging(void)
{
	SAR_CHAN_CONFIG(ADC0_HW, 0) &= ~(SAR_V2_CHAN_CONFIG_AVG_EN_Msk);
	SAR_CHAN_CONFIG(ADC0_HW, 1) &= ~(SAR_V2_CHAN_CONFIG_AVG_EN_Msk);
	SAR_CHAN_CONFIG(ADC0_HW, 2) &= ~(SAR_V2_CHAN_CONFIG_AVG_EN_Msk);

	SAR_CHAN_CONFIG(ADC1_HW, 0) &= ~(SAR_V2_CHAN_CONFIG_AVG_EN_Msk);
	SAR_CHAN_CONFIG(ADC1_HW, 1) &= ~(SAR_V2_CHAN_CONFIG_AVG_EN_Msk);
	SAR_CHAN_CONFIG(ADC1_HW, 2) &= ~(SAR_V2_CHAN_CONFIG_AVG_EN_Msk);

	return;
}


float ADC_GetTemperatureC(void)
{
	float result = Cy_SAR_GetResult16(ADC1_HW, CY_SAR_INJ_CHANNEL);

	result = (result - 620.0f) / 12.3f;

	return result;
}

float ADC_GetBusVoltage(void)
{
	float result = Cy_SAR_GetResult32(ADC0_HW, CY_SAR_INJ_CHANNEL);

	result = result / 4096.0f * (51.0f + 3.3f);

	return result;
}
