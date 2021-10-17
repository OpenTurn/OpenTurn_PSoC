/*******************************************************************************
* File Name: cycfg_peripherals.h
*
* Description:
* Peripheral Hardware Block configuration
* This file was automatically generated and should not be modified.
* Tools Package 2.3.0.4276
* mtb-pdl-cat1 2.2.1.9614
* personalities 4.0.0.0
* udd 3.0.0.1125
*
********************************************************************************
* Copyright 2021 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
********************************************************************************/

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_canfd.h"
#include "cy_sysclk.h"
#if defined (CY_USING_HAL)
	#include "cyhal_hwmgr.h"
#endif //defined (CY_USING_HAL)
#include "cy_csd.h"
#include "cy_sysanalog.h"
#include "cy_ctb.h"
#include "cy_sar.h"
#include "cycfg_routing.h"
#include "cy_scb_spi.h"
#include "cy_scb_uart.h"
#include "cy_mcwdt.h"
#include "cy_tcpwm_quaddec.h"
#include "cy_tcpwm_pwm.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define CANFD_ENABLED 1U
#define CANFD_HW CANFD0
#define CANFD_CHANNEL CANFD0_CH0
#define CANFD_STD_ID_FILTER_ID_0 0
#define CANFD_EXT_ID_FILTER_ID_0 0
#define CANFD_DATA_0 0
#define CANFD_DATA_1 1
#define CANFD_DATA_2 2
#define CANFD_DATA_3 3
#define CANFD_DATA_4 4
#define CANFD_DATA_5 5
#define CANFD_DATA_6 6
#define CANFD_DATA_7 7
#define CANFD_DATA_8 8
#define CANFD_DATA_9 9
#define CANFD_DATA_10 10
#define CANFD_DATA_11 11
#define CANFD_DATA_12 12
#define CANFD_DATA_13 13
#define CANFD_DATA_14 14
#define CANFD_DATA_15 15
#define CANFD_IRQ_0 canfd_0_interrupts0_0_IRQn
#define CANFD_IRQ_1 canfd_0_interrupts1_0_IRQn
#define VREF_ENABLED 1U
#define CY_CAPSENSE_CORE 4u
#define CY_CAPSENSE_CPU_CLK 100000000u
#define CY_CAPSENSE_PERI_CLK 100000000u
#define CY_CAPSENSE_VDDA_MV 3300u
#define CY_CAPSENSE_PERI_DIV_TYPE CY_SYSCLK_DIV_16_BIT
#define CY_CAPSENSE_PERI_DIV_INDEX 4u
#define VREF_HW CSD0
#define VREF_IRQ csd_interrupt_IRQn
#define PASS_ENABLED 1U
#define AREF_ENABLED 1U
#define OpAmp0_ENABLED 1U
#define OpAmp0_HW CTBM0
#define OpAmp1_ENABLED 1U
#define OpAmp1_HW CTBM0
#define pass_0_ctbmclk_0_ENABLED 1U
#define ADC_ENABLED 1U
#define ADC0_ENABLED 1U
#define ADC0_HW SAR0
#define ADC0_IRQ pass_interrupt_sar_IRQn
#define ADC0_CTL ((uint32_t)CY_SAR_VREF_PWR_100 | (uint32_t)CY_SAR_VREF_SEL_VDDA_DIV_2 | (uint32_t)CY_SAR_BYPASS_CAP_ENABLE | (uint32_t)CY_SAR_NEG_SEL_VREF | (uint32_t)CY_SAR_CTRL_NEGVREF_HW | (uint32_t)CY_SAR_CTRL_COMP_DLY_12 | (uint32_t)CY_SAR_COMP_PWR_100 | (uint32_t)CY_SAR_DEEPSLEEP_SARMUX_OFF | (uint32_t)CY_SAR_SARSEQ_SWITCH_ENABLE)
#define ADC0_SAMPLE ((uint32_t)SAR_SAMPLE_CTRL_EOS_DSI_OUT_EN_Msk | (uint32_t)CY_SAR_RIGHT_ALIGN | (uint32_t)CY_SAR_DIFFERENTIAL_UNSIGNED | (uint32_t)CY_SAR_SINGLE_ENDED_UNSIGNED | (uint32_t)CY_SAR_AVG_CNT_16 | (uint32_t)CY_SAR_AVG_MODE_SEQUENTIAL_FIXED | (uint32_t)CY_SAR_TRIGGER_MODE_FW_AND_HWEDGE)
#define ADC0_CH0_CONFIG (((uint32_t)SAR0_VPLUS0_PORT << SAR_CHAN_CONFIG_POS_PORT_ADDR_Pos) | (uint32_t)(SAR0_VPLUS0_PIN << SAR_CHAN_CONFIG_POS_PIN_ADDR_Pos) | CY_SAR_CHAN_SINGLE_ENDED | CY_SAR_CHAN_AVG_DISABLE | (uint32_t)CY_SAR_CHAN_SAMPLE_TIME_0)
#define ADC0_CH1_CONFIG (((uint32_t)SAR0_VPLUS1_PORT << SAR_CHAN_CONFIG_POS_PORT_ADDR_Pos) | (uint32_t)(SAR0_VPLUS1_PIN << SAR_CHAN_CONFIG_POS_PIN_ADDR_Pos) | CY_SAR_CHAN_SINGLE_ENDED | CY_SAR_CHAN_AVG_DISABLE | (uint32_t)CY_SAR_CHAN_SAMPLE_TIME_0)
#define ADC0_CH2_CONFIG (((uint32_t)SAR0_VPLUS2_PORT << SAR_CHAN_CONFIG_POS_PORT_ADDR_Pos) | (uint32_t)(SAR0_VPLUS2_PIN << SAR_CHAN_CONFIG_POS_PIN_ADDR_Pos) | CY_SAR_CHAN_SINGLE_ENDED | CY_SAR_CHAN_AVG_DISABLE | (uint32_t)CY_SAR_CHAN_SAMPLE_TIME_0)
#define ADC0_INJ_CONFIG (((uint32_t)SAR0_INJ_VPLUS_PORT << SAR_INJ_CHAN_CONFIG_INJ_PORT_ADDR_Pos) | (uint32_t)(SAR0_INJ_VPLUS_PIN << SAR_INJ_CHAN_CONFIG_INJ_PIN_ADDR_Pos) | CY_SAR_CHAN_SINGLE_ENDED | CY_SAR_CHAN_AVG_DISABLE | (uint32_t)CY_SAR_CHAN_SAMPLE_TIME_0)
#define ADC0_VREF_MV 1650UL
#define ADC1_ENABLED 1U
#define ADC1_HW SAR1
#define ADC1_IRQ pass_interrupt_sar_IRQn
#define ADC1_CTL ((uint32_t)CY_SAR_VREF_PWR_100 | (uint32_t)CY_SAR_VREF_SEL_VDDA_DIV_2 | (uint32_t)CY_SAR_BYPASS_CAP_ENABLE | (uint32_t)CY_SAR_NEG_SEL_VREF | (uint32_t)CY_SAR_CTRL_NEGVREF_HW | (uint32_t)CY_SAR_CTRL_COMP_DLY_12 | (uint32_t)CY_SAR_COMP_PWR_100 | (uint32_t)CY_SAR_DEEPSLEEP_SARMUX_OFF | (uint32_t)CY_SAR_SARSEQ_SWITCH_ENABLE)
#define ADC1_SAMPLE ((uint32_t)SAR_SAMPLE_CTRL_EOS_DSI_OUT_EN_Msk | (uint32_t)CY_SAR_RIGHT_ALIGN | (uint32_t)CY_SAR_DIFFERENTIAL_UNSIGNED | (uint32_t)CY_SAR_SINGLE_ENDED_UNSIGNED | (uint32_t)CY_SAR_AVG_CNT_16 | (uint32_t)CY_SAR_AVG_MODE_SEQUENTIAL_FIXED | (uint32_t)CY_SAR_TRIGGER_MODE_FW_ONLY)
#define ADC1_CH0_CONFIG (((uint32_t)SAR1_VPLUS0_PORT << SAR_CHAN_CONFIG_POS_PORT_ADDR_Pos) | (uint32_t)(SAR1_VPLUS0_PIN << SAR_CHAN_CONFIG_POS_PIN_ADDR_Pos) | CY_SAR_CHAN_SINGLE_ENDED | CY_SAR_CHAN_AVG_DISABLE | (uint32_t)CY_SAR_CHAN_SAMPLE_TIME_0)
#define ADC1_CH1_CONFIG (((uint32_t)SAR1_VPLUS1_PORT << SAR_CHAN_CONFIG_POS_PORT_ADDR_Pos) | (uint32_t)(SAR1_VPLUS1_PIN << SAR_CHAN_CONFIG_POS_PIN_ADDR_Pos) | CY_SAR_CHAN_SINGLE_ENDED | CY_SAR_CHAN_AVG_DISABLE | (uint32_t)CY_SAR_CHAN_SAMPLE_TIME_1)
#define ADC1_CH2_CONFIG (((uint32_t)SAR1_VPLUS2_PORT << SAR_CHAN_CONFIG_POS_PORT_ADDR_Pos) | (uint32_t)(SAR1_VPLUS2_PIN << SAR_CHAN_CONFIG_POS_PIN_ADDR_Pos) | CY_SAR_CHAN_SINGLE_ENDED | CY_SAR_CHAN_AVG_DISABLE | (uint32_t)CY_SAR_CHAN_SAMPLE_TIME_1)
#define ADC1_INJ_CONFIG (((uint32_t)SAR1_INJ_VPLUS_PORT << SAR_INJ_CHAN_CONFIG_INJ_PORT_ADDR_Pos) | (uint32_t)(SAR1_INJ_VPLUS_PIN << SAR_INJ_CHAN_CONFIG_INJ_PIN_ADDR_Pos) | CY_SAR_CHAN_SINGLE_ENDED | CY_SAR_CHAN_AVG_DISABLE | (uint32_t)CY_SAR_CHAN_SAMPLE_TIME_0)
#define ADC1_VREF_MV 1650UL
#define ENCODER_SSC_ENABLED 1U
#define ENCODER_SSC_HW SCB1
#define ENCODER_SSC_IRQ scb_1_interrupt_IRQn
#define DEBUG_UART_ENABLED 1U
#define DEBUG_UART_HW SCB2
#define DEBUG_UART_IRQ scb_2_interrupt_IRQn
#define FETDRV_SPI_ENABLED 1U
#define FETDRV_SPI_HW SCB4
#define FETDRV_SPI_IRQ scb_4_interrupt_IRQn
#define WATCHDOG_ENABLED 1U
#define WATCHDOG_HW MCWDT_STRUCT0
#define ENCODER_QUAD1_ENABLED 1U
#define ENCODER_QUAD1_HW TCPWM0
#define ENCODER_QUAD1_NUM 2UL
#define PWM_Timer_ENABLED 1U
#define PWM_Timer_HW TCPWM0
#define PWM_Timer_NUM 256UL
#define PWM_B_ENABLED 1U
#define PWM_B_HW TCPWM0
#define PWM_B_NUM 258UL
#define PWM_C_ENABLED 1U
#define PWM_C_HW TCPWM0
#define PWM_C_NUM 259UL
#define PWM_A_ENABLED 1U
#define PWM_A_HW TCPWM0
#define PWM_A_NUM 260UL

