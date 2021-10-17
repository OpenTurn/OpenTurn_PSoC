/*******************************************************************************
* File Name: cycfg_routing.h
*
* Description:
* Establishes all necessary connections between hardware elements.
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

#if !defined(CYCFG_ROUTING_H)
#define CYCFG_ROUTING_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "cycfg_notices.h"
void init_cycfg_routing(void);
#define init_cycfg_connectivity() init_cycfg_routing()
#define ioss_0_port_0_pin_0_HSIOM P0_0_PERI_TR_IO_INPUT0
#define ioss_0_port_0_pin_1_HSIOM P0_1_PERI_TR_IO_INPUT1
#define ioss_0_port_0_pin_4_HSIOM P0_4_PERI_TR_IO_OUTPUT0
#define ioss_0_port_2_pin_0_HSIOM P2_0_SCB1_SPI_MOSI
#define ioss_0_port_2_pin_1_HSIOM P2_1_SCB1_SPI_MISO
#define ioss_0_port_2_pin_2_HSIOM P2_2_SCB1_SPI_CLK
#define ioss_0_port_2_pin_3_HSIOM P2_3_SCB1_SPI_SELECT0
#define ioss_0_port_2_pin_4_HSIOM P2_4_SCB1_SPI_SELECT1
#define ioss_0_port_3_pin_0_HSIOM P3_0_SCB2_UART_RX
#define ioss_0_port_3_pin_1_HSIOM P3_1_SCB2_UART_TX
#define ioss_0_port_5_pin_0_HSIOM P5_0_CANFD0_TTCAN_RX0
#define ioss_0_port_5_pin_1_HSIOM P5_1_CANFD0_TTCAN_TX0
#define ioss_0_port_6_pin_2_HSIOM P6_2_TCPWM0_LINE259
#define ioss_0_port_6_pin_3_HSIOM P6_3_TCPWM0_LINE_COMPL259
#define ioss_0_port_6_pin_4_HSIOM P6_4_CPUSS_SWJ_SWO_TDO
#define ioss_0_port_6_pin_6_HSIOM P6_6_CPUSS_SWJ_SWDIO_TMS
#define ioss_0_port_6_pin_7_HSIOM P6_7_CPUSS_SWJ_SWCLK_TCLK
#define ioss_0_port_7_pin_0_HSIOM P7_0_SCB4_SPI_MOSI
#define ioss_0_port_7_pin_1_HSIOM P7_1_SCB4_SPI_MISO
#define ioss_0_port_7_pin_2_HSIOM P7_2_SCB4_SPI_CLK
#define ioss_0_port_7_pin_3_HSIOM P7_3_SCB4_SPI_SELECT0
#define ioss_0_port_8_pin_0_HSIOM P8_0_TCPWM0_LINE258
#define ioss_0_port_8_pin_1_HSIOM P8_1_TCPWM0_LINE_COMPL258
#define ioss_0_port_9_pin_2_ANALOG P9_2_PASS_CTB_PADS2
#define ioss_0_port_9_pin_4_HSIOM P9_4_TCPWM0_LINE256
#define ioss_0_port_10_pin_0_HSIOM P10_0_PERI_TR_IO_INPUT20
#define ioss_0_port_10_pin_1_ANALOG P10_1_PASS_SARMUX_PADS1
#define ioss_0_port_10_pin_2_ANALOG P10_2_PASS_SARMUX_PADS2
#define ioss_0_port_10_pin_3_ANALOG P10_3_PASS_SARMUX_PADS3
#define ioss_0_port_10_pin_4_ANALOG P10_4_PASS_SARMUX_PADS4
#define ioss_0_port_10_pin_5_ANALOG P10_5_PASS_SARMUX_PADS5
#define ioss_0_port_11_pin_4_HSIOM P11_4_TCPWM0_LINE260
#define ioss_0_port_11_pin_5_HSIOM P11_5_TCPWM0_LINE_COMPL260

#define ADC0_tr_sar_in_0_TRIGGER_OUT TRIG_OUT_MUX_9_PASS_TR_SAR_IN0
#define ADC0_tr_sar_out_0_TRIGGER_IN TRIG_IN_MUX_4_PASS_SAR0_DONE
#define ENCODER_QOAD_A1_digital_in_0_TRIGGER_IN TRIG_IN_MUX_2_HSIOM_TR_OUT1
#define ENCODER_QOAD_B1_digital_in_0_TRIGGER_IN TRIG_IN_MUX_2_HSIOM_TR_OUT0
#define ENCODER_QOAD_B2_digital_out_0_TRIGGER_OUT TRIG_OUT_MUX_4_HSIOM_TR_IO_OUTPUT0
#define ENCODER_QUAD1_capture0_0_TRIGGER_OUT TRIG_OUT_MUX_3_TCPWM0_TR_IN22
#define ENCODER_QUAD1_count_0_TRIGGER_OUT TRIG_OUT_MUX_2_TCPWM0_TR_IN9
#define ENCODER_QUAD1_start_0_TRIGGER_OUT TRIG_OUT_MUX_2_TCPWM0_TR_IN8
#define NC_0_digital_in_0_TRIGGER_IN TRIG_IN_MUX_3_HSIOM_TR_OUT20
#define PWM_A_capture0_0_TRIGGER_OUT TRIG_OUT_MUX_3_TCPWM0_TR_IN21
#define PWM_A_start_0_TRIGGER_OUT TRIG_OUT_MUX_3_TCPWM0_TR_IN23
#define PWM_B_capture0_0_TRIGGER_OUT TRIG_OUT_MUX_3_TCPWM0_TR_IN21
#define PWM_B_start_0_TRIGGER_OUT TRIG_OUT_MUX_3_TCPWM0_TR_IN23
#define PWM_C_capture0_0_TRIGGER_OUT TRIG_OUT_MUX_3_TCPWM0_TR_IN21
#define PWM_C_start_0_TRIGGER_OUT TRIG_OUT_MUX_3_TCPWM0_TR_IN23
#define PWM_Timer_tr_out0_0_TRIGGER_IN_0 TRIG_IN_MUX_3_TCPWM0_TR_OUT0256
#define PWM_Timer_tr_out0_0_TRIGGER_IN_1 TRIG_IN_MUX_9_TCPWM0_TR_OUT0256
#define PWM_Timer_tr_out1_0_TRIGGER_IN TRIG_IN_MUX_3_TCPWM0_TR_OUT1256

#define SAR0_INJ_VPLUS_PIN 4
#define SAR0_INJ_VPLUS_PORT 0
#define SAR0_VPLUS0_PIN 3
#define SAR0_VPLUS0_PORT 0
#define SAR0_VPLUS1_PIN 2
#define SAR0_VPLUS1_PORT 0
#define SAR0_VPLUS2_PIN 1
#define SAR0_VPLUS2_PORT 0
#define SAR1_INJ_VPLUS_PIN 5
#define SAR1_INJ_VPLUS_PORT 0
#define SAR1_VPLUS0_PIN 3
#define SAR1_VPLUS0_PORT 0
#define SAR1_VPLUS1_PIN 2
#define SAR1_VPLUS1_PORT 0
#define SAR1_VPLUS2_PIN 1
#define SAR1_VPLUS2_PORT 0

#define TCPWM0_GRP0_CNT2_CAPTURE0_VALUE 0x19
#define TCPWM0_GRP0_CNT2_COUNT_VALUE 0xC
#define TCPWM0_GRP0_CNT2_START_VALUE 0xB
#define TCPWM0_GRP1_CNT2_CAPTURE0_VALUE 0x18
#define TCPWM0_GRP1_CNT2_START_VALUE 0x1A
#define TCPWM0_GRP1_CNT3_CAPTURE0_VALUE 0x18
#define TCPWM0_GRP1_CNT3_START_VALUE 0x1A
#define TCPWM0_GRP1_CNT4_CAPTURE0_VALUE 0x18
#define TCPWM0_GRP1_CNT4_START_VALUE 0x1A

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_ROUTING_H */
