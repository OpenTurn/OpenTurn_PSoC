/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for CM4 in the the Dual CPU Empty 
*              Application for ModusToolbox.
*
* Related Document: See README.md
*
*
*******************************************************************************
* Copyright 2020-2021, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "resources.h"
#include "utils.h"

stc_motor_param_t MotorParameter;
stc_settings_t Settings;
uint8_t     rx_buffer[256];
uint8_t     rx_BuffReadPtr = 0;
uint8_t     rx_BuffWritePtr = 0;
uint32_t    rx_fill = 0;

char temp_buffer[16];

#define CommandUartSCB              DEBUG_UART_HW

const cy_stc_sysint_t SysTick_IRQ_cfg = {
/* .intrSrc         = */ SysTick_IRQn,              /* Interrupt source is the SAR interrupt */
/* .intrPriority    = */ 4UL                        /* Interrupt priority is 4 */
};

void MotorCalibration(void)
{
    static e_adc_cal_state_t state = INIT_PWM;
    static int32_t timeout = 0;

    if(MotorParameter.MotorCtrlState != MOTOR_CAL)
    {
        state = INIT_PWM;
        return;
    }

    if (timeout != 0) {
        timeout--;
        return;
    }

    switch(state) {
        case INIT_PWM:
            // Init PWM
            Cy_TCPWM_PWM_SetCompare0Val(PWM_A_HW, PWM_A_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_A_HW, PWM_A_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_B_HW, PWM_B_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_B_HW, PWM_B_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_C_HW, PWM_C_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_C_HW, PWM_C_NUM, 0);

            IFX_6EDL7141_EnableCalibrationMode();
            Cy_GPIO_Set(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);

            timeout = 10;
            state = ADC_CAL;
            break;
        case ADC_CAL:
            // ADC Calibration
        	ADC_EnableChannels(CH_MASK_ABC);
        	ADC_EnableAveraging();

        	Cy_SAR_StartConvert(ADC0_HW, CY_SAR_START_CONVERT_SINGLE_SHOT);
        	cy_en_sar_status_t ret = Cy_SAR_IsEndConversion(ADC0_HW, CY_SAR_WAIT_FOR_RESULT);
            if (CY_SAR_SUCCESS != ret)
            {
                PrintDebugAlarm(ret);
                MotorParameter.MotorCtrlState = CRITICAL_ERROR;
                return;
            }

            int32_t result0 = Cy_SAR_GetResult32(ADC0_HW, 0);
            int32_t result1 = Cy_SAR_GetResult32(ADC0_HW, 1);
            int32_t result2 = Cy_SAR_GetResult32(ADC0_HW, 2);
            if ((result0 > 2100) || (result0 < 2000) || \
                (result1 > 2100) || (result1 < 2000) || \
				(result2 > 2100) || (result2 < 2000))
            {
                PrintDebugAlarm(result0);
                PrintDebugAlarm(result1);
                PrintDebugAlarm(result2);
                MotorParameter.MotorCtrlState = CRITICAL_ERROR;
                return;
            }

			// store result in struct
			MotorParameter.MotorSVPWM.adc0_i_a_offset = result0;
			MotorParameter.MotorSVPWM.adc0_i_b_offset = result1;
			MotorParameter.MotorSVPWM.adc0_i_c_offset = result2;



            Cy_SAR_StartConvert(ADC1_HW, CY_SAR_START_CONVERT_SINGLE_SHOT);
			ret = Cy_SAR_IsEndConversion(ADC1_HW, CY_SAR_WAIT_FOR_RESULT);
			if (CY_SAR_SUCCESS != ret)
			{
				PrintDebugAlarm(ret);
				MotorParameter.MotorCtrlState = CRITICAL_ERROR;
				return;
			}

			result0 = Cy_SAR_GetResult32(ADC0_HW, 0);
			result1 = Cy_SAR_GetResult32(ADC0_HW, 1);
			result2 = Cy_SAR_GetResult32(ADC0_HW, 2);
			if ((result0 > 2100) || (result0 < 2000) || \
				(result1 > 2100) || (result1 < 2000) || \
				(result2 > 2100) || (result2 < 2000))
			{
				PrintDebugAlarm(result0);
				PrintDebugAlarm(result1);
				PrintDebugAlarm(result2);
				MotorParameter.MotorCtrlState = CRITICAL_ERROR;
				return;
			}

            // store result in struct
			MotorParameter.MotorSVPWM.adc1_i_a_offset = result0;
			MotorParameter.MotorSVPWM.adc1_i_b_offset = result1;
			MotorParameter.MotorSVPWM.adc1_i_c_offset = result2;

			ADC_EnableChannels(CH_MASK_AB);
			ADC_DisableAveraging();

            IFX_6EDL7141_DisableCalibrationMode();
            state = ZERO_PWM;

            break;
        case ZERO_PWM:
            PWM_SetVectorDirect(1, 0.075f);

            timeout = 500;

            state = ENCODER_ZERO;
            break;
        case ENCODER_ZERO:
            // Encoder Write 0 Pos
            ret = tle5012b_SetZeroPos();

            Cy_TCPWM_QuadDec_SetCounter(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM, 0);
            MotorParameter.position_set = 0.0f;
            MotorParameter.position = 0.0f;

            if(ret)
            {
                PrintDebugAlarm(ret);
                MotorParameter.MotorCtrlState = CRITICAL_ERROR;
                return;
            }

            state = CAL_END;
            break;
        case CAL_END:
            Cy_TCPWM_PWM_SetCompare0Val(PWM_A_HW, PWM_A_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_A_HW, PWM_A_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_B_HW, PWM_B_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_B_HW, PWM_B_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_C_HW, PWM_C_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_C_HW, PWM_C_NUM, 0);

            // clean up
            Cy_GPIO_Clr(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);

            MotorParameter.MotorCtrlState = MOTOR_OFF;

            state = INIT_PWM;
            break;
        default:
            break;
    }

    return;
}