extern const cy_stc_canfd_bitrate_t CANFD_nominalBitrateConfig;
extern const cy_stc_canfd_bitrate_t CANFD_dataBitrateConfig;
extern const cy_stc_canfd_transceiver_delay_compensation_t CANFD_tdcConfig;
extern const cy_stc_id_filter_t CANFD_stdIdFilter_0;
extern const cy_stc_canfd_f0_t CANFD_extIdFilterF0Config_0;
extern const cy_stc_canfd_f1_t CANFD_extIdFilterF1Config_0;
extern const cy_stc_extid_filter_t CANFD_extIdFilter_0;
extern const cy_stc_extid_filter_t CANFD_extIdFilters[];
extern const cy_stc_canfd_extid_filter_config_t CANFD_extIdFiltersConfig;
extern const cy_stc_canfd_global_filter_config_t CANFD_globalFilterConfig;
extern const cy_en_canfd_fifo_config_t CANFD_rxFifo0Config;
extern const cy_en_canfd_fifo_config_t CANFD_rxFifo1Config;
extern const cy_stc_canfd_config_t CANFD_config;
extern cy_stc_canfd_t0_t CANFD_T0RegisterBuffer_0;
extern cy_stc_canfd_t1_t CANFD_T1RegisterBuffer_0;
extern uint32_t CANFD_dataBuffer_0[];
extern cy_stc_canfd_tx_buffer_t CANFD_txBuffer_0;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CANFD_obj;
#endif //defined (CY_USING_HAL)
extern cy_stc_csd_context_t cy_csd_0_context;
extern const cy_stc_sysanalog_config_t AREF_config;
extern const cy_stc_ctb_opamp_config_t OpAmp0_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t OpAmp0_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_ctb_opamp_config_t OpAmp1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t OpAmp1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_sar_common_config_t ADC_config;
extern const cy_stc_sar_config_t ADC0_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ADC0_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_sar_config_t ADC1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ADC1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_scb_spi_config_t ENCODER_SSC_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENCODER_SSC_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_scb_uart_config_t DEBUG_UART_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t DEBUG_UART_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_scb_spi_config_t FETDRV_SPI_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_SPI_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_mcwdt_config_t WATCHDOG_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t WATCHDOG_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_tcpwm_quaddec_config_t ENCODER_QUAD1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENCODER_QUAD1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_tcpwm_pwm_config_t PWM_Timer_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t PWM_Timer_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_tcpwm_pwm_config_t PWM_B_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t PWM_B_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_tcpwm_pwm_config_t PWM_C_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t PWM_C_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_tcpwm_pwm_config_t PWM_A_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t PWM_A_obj;
#endif //defined (CY_USING_HAL)

void init_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PERIPHERALS_H */