int32_t speed_buf[10] = {0};
uint8_t speed_cnt = 0;

union {
	float    fl;
	uint32_t ui;
	int32_t si;
	uint8_t ba[4];
} temp;

void MotorSpeedCtrl(void)
{
  static e_speed_state_t state = SPEED_INIT_PWM;
  static int32_t start_angle, end_angle;
  float rotor_speed;
  float speed_error;
  float speed_error_pid;
  static uint32_t timeout;

  if(MotorParameter.MotorCtrlState != SPEED_CTRL)
  {
    state = SPEED_INIT_PWM;
    return;
  }

  switch(state)
  {
    case SPEED_INIT_PWM:
      // Init PWM
      Cy_TCPWM_PWM_SetCompare0Val(PWM_A_HW, PWM_A_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1Val(PWM_A_HW, PWM_A_NUM, 0);

      Cy_TCPWM_PWM_SetCompare0Val(PWM_B_HW, PWM_B_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1Val(PWM_B_HW, PWM_B_NUM, 0);

      Cy_TCPWM_PWM_SetCompare0Val(PWM_C_HW, PWM_C_NUM, 0);
      Cy_TCPWM_PWM_SetCompare1Val(PWM_C_HW, PWM_C_NUM, 0);

      IFX_6EDL7141_DisableCalibrationMode();
      Cy_GPIO_Set(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);

      state = SPEED_ADC_INT_EN;
    break;
    case SPEED_ADC_INT_EN:

      MotorParameter.MotorSVPWM.i_d_set = 0;
      MotorParameter.MotorSVPWM.i_q_set = 0;
      MotorParameter.pid_iq.I = 0.0f;
      MotorParameter.pid_id.I = 0.0f;
      start_angle = Cy_TCPWM_QuadDec_GetCounter(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM);
      ADC_InterruptEnable();

      state = SPEED_LOOP;
    break;
    case SPEED_LOOP:

      if (timeout == 0) {
        end_angle = Cy_TCPWM_QuadDec_GetCounter(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM);

        rotor_speed = (((end_angle - start_angle) * 60000.0f) / 20.0f) / 16384.0f;

        if(MotorParameter.speed_set != 0)
        {
          speed_error = -(MotorParameter.speed_set - rotor_speed) / fabsf(MotorParameter.speed_set);
        }
        else{

        }

        // PI controller
        speed_error_pid = speed_error * MotorParameter.pid_iq.Kp + MotorParameter.pid_iq.I;
        speed_error_pid = limit_F32(speed_error_pid, 0.25f);  // todo change limit
        MotorParameter.pid_iq.I += speed_error_pid * MotorParameter.pid_iq.Ki;
        MotorParameter.pid_iq.I = limit_F32(MotorParameter.pid_iq.I, 0.25f);  // todo change limit

        MotorParameter.MotorSVPWM.i_d_set = 0;
        MotorParameter.MotorSVPWM.i_q_set = speed_error_pid * MotorParameter.speed_cwccw;

        PrintDebugChar('\r');
        PrintDebugChar('\n');
        temp.fl = rotor_speed * 1.0f; // current in percent
        PrintDebugChar(temp.ba[0]);
        PrintDebugChar(temp.ba[1]);
        PrintDebugChar(temp.ba[2]);
        PrintDebugChar(temp.ba[3]);

        temp.fl = speed_error_pid; // current in percent
        PrintDebugChar(temp.ba[0]);
        PrintDebugChar(temp.ba[1]);
        PrintDebugChar(temp.ba[2]);
        PrintDebugChar(temp.ba[3]);

        temp.fl = speed_error; // current in percent
        PrintDebugChar(temp.ba[0]);
        PrintDebugChar(temp.ba[1]);
        PrintDebugChar(temp.ba[2]);
        PrintDebugChar(temp.ba[3]);


        temp.fl = MotorParameter.MotorSVPWM.i_q_set;
        PrintDebugChar(temp.ba[0]);
        PrintDebugChar(temp.ba[1]);
        PrintDebugChar(temp.ba[2]);
        PrintDebugChar(temp.ba[3]);

        temp.fl = MotorParameter.speed_set;
        PrintDebugChar(temp.ba[0]);
        PrintDebugChar(temp.ba[1]);
        PrintDebugChar(temp.ba[2]);
        PrintDebugChar(temp.ba[3]);

        timeout = 20;
        start_angle = Cy_TCPWM_QuadDec_GetCounter(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM);
      }
      else
      {
        timeout--;
      }
    break;
    default:
    break;
  }

  return;
}

void MotorPositionCtrl(void)
{
    return;
}

void MotorTorqueCtrl(void)
{
    static e_torque_state_t state = TORQUE_INIT_PWM;
    static uint32_t timeout;

    if(MotorParameter.MotorCtrlState != TORQUE_CTRL)
    {
        state = TORQUE_INIT_PWM;
        return;
    }

    switch(state) {
        case TORQUE_INIT_PWM:
            // Init PWM
            Cy_TCPWM_PWM_SetCompare0Val(PWM_A_HW, PWM_A_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_A_HW, PWM_A_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_B_HW, PWM_B_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_B_HW, PWM_B_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_C_HW, PWM_C_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_C_HW, PWM_C_NUM, 0);

            IFX_6EDL7141_DisableCalibrationMode();
            Cy_GPIO_Set(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);

            state = TORQUE_ADC_INT_EN;
            break;
        case TORQUE_ADC_INT_EN:

          MotorParameter.MotorSVPWM.i_d_set = 0;
          MotorParameter.MotorSVPWM.i_q_set = MotorParameter.torque_set * MotorParameter.speed_cwccw;
            ADC_InterruptEnable();

            state = TORQUE_LOOP;
            break;
        case TORQUE_LOOP:

            MotorParameter.MotorSVPWM.i_d_set = 0;
            MotorParameter.MotorSVPWM.i_q_set = MotorParameter.torque_set * MotorParameter.speed_cwccw;

           /* if (timeout == 0) {
            	temp.fl = MotorParameter.MotorSVPWM.i_a;
				PrintDebugChar('\r');
				PrintDebugChar('\n');
				PrintDebugChar(temp.ba[0]);
				PrintDebugChar(temp.ba[1]);
				PrintDebugChar(temp.ba[2]);
				PrintDebugChar(temp.ba[3]);

				temp.fl = MotorParameter.MotorSVPWM.i_b;
				PrintDebugChar(temp.ba[0]);
				PrintDebugChar(temp.ba[1]);
				PrintDebugChar(temp.ba[2]);
				PrintDebugChar(temp.ba[3]);

				temp.fl = MotorParameter.MotorSVPWM.i_c;
				PrintDebugChar(temp.ba[0]);
				PrintDebugChar(temp.ba[1]);
				PrintDebugChar(temp.ba[2]);
				PrintDebugChar(temp.ba[3]);

				temp.fl = MotorParameter.MotorSVPWM.i_q;
				PrintDebugChar(temp.ba[0]);
				PrintDebugChar(temp.ba[1]);
				PrintDebugChar(temp.ba[2]);
				PrintDebugChar(temp.ba[3]);

				temp.fl = MotorParameter.MotorSVPWM.i_q_error;
				PrintDebugChar(temp.ba[0]);
				PrintDebugChar(temp.ba[1]);
				PrintDebugChar(temp.ba[2]);
				PrintDebugChar(temp.ba[3]);

                timeout = 0;
            }
            else
            {
                timeout--;
            }*/
            break;
        default:
            break;
    }

    return;
}


void Uart_Parse (void)
{
    uint32_t i;
    uint32_t j;
    uint32_t len;
    int32_t val = 0;

    len = Cy_SCB_UART_GetNumInRxFifo(CommandUartSCB);

    if (len > 0) {
        if ((len + rx_BuffWritePtr) >= 256) {
            len = 256 - rx_BuffWritePtr;
            rx_BuffWritePtr = 0;
        }

        Cy_SCB_UART_GetArray(CommandUartSCB, &rx_buffer[rx_BuffWritePtr], len);
        rx_fill += len;
        rx_BuffWritePtr += len;
    }


    j = 0;

    if (rx_BuffReadPtr != rx_BuffWritePtr) {
        i = rx_BuffReadPtr;
        switch(rx_buffer[i++]) {
            case 's':
                if (rx_fill < 4) return;
                if (rx_buffer[i++] == '=')
                {
                    for(j = 0; j < 16; j++)
                    {
                        if(rx_buffer[i] == '\n')
                        {
                            temp_buffer[j] = 0;
                            break;
                        }

                        temp_buffer[j] = rx_buffer[i];

                        if(i == rx_BuffWritePtr)
                        {
                            return;
                        }

                        i++;
                    }

                    rx_BuffReadPtr = i;

                    val = atoi(temp_buffer);

                    MotorParameter.speed_set = val;

                    MotorParameter.MotorCtrlState = SPEED_CTRL;
                    return;
                }
                else {

                }

                break;
            case 'p':
                if (rx_fill < 4) return;
                if (rx_buffer[i++] == '=')
                {
                    for(j = 0; j < 16; j++)
                    {
                        if(rx_buffer[i] == '\n')
                        {
                            temp_buffer[j] = 0;
                            break;
                        }

                        temp_buffer[j] = rx_buffer[i];

                        if(i == rx_BuffWritePtr)
                        {
                            return;
                        }

                        i++;
                    }

                    rx_BuffReadPtr = i;

                    val = atoi(temp_buffer);

                    MotorParameter.position_set = (float)(val);

                    MotorParameter.MotorCtrlState = POSITION_CTRL;
                }else {

                }
                break;
            case 't':
                if (rx_fill < 4) return;
                if (rx_buffer[i++] == '=')
                {
                    for(j = 0; j < 16; j++)
                    {
                        if(rx_buffer[i] == '\n')
                        {
                            temp_buffer[j] = 0;
                            break;
                        }

                        temp_buffer[j] = rx_buffer[i];

                        if(i == rx_BuffWritePtr)
                        {
                            return;
                        }

                        i++;
                    }

                    rx_BuffReadPtr = i;

                    val = atoi(temp_buffer);

                    val = limit_I32(val, 10000);

                    MotorParameter.torque_set = val/10000.0f;

                    MotorParameter.MotorCtrlState = TORQUE_CTRL;
                    return;
                }
                else {

                }

                break;
            case '#':
                if (rx_fill < 8) return;

                MotorParameter.MotorCtrlState = CRITICAL_ERROR;
                break;
            default:
                while (rx_buffer[rx_BuffReadPtr++] != '\n') {
                    rx_fill--;
                    if (rx_BuffReadPtr == rx_BuffWritePtr) break;
                }
                break;
        }
    }
    return;
}



void SysTick_ISR(void)
{
	static e_motor_state_t prev_state = MOTOR_INIT;
	static uint32_t timeout = 10;
	timeout--;

	//LED1_ON();

	// in case of state change, reset other state machines
	if(MotorParameter.MotorCtrlState != prev_state)
	{
		if(MotorParameter.MotorCtrlState != MOTOR_CAL)
		{
			MotorCalibration();
		}
		if(MotorParameter.MotorCtrlState != SPEED_CTRL)
		{
			MotorSpeedCtrl();
		}
		if(MotorParameter.MotorCtrlState != TORQUE_CTRL)
		{
			MotorTorqueCtrl();
		}
		if(MotorParameter.MotorCtrlState != POSITION_CTRL)
		{
			MotorPositionCtrl();
		}
	}
	prev_state = MotorParameter.MotorCtrlState;


    switch (MotorParameter.MotorCtrlState)
    {
        case MOTOR_INIT:
			MotorParameter.pid_id.I = 0.0f;
			MotorParameter.pid_iq.I = 0.0f;

            MotorParameter.MotorCtrlState = MOTOR_CAL;
            return; // dont parse uart here
        case MOTOR_CAL:
            MotorCalibration();
            return; // dont parse uart here
        case MOTOR_OFF:

            ADC_InterruptDisable();
            Cy_GPIO_Clr(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);

            MotorParameter.pid_id.I = 0.0f;
            MotorParameter.pid_iq.I = 0.0f;

            Cy_TCPWM_PWM_SetCompare0Val(PWM_A_HW, PWM_A_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_A_HW, PWM_A_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_B_HW, PWM_B_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_B_HW, PWM_B_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_C_HW, PWM_C_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_C_HW, PWM_C_NUM, 0);
            break;
        case MOTOR_TEST:
            ADC_InterruptDisable();
            Cy_GPIO_Clr(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_A_HW, PWM_A_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_A_HW, PWM_A_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_B_HW, PWM_B_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_B_HW, PWM_B_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_C_HW, PWM_C_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_C_HW, PWM_C_NUM, 0);

            Print_MotorParamHeader();

            for(int i = 0; i < STEP_RESPONSE_SIZE; i++)
            {
              Print_MotorParam(DEBUG_ARRAY[i]);
            }

            MotorParameter.MotorCtrlState = MOTOR_OFF;

            break;
        case SPEED_CTRL:
            MotorSpeedCtrl();
            break;
        case TORQUE_CTRL:
            MotorTorqueCtrl();
            break;
        case POSITION_CTRL:
            MotorPositionCtrl();

            break;
        case CRITICAL_ERROR:
            __disable_irq();

            Cy_TCPWM_PWM_SetCompare0Val(PWM_A_HW, PWM_A_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_A_HW, PWM_A_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_B_HW, PWM_B_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_B_HW, PWM_B_NUM, 0);

            Cy_TCPWM_PWM_SetCompare0Val(PWM_C_HW, PWM_C_NUM, 0);
            Cy_TCPWM_PWM_SetCompare1Val(PWM_C_HW, PWM_C_NUM, 0);

            Cy_GPIO_Clr(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);
            Cy_GPIO_Clr(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN);

            PrintDebugError(MotorParameter.MotorCtrlState);

            while(1) {
                CyDelay(250);
                LED1_TOGGLE();
            }

            break;
        default:
            PrintDebugAlarm(MotorParameter.MotorCtrlState);
            MotorParameter.MotorCtrlState = CRITICAL_ERROR;
            break;
    }
    Uart_Parse();

    //ADC_InjectionTrigger();

    //LED1_OFF();
}

int main(void)
{
	cy_rslt_t result;

  /* Initialize the device and board peripherals */
  result = cybsp_init() ;
  if (result != CY_RSLT_SUCCESS)
  {
      CY_ASSERT(0);
  }

  settings_LoadDefault();
  Settings.calibration_mode = mode1;



  Cy_SysLib_Delay(2000);

  Cy_SysTick_SetClockSource(CY_SYSTICK_CLOCK_SOURCE_CLK_CPU);
	Cy_SysTick_SetReload(100000);

	(void)Cy_SysInt_Init(&SysTick_IRQ_cfg, SysTick_ISR);
	NVIC_EnableIRQ(SysTick_IRQ_cfg.intrSrc);
  Cy_SysTick_Clear();
  Cy_SysTick_Enable();


  DebugUartInit();
  tle5012b_Init();
  IFX_6EDL7141_Init();
  PWM_Init();
  ADC_Init();
  Cy_SmartIO_Init(SMART_IO_HW, &SMART_IO_config);
  Cy_SmartIO_Enable(SMART_IO_HW);

  Cy_TCPWM_QuadDec_Init(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM, &ENCODER_QUAD1_config);
	Cy_TCPWM_QuadDec_Enable(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM);
	Cy_TCPWM_TriggerReloadOrIndex_Single(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM);


  Cy_CTB_OpampInit(OpAmp0_HW, CY_CTB_OPAMP_0, &OpAmp0_config);
  Cy_CTB_Enable(OpAmp0_HW);
  Cy_CTB_OpampInit(OpAmp1_HW, CY_CTB_OPAMP_1, &OpAmp1_config);
	Cy_CTB_Enable(OpAmp1_HW);

	// Trigger Sync Start of all PWM
	Cy_TCPWM_PWM_SetCompare0Val(PWM_A_HW, PWM_A_NUM, 0);
	Cy_TCPWM_PWM_SetCompare1Val(PWM_A_HW, PWM_A_NUM, 0);

	Cy_TCPWM_PWM_SetCompare0Val(PWM_B_HW, PWM_B_NUM, 0);
	Cy_TCPWM_PWM_SetCompare1Val(PWM_B_HW, PWM_B_NUM, 0);

	Cy_TCPWM_PWM_SetCompare0Val(PWM_C_HW, PWM_C_NUM, 0);
	Cy_TCPWM_PWM_SetCompare1Val(PWM_C_HW, PWM_C_NUM, 0);

	Cy_TCPWM_TriggerStart_Single(PWM_Timer_HW, PWM_Timer_NUM);

	ADC_InjectionTrigger();

	CyDelay(100);

	MotorParameter.MotorCtrlState = MOTOR_INIT;

	Cy_GPIO_Set(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN);

  /* Enable global interrupts */
  __enable_irq();

  CyDelay(4000);

  uint32_t elec_pos = 0;




  LED0_OFF();
  LED1_OFF();

  MotorParameter.MotorCtrlState = MOTOR_TEST;
  calibration_polepairs_and_direction();

  //ADC_EnableChannels(CH_MASK_ABC);



  //PWM_SetVector(-0.0375f, 0.075f * FP_SQRT3HALF);
  //PWM_SetVector(0.075f, 0.0f);

  //Cy_GPIO_Set(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);
  //Cy_GPIO_Set(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN);

  for (;;)
  {
    if(Cy_GPIO_Read(FETDRV_nFAULT_PORT, FETDRV_nFAULT_PIN))
    {
      LED1_ON();
    }else{
      LED1_OFF();
    }
  }

  {
    float sin_var, cos_var;
    elec_pos = (elec_pos + 1) & 0xFFF;
    f32SinCos(elec_pos, &sin_var, &cos_var);
    PWM_SetVector(cos_var * 0.075f, sin_var * 0.075f);


    PrintDebugChar('\r');
    PrintDebugChar('\n');
    temp.fl = (Cy_SAR_GetResult16(ADC0_HW, 0) - MotorParameter.MotorSVPWM.adc0_i_b_offset) * 1.0f; // current in percent
    PrintDebugChar(temp.ba[0]);
    PrintDebugChar(temp.ba[1]);
    PrintDebugChar(temp.ba[2]);
    PrintDebugChar(temp.ba[3]);

    temp.fl = (Cy_SAR_GetResult16(ADC0_HW, 1) - MotorParameter.MotorSVPWM.adc0_i_b_offset) * 1.0f; // current in percent
    PrintDebugChar(temp.ba[0]);
    PrintDebugChar(temp.ba[1]);
    PrintDebugChar(temp.ba[2]);
    PrintDebugChar(temp.ba[3]);

    temp.fl = (Cy_SAR_GetResult16(ADC0_HW, 2) - MotorParameter.MotorSVPWM.adc0_i_b_offset) * 1.0f; // current in percent
    PrintDebugChar(temp.ba[0]);
    PrintDebugChar(temp.ba[1]);
    PrintDebugChar(temp.ba[2]);
    PrintDebugChar(temp.ba[3]);

    Cy_SysLib_Delay(10);
  }
  {
  /*  float sin_var, cos_var;

    uint32_t mec_pos = Cy_TCPWM_QuadDec_GetCounter(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM);
    float position = ((mec_pos * 360) / 16384.0f);
    //todo rewrite to use pole pairs
    int32_t elec_pos = (mec_pos * SINETABLE_STEPS_PER_PERIOD) / 780;

    // park transformation
    f32SinCos(elec_pos, &sin_var, &cos_var);

    temp.fl = mec_pos * 1.0f;
    PrintDebugChar('\r');
    PrintDebugChar('\n');
    PrintDebugChar(temp.ba[0]);
    PrintDebugChar(temp.ba[1]);
    PrintDebugChar(temp.ba[2]);
    PrintDebugChar(temp.ba[3]);

    temp.fl = elec_pos * 1.0f;
    PrintDebugChar(temp.ba[0]);
    PrintDebugChar(temp.ba[1]);
    PrintDebugChar(temp.ba[2]);
    PrintDebugChar(temp.ba[3]);

    temp.fl = position;
    PrintDebugChar(temp.ba[0]);
    PrintDebugChar(temp.ba[1]);
    PrintDebugChar(temp.ba[2]);
    PrintDebugChar(temp.ba[3]);

    temp.fl = sin_var * 100.0f;
    PrintDebugChar(temp.ba[0]);
    PrintDebugChar(temp.ba[1]);
    PrintDebugChar(temp.ba[2]);
    PrintDebugChar(temp.ba[3]);

    temp.fl = cos_var * 100.0f;
    PrintDebugChar(temp.ba[0]);
    PrintDebugChar(temp.ba[1]);
    PrintDebugChar(temp.ba[2]);
    PrintDebugChar(temp.ba[3]);

    Cy_SysLib_Delay(1);
  }
  {*/


      // enable FET driver
      Cy_GPIO_Set(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN);
      Cy_GPIO_Set(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN);
      float sin_var, cos_var;

      ADC_InjectionTrigger();



      elec_pos = (elec_pos + 1) & 0xFFF;
      f32SinCos(elec_pos, &sin_var, &cos_var);
      PWM_SetVector(cos_var * 0.075f, sin_var * 0.075f);


      Cy_SysLib_DelayUs(100);

      uint32_t mec_pos = Cy_TCPWM_QuadDec_GetCounter(ENCODER_QUAD1_HW, ENCODER_QUAD1_NUM);
      temp.fl = ((mec_pos * 360) / 16384.0f);
      temp.fl = fmod(temp.fl, 360.0f);
      PrintDebugChar('\r');
      PrintDebugChar('\n');
      PrintDebugChar(temp.ba[0]);
      PrintDebugChar(temp.ba[1]);
      PrintDebugChar(temp.ba[2]);
      PrintDebugChar(temp.ba[3]);

      //todo rewrite to use pole pairs
      temp.fl = ((mec_pos * 21 * 4096) / 16384.0f);
      temp.fl = fmod(temp.fl, 4096.0f);
      PrintDebugChar(temp.ba[0]);
      PrintDebugChar(temp.ba[1]);
      PrintDebugChar(temp.ba[2]);
      PrintDebugChar(temp.ba[3]);

      temp.fl = elec_pos * 1.0f;
      PrintDebugChar(temp.ba[0]);
      PrintDebugChar(temp.ba[1]);
      PrintDebugChar(temp.ba[2]);
      PrintDebugChar(temp.ba[3]);

      temp.fl = sin_var * 100.0f;
      PrintDebugChar(temp.ba[0]);
      PrintDebugChar(temp.ba[1]);
      PrintDebugChar(temp.ba[2]);
      PrintDebugChar(temp.ba[3]);

      temp.fl = cos_var * 100.0f;
      PrintDebugChar(temp.ba[0]);
      PrintDebugChar(temp.ba[1]);
      PrintDebugChar(temp.ba[2]);
      PrintDebugChar(temp.ba[3]);

      temp.fl = (Cy_SAR_GetResult32(ADC0_HW, 0) - MotorParameter.MotorSVPWM.adc0_i_a_offset + Cy_SAR_GetResult32(ADC1_HW, 0) - MotorParameter.MotorSVPWM.adc1_i_a_offset) / 2.0f;
      PrintDebugChar(temp.ba[0]);
      PrintDebugChar(temp.ba[1]);
      PrintDebugChar(temp.ba[2]);
      PrintDebugChar(temp.ba[3]);

      temp.fl = (Cy_SAR_GetResult32(ADC0_HW, 1) - MotorParameter.MotorSVPWM.adc0_i_b_offset + Cy_SAR_GetResult32(ADC1_HW, 1) - MotorParameter.MotorSVPWM.adc1_i_b_offset) / 2.0f;
      PrintDebugChar(temp.ba[0]);
      PrintDebugChar(temp.ba[1]);
      PrintDebugChar(temp.ba[2]);
      PrintDebugChar(temp.ba[3]);

      temp.fl = (Cy_SAR_GetResult32(ADC0_HW, 2) - MotorParameter.MotorSVPWM.adc0_i_c_offset + Cy_SAR_GetResult32(ADC1_HW, 2) - MotorParameter.MotorSVPWM.adc1_i_c_offset) / 2.0f;
      PrintDebugChar(temp.ba[0]);
      PrintDebugChar(temp.ba[1]);
      PrintDebugChar(temp.ba[2]);
      PrintDebugChar(temp.ba[3]);

      temp.fl = ADC_GetTemperatureC();
      PrintDebugChar(temp.ba[0]);
      PrintDebugChar(temp.ba[1]);
      PrintDebugChar(temp.ba[2]);
      PrintDebugChar(temp.ba[3]);

      temp.fl = IFX_6EDL7141_CalcTemp();
      PrintDebugChar(temp.ba[0]);
      PrintDebugChar(temp.ba[1]);
      PrintDebugChar(temp.ba[2]);
      PrintDebugChar(temp.ba[3]);



      Cy_SysLib_DelayUs(100);
  }
}

/* [] END OF FILE */
