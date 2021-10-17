/*******************************************************************************
* File Name: cycfg_pins.h
*
* Description:
* Pin configuration
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

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"
#if defined (CY_USING_HAL)
	#include "cyhal_hwmgr.h"
#endif //defined (CY_USING_HAL)
#include "cy_smartio.h"
#include "cy_sysclk.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define ENCODER_QOAD_B1_ENABLED 1U
#define ENCODER_QOAD_B1_PORT GPIO_PRT0
#define ENCODER_QOAD_B1_PORT_NUM 0U
#define ENCODER_QOAD_B1_PIN 0U
#define ENCODER_QOAD_B1_NUM 0U
#define ENCODER_QOAD_B1_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ENCODER_QOAD_B1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_0_HSIOM
	#define ioss_0_port_0_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ENCODER_QOAD_B1_HSIOM ioss_0_port_0_pin_0_HSIOM
#define ENCODER_QOAD_B1_IRQ ioss_interrupts_gpio_0_IRQn
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_B1_HAL_PORT_PIN P0_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_B1 P0_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_B1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_B1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_B1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define ENCODER_QOAD_A1_ENABLED 1U
#define ENCODER_QOAD_A1_PORT GPIO_PRT0
#define ENCODER_QOAD_A1_PORT_NUM 0U
#define ENCODER_QOAD_A1_PIN 1U
#define ENCODER_QOAD_A1_NUM 1U
#define ENCODER_QOAD_A1_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ENCODER_QOAD_A1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_1_HSIOM
	#define ioss_0_port_0_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ENCODER_QOAD_A1_HSIOM ioss_0_port_0_pin_1_HSIOM
#define ENCODER_QOAD_A1_IRQ ioss_interrupts_gpio_0_IRQn
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_A1_HAL_PORT_PIN P0_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_A1 P0_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_A1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_A1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_A1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define ENCODER_QOAD_I1_ENABLED 1U
#define ENCODER_QOAD_I1_PORT GPIO_PRT0
#define ENCODER_QOAD_I1_PORT_NUM 0U
#define ENCODER_QOAD_I1_PIN 2U
#define ENCODER_QOAD_I1_NUM 2U
#define ENCODER_QOAD_I1_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ENCODER_QOAD_I1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_2_HSIOM
	#define ioss_0_port_0_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ENCODER_QOAD_I1_HSIOM ioss_0_port_0_pin_2_HSIOM
#define ENCODER_QOAD_I1_IRQ ioss_interrupts_gpio_0_IRQn
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_I1_HAL_PORT_PIN P0_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_I1 P0_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_I1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_I1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_I1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define ENCODER_QOAD_I2_ENABLED 1U
#define ENCODER_QOAD_I2_PORT GPIO_PRT0
#define ENCODER_QOAD_I2_PORT_NUM 0U
#define ENCODER_QOAD_I2_PIN 3U
#define ENCODER_QOAD_I2_NUM 3U
#define ENCODER_QOAD_I2_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ENCODER_QOAD_I2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_3_HSIOM
	#define ioss_0_port_0_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ENCODER_QOAD_I2_HSIOM ioss_0_port_0_pin_3_HSIOM
#define ENCODER_QOAD_I2_IRQ ioss_interrupts_gpio_0_IRQn
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_I2_HAL_PORT_PIN P0_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_I2 P0_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_I2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_I2_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_I2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define ENCODER_QOAD_B2_ENABLED 1U
#define ENCODER_QOAD_B2_PORT GPIO_PRT0
#define ENCODER_QOAD_B2_PORT_NUM 0U
#define ENCODER_QOAD_B2_PIN 4U
#define ENCODER_QOAD_B2_NUM 4U
#define ENCODER_QOAD_B2_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ENCODER_QOAD_B2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_4_HSIOM
	#define ioss_0_port_0_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define ENCODER_QOAD_B2_HSIOM ioss_0_port_0_pin_4_HSIOM
#define ENCODER_QOAD_B2_IRQ ioss_interrupts_gpio_0_IRQn
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_B2_HAL_PORT_PIN P0_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_B2 P0_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_B2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_B2_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_B2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define ENCODER_QOAD_A2_ENABLED 1U
#define ENCODER_QOAD_A2_PORT GPIO_PRT0
#define ENCODER_QOAD_A2_PORT_NUM 0U
#define ENCODER_QOAD_A2_PIN 5U
#define ENCODER_QOAD_A2_NUM 5U
#define ENCODER_QOAD_A2_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ENCODER_QOAD_A2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_5_HSIOM
	#define ioss_0_port_0_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define ENCODER_QOAD_A2_HSIOM ioss_0_port_0_pin_5_HSIOM
#define ENCODER_QOAD_A2_IRQ ioss_interrupts_gpio_0_IRQn
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_A2_HAL_PORT_PIN P0_5
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_A2 P0_5
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_A2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_A2_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENCODER_QOAD_A2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define NC_0_ENABLED 1U
#define NC_0_PORT GPIO_PRT10
#define NC_0_PORT_NUM 10U
#define NC_0_PIN 0U
#define NC_0_NUM 0U
#define NC_0_DRIVEMODE CY_GPIO_DM_HIGHZ
#define NC_0_INIT_DRIVESTATE 0
#ifndef ioss_0_port_10_pin_0_HSIOM
	#define ioss_0_port_10_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define NC_0_HSIOM ioss_0_port_10_pin_0_HSIOM
#define NC_0_IRQ ioss_interrupts_gpio_10_IRQn
#if defined (CY_USING_HAL)
	#define NC_0_HAL_PORT_PIN P10_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define NC_0 P10_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define NC_0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define NC_0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define NC_0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define ADC_ISENSE_C_ENABLED 1U
#define ADC_ISENSE_C_PORT GPIO_PRT10
#define ADC_ISENSE_C_PORT_NUM 10U
#define ADC_ISENSE_C_PIN 1U
#define ADC_ISENSE_C_NUM 1U
#define ADC_ISENSE_C_DRIVEMODE CY_GPIO_DM_ANALOG
#define ADC_ISENSE_C_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_1_HSIOM
	#define ioss_0_port_10_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ADC_ISENSE_C_HSIOM ioss_0_port_10_pin_1_HSIOM
#define ADC_ISENSE_C_IRQ ioss_interrupts_gpio_10_IRQn
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_C_HAL_PORT_PIN P10_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_C P10_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_C_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_C_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_C_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define ADC_ISENSE_B_ENABLED 1U
#define ADC_ISENSE_B_PORT GPIO_PRT10
#define ADC_ISENSE_B_PORT_NUM 10U
#define ADC_ISENSE_B_PIN 2U
#define ADC_ISENSE_B_NUM 2U
#define ADC_ISENSE_B_DRIVEMODE CY_GPIO_DM_ANALOG
#define ADC_ISENSE_B_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_2_HSIOM
	#define ioss_0_port_10_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ADC_ISENSE_B_HSIOM ioss_0_port_10_pin_2_HSIOM
#define ADC_ISENSE_B_IRQ ioss_interrupts_gpio_10_IRQn
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_B_HAL_PORT_PIN P10_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_B P10_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_B_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_B_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_B_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define ADC_ISENSE_A_ENABLED 1U
#define ADC_ISENSE_A_PORT GPIO_PRT10
#define ADC_ISENSE_A_PORT_NUM 10U
#define ADC_ISENSE_A_PIN 3U
#define ADC_ISENSE_A_NUM 3U
#define ADC_ISENSE_A_DRIVEMODE CY_GPIO_DM_ANALOG
#define ADC_ISENSE_A_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_3_HSIOM
	#define ioss_0_port_10_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ADC_ISENSE_A_HSIOM ioss_0_port_10_pin_3_HSIOM
#define ADC_ISENSE_A_IRQ ioss_interrupts_gpio_10_IRQn
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_A_HAL_PORT_PIN P10_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_A P10_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_A_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_A_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_ISENSE_A_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define ADC_VBUS_SENSE_ENABLED 1U
#define ADC_VBUS_SENSE_PORT GPIO_PRT10
#define ADC_VBUS_SENSE_PORT_NUM 10U
#define ADC_VBUS_SENSE_PIN 4U
#define ADC_VBUS_SENSE_NUM 4U
#define ADC_VBUS_SENSE_DRIVEMODE CY_GPIO_DM_ANALOG
#define ADC_VBUS_SENSE_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_4_HSIOM
	#define ioss_0_port_10_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define ADC_VBUS_SENSE_HSIOM ioss_0_port_10_pin_4_HSIOM
#define ADC_VBUS_SENSE_IRQ ioss_interrupts_gpio_10_IRQn
#if defined (CY_USING_HAL)
	#define ADC_VBUS_SENSE_HAL_PORT_PIN P10_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_VBUS_SENSE P10_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_VBUS_SENSE_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_VBUS_SENSE_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_VBUS_SENSE_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define ADC_TEMP1_ENABLED 1U
#define ADC_TEMP1_PORT GPIO_PRT10
#define ADC_TEMP1_PORT_NUM 10U
#define ADC_TEMP1_PIN 5U
#define ADC_TEMP1_NUM 5U
#define ADC_TEMP1_DRIVEMODE CY_GPIO_DM_ANALOG
#define ADC_TEMP1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_5_HSIOM
	#define ioss_0_port_10_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define ADC_TEMP1_HSIOM ioss_0_port_10_pin_5_HSIOM
#define ADC_TEMP1_IRQ ioss_interrupts_gpio_10_IRQn
#if defined (CY_USING_HAL)
	#define ADC_TEMP1_HAL_PORT_PIN P10_5
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_TEMP1 P10_5
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_TEMP1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_TEMP1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ADC_TEMP1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define GPIO1_ENABLED 1U
#define GPIO1_PORT GPIO_PRT10
#define GPIO1_PORT_NUM 10U
#define GPIO1_PIN 6U
#define GPIO1_NUM 6U
#define GPIO1_DRIVEMODE CY_GPIO_DM_ANALOG
#define GPIO1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_6_HSIOM
	#define ioss_0_port_10_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO1_HSIOM ioss_0_port_10_pin_6_HSIOM
#define GPIO1_IRQ ioss_interrupts_gpio_10_IRQn
#if defined (CY_USING_HAL)
	#define GPIO1_HAL_PORT_PIN P10_6
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO1 P10_6
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO1_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define GPIO0_ENABLED 1U
#define GPIO0_PORT GPIO_PRT10
#define GPIO0_PORT_NUM 10U
#define GPIO0_PIN 7U
#define GPIO0_NUM 7U
#define GPIO0_DRIVEMODE CY_GPIO_DM_ANALOG
#define GPIO0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_7_HSIOM
	#define ioss_0_port_10_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO0_HSIOM ioss_0_port_10_pin_7_HSIOM
#define GPIO0_IRQ ioss_interrupts_gpio_10_IRQn
#if defined (CY_USING_HAL)
	#define GPIO0_HAL_PORT_PIN P10_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO0 P10_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO0_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define NC_1 (P11_2)
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define NC_2 (P11_3)
#endif //defined (CY_USING_HAL)
#define PWM_AL_ENABLED 1U
#define PWM_AL_PORT GPIO_PRT11
#define PWM_AL_PORT_NUM 11U
#define PWM_AL_PIN 4U
#define PWM_AL_NUM 4U
#define PWM_AL_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PWM_AL_INIT_DRIVESTATE 0
#ifndef ioss_0_port_11_pin_4_HSIOM
	#define ioss_0_port_11_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define PWM_AL_HSIOM ioss_0_port_11_pin_4_HSIOM
#define PWM_AL_IRQ ioss_interrupts_gpio_11_IRQn
#if defined (CY_USING_HAL)
	#define PWM_AL_HAL_PORT_PIN P11_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define PWM_AL P11_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define PWM_AL_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define PWM_AL_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define PWM_AL_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define PWM_AH_ENABLED 1U
#define PWM_AH_PORT GPIO_PRT11
#define PWM_AH_PORT_NUM 11U
#define PWM_AH_PIN 5U
#define PWM_AH_NUM 5U
#define PWM_AH_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PWM_AH_INIT_DRIVESTATE 0
#ifndef ioss_0_port_11_pin_5_HSIOM
	#define ioss_0_port_11_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define PWM_AH_HSIOM ioss_0_port_11_pin_5_HSIOM
#define PWM_AH_IRQ ioss_interrupts_gpio_11_IRQn
#if defined (CY_USING_HAL)
	#define PWM_AH_HAL_PORT_PIN P11_5
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define PWM_AH P11_5
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define PWM_AH_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define PWM_AH_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define PWM_AH_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define NC_3 (P11_6)
#endif //defined (CY_USING_HAL)
#define NC_4_ENABLED 1U
#define NC_4_PORT GPIO_PRT11
#define NC_4_PORT_NUM 11U
#define NC_4_PIN 7U
#define NC_4_NUM 7U
#define NC_4_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define NC_4_INIT_DRIVESTATE 1
#ifndef ioss_0_port_11_pin_7_HSIOM
	#define ioss_0_port_11_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define NC_4_HSIOM ioss_0_port_11_pin_7_HSIOM
#define NC_4_IRQ ioss_interrupts_gpio_11_IRQn
#if defined (CY_USING_HAL)
	#define NC_4_HAL_PORT_PIN P11_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define NC_4 P11_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define NC_4_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define NC_4_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define NC_4_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define ECO_IN_ENABLED 1U
#define ECO_IN_PORT GPIO_PRT12
#define ECO_IN_PORT_NUM 12U
#define ECO_IN_PIN 6U
#define ECO_IN_NUM 6U
#define ECO_IN_DRIVEMODE CY_GPIO_DM_ANALOG
#define ECO_IN_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_6_HSIOM
	#define ioss_0_port_12_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define ECO_IN_HSIOM ioss_0_port_12_pin_6_HSIOM
#define ECO_IN_IRQ ioss_interrupts_gpio_12_IRQn
#if defined (CY_USING_HAL)
	#define ECO_IN_HAL_PORT_PIN P12_6
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ECO_IN P12_6
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ECO_IN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ECO_IN_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ECO_IN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define ECO_OUT_ENABLED 1U
#define ECO_OUT_PORT GPIO_PRT12
#define ECO_OUT_PORT_NUM 12U
#define ECO_OUT_PIN 7U
#define ECO_OUT_NUM 7U
#define ECO_OUT_DRIVEMODE CY_GPIO_DM_ANALOG
#define ECO_OUT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_12_pin_7_HSIOM
	#define ioss_0_port_12_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define ECO_OUT_HSIOM ioss_0_port_12_pin_7_HSIOM
#define ECO_OUT_IRQ ioss_interrupts_gpio_12_IRQn
#if defined (CY_USING_HAL)
	#define ECO_OUT_HAL_PORT_PIN P12_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ECO_OUT P12_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ECO_OUT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ECO_OUT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ECO_OUT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define ENC_SSC_DO_ENABLED 1U
#define ENC_SSC_DO_PORT GPIO_PRT2
#define ENC_SSC_DO_PORT_NUM 2U
#define ENC_SSC_DO_PIN 0U
#define ENC_SSC_DO_NUM 0U
#define ENC_SSC_DO_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ENC_SSC_DO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_0_HSIOM
	#define ioss_0_port_2_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ENC_SSC_DO_HSIOM ioss_0_port_2_pin_0_HSIOM
#define ENC_SSC_DO_IRQ ioss_interrupts_gpio_2_IRQn
#if defined (CY_USING_HAL)
	#define ENC_SSC_DO_HAL_PORT_PIN P2_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_DO P2_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_DO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_DO_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_DO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define ENC_SSC_DI_ENABLED 1U
#define ENC_SSC_DI_PORT GPIO_PRT2
#define ENC_SSC_DI_PORT_NUM 2U
#define ENC_SSC_DI_PIN 1U
#define ENC_SSC_DI_NUM 1U
#define ENC_SSC_DI_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ENC_SSC_DI_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_1_HSIOM
	#define ioss_0_port_2_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ENC_SSC_DI_HSIOM ioss_0_port_2_pin_1_HSIOM
#define ENC_SSC_DI_IRQ ioss_interrupts_gpio_2_IRQn
#if defined (CY_USING_HAL)
	#define ENC_SSC_DI_HAL_PORT_PIN P2_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_DI P2_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_DI_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_DI_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_DI_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define ENC_SSC_SCK_ENABLED 1U
#define ENC_SSC_SCK_PORT GPIO_PRT2
#define ENC_SSC_SCK_PORT_NUM 2U
#define ENC_SSC_SCK_PIN 2U
#define ENC_SSC_SCK_NUM 2U
#define ENC_SSC_SCK_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ENC_SSC_SCK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_2_HSIOM
	#define ioss_0_port_2_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ENC_SSC_SCK_HSIOM ioss_0_port_2_pin_2_HSIOM
#define ENC_SSC_SCK_IRQ ioss_interrupts_gpio_2_IRQn
#if defined (CY_USING_HAL)
	#define ENC_SSC_SCK_HAL_PORT_PIN P2_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_SCK P2_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_SCK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_SCK_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_SCK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define ENC_SSC_CS1_ENABLED 1U
#define ENC_SSC_CS1_PORT GPIO_PRT2
#define ENC_SSC_CS1_PORT_NUM 2U
#define ENC_SSC_CS1_PIN 3U
#define ENC_SSC_CS1_NUM 3U
#define ENC_SSC_CS1_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ENC_SSC_CS1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_3_HSIOM
	#define ioss_0_port_2_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ENC_SSC_CS1_HSIOM ioss_0_port_2_pin_3_HSIOM
#define ENC_SSC_CS1_IRQ ioss_interrupts_gpio_2_IRQn
#if defined (CY_USING_HAL)
	#define ENC_SSC_CS1_HAL_PORT_PIN P2_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_CS1 P2_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_CS1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_CS1_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_CS1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define ENC_SSC_CS2_ENABLED 1U
#define ENC_SSC_CS2_PORT GPIO_PRT2
#define ENC_SSC_CS2_PORT_NUM 2U
#define ENC_SSC_CS2_PIN 4U
#define ENC_SSC_CS2_NUM 4U
#define ENC_SSC_CS2_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ENC_SSC_CS2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_4_HSIOM
	#define ioss_0_port_2_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define ENC_SSC_CS2_HSIOM ioss_0_port_2_pin_4_HSIOM
#define ENC_SSC_CS2_IRQ ioss_interrupts_gpio_2_IRQn
#if defined (CY_USING_HAL)
	#define ENC_SSC_CS2_HAL_PORT_PIN P2_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_CS2 P2_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_CS2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_CS2_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define ENC_SSC_CS2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define CANF_SILENT_ENABLED 1U
#define CANF_SILENT_PORT GPIO_PRT2
#define CANF_SILENT_PORT_NUM 2U
#define CANF_SILENT_PIN 5U
#define CANF_SILENT_NUM 5U
#define CANF_SILENT_DRIVEMODE CY_GPIO_DM_STRONG
#define CANF_SILENT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_5_HSIOM
	#define ioss_0_port_2_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define CANF_SILENT_HSIOM ioss_0_port_2_pin_5_HSIOM
#define CANF_SILENT_IRQ ioss_interrupts_gpio_2_IRQn
#if defined (CY_USING_HAL)
	#define CANF_SILENT_HAL_PORT_PIN P2_5
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANF_SILENT P2_5
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANF_SILENT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANF_SILENT_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANF_SILENT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define LED0_ENABLED 1U
#define LED0_PORT GPIO_PRT2
#define LED0_PORT_NUM 2U
#define LED0_PIN 6U
#define LED0_NUM 6U
#define LED0_DRIVEMODE CY_GPIO_DM_STRONG
#define LED0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_6_HSIOM
	#define ioss_0_port_2_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define LED0_HSIOM ioss_0_port_2_pin_6_HSIOM
#define LED0_IRQ ioss_interrupts_gpio_2_IRQn
#if defined (CY_USING_HAL)
	#define LED0_HAL_PORT_PIN P2_6
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define LED0 P2_6
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define LED0_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define LED0_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define LED0_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define LED1_ENABLED 1U
#define LED1_PORT GPIO_PRT2
#define LED1_PORT_NUM 2U
#define LED1_PIN 7U
#define LED1_NUM 7U
#define LED1_DRIVEMODE CY_GPIO_DM_STRONG
#define LED1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_7_HSIOM
	#define ioss_0_port_2_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define LED1_HSIOM ioss_0_port_2_pin_7_HSIOM
#define LED1_IRQ ioss_interrupts_gpio_2_IRQn
#if defined (CY_USING_HAL)
	#define LED1_HAL_PORT_PIN P2_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define LED1 P2_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define LED1_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define LED1_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define LED1_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define DEBUG_UART_RX_ENABLED 1U
#define DEBUG_UART_RX_PORT GPIO_PRT3
#define DEBUG_UART_RX_PORT_NUM 3U
#define DEBUG_UART_RX_PIN 0U
#define DEBUG_UART_RX_NUM 0U
#define DEBUG_UART_RX_DRIVEMODE CY_GPIO_DM_HIGHZ
#define DEBUG_UART_RX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_3_pin_0_HSIOM
	#define ioss_0_port_3_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define DEBUG_UART_RX_HSIOM ioss_0_port_3_pin_0_HSIOM
#define DEBUG_UART_RX_IRQ ioss_interrupts_gpio_3_IRQn
#if defined (CY_USING_HAL)
	#define DEBUG_UART_RX_HAL_PORT_PIN P3_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define DEBUG_UART_RX P3_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define DEBUG_UART_RX_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define DEBUG_UART_RX_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define DEBUG_UART_RX_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define DEBUG_UART_TX_ENABLED 1U
#define DEBUG_UART_TX_PORT GPIO_PRT3
#define DEBUG_UART_TX_PORT_NUM 3U
#define DEBUG_UART_TX_PIN 1U
#define DEBUG_UART_TX_NUM 1U
#define DEBUG_UART_TX_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define DEBUG_UART_TX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_3_pin_1_HSIOM
	#define ioss_0_port_3_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define DEBUG_UART_TX_HSIOM ioss_0_port_3_pin_1_HSIOM
#define DEBUG_UART_TX_IRQ ioss_interrupts_gpio_3_IRQn
#if defined (CY_USING_HAL)
	#define DEBUG_UART_TX_HAL_PORT_PIN P3_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define DEBUG_UART_TX P3_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define DEBUG_UART_TX_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define DEBUG_UART_TX_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define DEBUG_UART_TX_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define CANFD_RX_ENABLED 1U
#define CANFD_RX_PORT GPIO_PRT5
#define CANFD_RX_PORT_NUM 5U
#define CANFD_RX_PIN 0U
#define CANFD_RX_NUM 0U
#define CANFD_RX_DRIVEMODE CY_GPIO_DM_PULLUP
#define CANFD_RX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_0_HSIOM
	#define ioss_0_port_5_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define CANFD_RX_HSIOM ioss_0_port_5_pin_0_HSIOM
#define CANFD_RX_IRQ ioss_interrupts_gpio_5_IRQn
#if defined (CY_USING_HAL)
	#define CANFD_RX_HAL_PORT_PIN P5_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_RX P5_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_RX_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_RX_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_RX_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#endif //defined (CY_USING_HAL)
#define CANFD_TX_ENABLED 1U
#define CANFD_TX_PORT GPIO_PRT5
#define CANFD_TX_PORT_NUM 5U
#define CANFD_TX_PIN 1U
#define CANFD_TX_NUM 1U
#define CANFD_TX_DRIVEMODE CY_GPIO_DM_STRONG
#define CANFD_TX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_1_HSIOM
	#define ioss_0_port_5_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define CANFD_TX_HSIOM ioss_0_port_5_pin_1_HSIOM
#define CANFD_TX_IRQ ioss_interrupts_gpio_5_IRQn
#if defined (CY_USING_HAL)
	#define CANFD_TX_HAL_PORT_PIN P5_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_TX P5_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_TX_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_TX_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_TX_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define GPIO2_ENABLED 1U
#define GPIO2_PORT GPIO_PRT5
#define GPIO2_PORT_NUM 5U
#define GPIO2_PIN 6U
#define GPIO2_NUM 6U
#define GPIO2_DRIVEMODE CY_GPIO_DM_HIGHZ
#define GPIO2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_6_HSIOM
	#define ioss_0_port_5_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO2_HSIOM ioss_0_port_5_pin_6_HSIOM
#define GPIO2_IRQ ioss_interrupts_gpio_5_IRQn
#if defined (CY_USING_HAL)
	#define GPIO2_HAL_PORT_PIN P5_6
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO2 P5_6
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO2_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO2_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO2_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define GPIO3_ENABLED 1U
#define GPIO3_PORT GPIO_PRT5
#define GPIO3_PORT_NUM 5U
#define GPIO3_PIN 7U
#define GPIO3_NUM 7U
#define GPIO3_DRIVEMODE CY_GPIO_DM_HIGHZ
#define GPIO3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_7_HSIOM
	#define ioss_0_port_5_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define GPIO3_HSIOM ioss_0_port_5_pin_7_HSIOM
#define GPIO3_IRQ ioss_interrupts_gpio_5_IRQn
#if defined (CY_USING_HAL)
	#define GPIO3_HAL_PORT_PIN P5_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO3 P5_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO3_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define GPIO3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define FETDRV_PWM_CL_ENABLED 1U
#define FETDRV_PWM_CL_PORT GPIO_PRT6
#define FETDRV_PWM_CL_PORT_NUM 6U
#define FETDRV_PWM_CL_PIN 2U
#define FETDRV_PWM_CL_NUM 2U
#define FETDRV_PWM_CL_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define FETDRV_PWM_CL_INIT_DRIVESTATE 0
#ifndef ioss_0_port_6_pin_2_HSIOM
	#define ioss_0_port_6_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_PWM_CL_HSIOM ioss_0_port_6_pin_2_HSIOM
#define FETDRV_PWM_CL_IRQ ioss_interrupts_gpio_6_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_CL_HAL_PORT_PIN P6_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_CL P6_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_CL_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_CL_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_CL_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define FETDRV_PWM_CH_ENABLED 1U
#define FETDRV_PWM_CH_PORT GPIO_PRT6
#define FETDRV_PWM_CH_PORT_NUM 6U
#define FETDRV_PWM_CH_PIN 3U
#define FETDRV_PWM_CH_NUM 3U
#define FETDRV_PWM_CH_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define FETDRV_PWM_CH_INIT_DRIVESTATE 0
#ifndef ioss_0_port_6_pin_3_HSIOM
	#define ioss_0_port_6_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_PWM_CH_HSIOM ioss_0_port_6_pin_3_HSIOM
#define FETDRV_PWM_CH_IRQ ioss_interrupts_gpio_6_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_CH_HAL_PORT_PIN P6_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_CH P6_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_CH_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_CH_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_CH_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define SWO_ENABLED 1U
#define DEBUG_I2C_SCL_ENABLED SWO_ENABLED
#define SWO_PORT GPIO_PRT6
#define DEBUG_I2C_SCL_PORT SWO_PORT
#define SWO_PORT_NUM 6U
#define DEBUG_I2C_SCL_PORT_NUM SWO_PORT_NUM
#define SWO_PIN 4U
#define DEBUG_I2C_SCL_PIN SWO_PIN
#define SWO_NUM 4U
#define DEBUG_I2C_SCL_NUM SWO_NUM
#define SWO_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define DEBUG_I2C_SCL_DRIVEMODE SWO_DRIVEMODE
#define SWO_INIT_DRIVESTATE 1
#define DEBUG_I2C_SCL_INIT_DRIVESTATE SWO_INIT_DRIVESTATE
#ifndef ioss_0_port_6_pin_4_HSIOM
	#define ioss_0_port_6_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define SWO_HSIOM ioss_0_port_6_pin_4_HSIOM
#define DEBUG_I2C_SCL_HSIOM SWO_HSIOM
#define SWO_IRQ ioss_interrupts_gpio_6_IRQn
#define DEBUG_I2C_SCL_IRQ SWO_IRQ
#if defined (CY_USING_HAL)
	#define SWO_HAL_PORT_PIN P6_4
	#define DEBUG_I2C_SCL_HAL_PORT_PIN SWO_HAL_PORT_PIN
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWO P6_4
	#define DEBUG_I2C_SCL SWO
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
	#define DEBUG_I2C_SCL_HAL_IRQ SWO_HAL_IRQ
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWO_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
	#define DEBUG_I2C_SCL_HAL_DIR SWO_HAL_DIR
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
	#define DEBUG_I2C_SCL_HAL_DRIVEMODE SWO_HAL_DRIVEMODE
#endif //defined (CY_USING_HAL)
#define TDI_ENABLED 1U
#define DEBUG_I2C_SDA_ENABLED TDI_ENABLED
#define TDI_PORT GPIO_PRT6
#define DEBUG_I2C_SDA_PORT TDI_PORT
#define TDI_PORT_NUM 6U
#define DEBUG_I2C_SDA_PORT_NUM TDI_PORT_NUM
#define TDI_PIN 5U
#define DEBUG_I2C_SDA_PIN TDI_PIN
#define TDI_NUM 5U
#define DEBUG_I2C_SDA_NUM TDI_NUM
#define TDI_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define DEBUG_I2C_SDA_DRIVEMODE TDI_DRIVEMODE
#define TDI_INIT_DRIVESTATE 1
#define DEBUG_I2C_SDA_INIT_DRIVESTATE TDI_INIT_DRIVESTATE
#ifndef ioss_0_port_6_pin_5_HSIOM
	#define ioss_0_port_6_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define TDI_HSIOM ioss_0_port_6_pin_5_HSIOM
#define DEBUG_I2C_SDA_HSIOM TDI_HSIOM
#define TDI_IRQ ioss_interrupts_gpio_6_IRQn
#define DEBUG_I2C_SDA_IRQ TDI_IRQ
#if defined (CY_USING_HAL)
	#define TDI_HAL_PORT_PIN P6_5
	#define DEBUG_I2C_SDA_HAL_PORT_PIN TDI_HAL_PORT_PIN
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define TDI P6_5
	#define DEBUG_I2C_SDA TDI
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define TDI_HAL_IRQ CYHAL_GPIO_IRQ_NONE
	#define DEBUG_I2C_SDA_HAL_IRQ TDI_HAL_IRQ
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define TDI_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
	#define DEBUG_I2C_SDA_HAL_DIR TDI_HAL_DIR
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define TDI_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_OPENDRAINDRIVESLOW
	#define DEBUG_I2C_SDA_HAL_DRIVEMODE TDI_HAL_DRIVEMODE
#endif //defined (CY_USING_HAL)
#define SWDIO_ENABLED 1U
#define SWDIO_PORT GPIO_PRT6
#define SWDIO_PORT_NUM 6U
#define SWDIO_PIN 6U
#define SWDIO_NUM 6U
#define SWDIO_DRIVEMODE CY_GPIO_DM_PULLUP
#define SWDIO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_6_HSIOM
	#define ioss_0_port_6_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define SWDIO_HSIOM ioss_0_port_6_pin_6_HSIOM
#define SWDIO_IRQ ioss_interrupts_gpio_6_IRQn
#if defined (CY_USING_HAL)
	#define SWDIO_HAL_PORT_PIN P6_6
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWDIO P6_6
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWDIO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWDIO_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWDIO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#endif //defined (CY_USING_HAL)
#define SWDCLK_ENABLED 1U
#define SWDCLK_PORT GPIO_PRT6
#define SWDCLK_PORT_NUM 6U
#define SWDCLK_PIN 7U
#define SWDCLK_NUM 7U
#define SWDCLK_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define SWDCLK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_7_HSIOM
	#define ioss_0_port_6_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define SWDCLK_HSIOM ioss_0_port_6_pin_7_HSIOM
#define SWDCLK_IRQ ioss_interrupts_gpio_6_IRQn
#if defined (CY_USING_HAL)
	#define SWDCLK_HAL_PORT_PIN P6_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWDCLK P6_7
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWDCLK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWDCLK_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define SWDCLK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLDOWN
#endif //defined (CY_USING_HAL)
#define FETDRV_MOSI_ENABLED 1U
#define FETDRV_MOSI_PORT GPIO_PRT7
#define FETDRV_MOSI_PORT_NUM 7U
#define FETDRV_MOSI_PIN 0U
#define FETDRV_MOSI_NUM 0U
#define FETDRV_MOSI_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define FETDRV_MOSI_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_0_HSIOM
	#define ioss_0_port_7_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_MOSI_HSIOM ioss_0_port_7_pin_0_HSIOM
#define FETDRV_MOSI_IRQ ioss_interrupts_gpio_7_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_MOSI_HAL_PORT_PIN P7_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_MOSI P7_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_MOSI_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_MOSI_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_MOSI_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define FETDRV_MISO_ENABLED 1U
#define FETDRV_MISO_PORT GPIO_PRT7
#define FETDRV_MISO_PORT_NUM 7U
#define FETDRV_MISO_PIN 1U
#define FETDRV_MISO_NUM 1U
#define FETDRV_MISO_DRIVEMODE CY_GPIO_DM_HIGHZ
#define FETDRV_MISO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_1_HSIOM
	#define ioss_0_port_7_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_MISO_HSIOM ioss_0_port_7_pin_1_HSIOM
#define FETDRV_MISO_IRQ ioss_interrupts_gpio_7_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_MISO_HAL_PORT_PIN P7_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_MISO P7_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_MISO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_MISO_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_MISO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define FETDRV_SCK_ENABLED 1U
#define FETDRV_SCK_PORT GPIO_PRT7
#define FETDRV_SCK_PORT_NUM 7U
#define FETDRV_SCK_PIN 2U
#define FETDRV_SCK_NUM 2U
#define FETDRV_SCK_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define FETDRV_SCK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_2_HSIOM
	#define ioss_0_port_7_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_SCK_HSIOM ioss_0_port_7_pin_2_HSIOM
#define FETDRV_SCK_IRQ ioss_interrupts_gpio_7_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_SCK_HAL_PORT_PIN P7_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_SCK P7_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_SCK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_SCK_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_SCK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define FETDRV_CS_ENABLED 1U
#define FETDRV_CS_PORT GPIO_PRT7
#define FETDRV_CS_PORT_NUM 7U
#define FETDRV_CS_PIN 3U
#define FETDRV_CS_NUM 3U
#define FETDRV_CS_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define FETDRV_CS_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_3_HSIOM
	#define ioss_0_port_7_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_CS_HSIOM ioss_0_port_7_pin_3_HSIOM
#define FETDRV_CS_IRQ ioss_interrupts_gpio_7_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_CS_HAL_PORT_PIN P7_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_CS P7_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_CS_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_CS_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_CS_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define FETDRV_PWM_BL_ENABLED 1U
#define FETDRV_PWM_BL_PORT GPIO_PRT8
#define FETDRV_PWM_BL_PORT_NUM 8U
#define FETDRV_PWM_BL_PIN 0U
#define FETDRV_PWM_BL_NUM 0U
#define FETDRV_PWM_BL_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define FETDRV_PWM_BL_INIT_DRIVESTATE 0
#ifndef ioss_0_port_8_pin_0_HSIOM
	#define ioss_0_port_8_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_PWM_BL_HSIOM ioss_0_port_8_pin_0_HSIOM
#define FETDRV_PWM_BL_IRQ ioss_interrupts_gpio_8_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_BL_HAL_PORT_PIN P8_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_BL P8_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_BL_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_BL_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_BL_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define FETDRV_PWM_BH_ENABLED 1U
#define FETDRV_PWM_BH_PORT GPIO_PRT8
#define FETDRV_PWM_BH_PORT_NUM 8U
#define FETDRV_PWM_BH_PIN 1U
#define FETDRV_PWM_BH_NUM 1U
#define FETDRV_PWM_BH_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define FETDRV_PWM_BH_INIT_DRIVESTATE 0
#ifndef ioss_0_port_8_pin_1_HSIOM
	#define ioss_0_port_8_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_PWM_BH_HSIOM ioss_0_port_8_pin_1_HSIOM
#define FETDRV_PWM_BH_IRQ ioss_interrupts_gpio_8_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_BH_HAL_PORT_PIN P8_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_BH P8_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_BH_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_BH_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_PWM_BH_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define FETDRV_ENABLE_ENABLED 1U
#define FETDRV_ENABLE_PORT GPIO_PRT9
#define FETDRV_ENABLE_PORT_NUM 9U
#define FETDRV_ENABLE_PIN 0U
#define FETDRV_ENABLE_NUM 0U
#define FETDRV_ENABLE_DRIVEMODE CY_GPIO_DM_STRONG
#define FETDRV_ENABLE_INIT_DRIVESTATE 0
#ifndef ioss_0_port_9_pin_0_HSIOM
	#define ioss_0_port_9_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_ENABLE_HSIOM ioss_0_port_9_pin_0_HSIOM
#define FETDRV_ENABLE_IRQ ioss_interrupts_gpio_9_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_ENABLE_HAL_PORT_PIN P9_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_ENABLE P9_0
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_ENABLE_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_ENABLE_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_ENABLE_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define FETDRV_nFAULT_ENABLED 1U
#define FETDRV_nFAULT_PORT GPIO_PRT9
#define FETDRV_nFAULT_PORT_NUM 9U
#define FETDRV_nFAULT_PIN 1U
#define FETDRV_nFAULT_NUM 1U
#define FETDRV_nFAULT_DRIVEMODE CY_GPIO_DM_PULLUP_DOWN
#define FETDRV_nFAULT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_1_HSIOM
	#define ioss_0_port_9_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_nFAULT_HSIOM ioss_0_port_9_pin_1_HSIOM
#define FETDRV_nFAULT_IRQ ioss_interrupts_gpio_9_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_nFAULT_HAL_PORT_PIN P9_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_nFAULT P9_1
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_nFAULT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_nFAULT_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_nFAULT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUPDOWN
#endif //defined (CY_USING_HAL)
#define FETDRV_VREF_ENABLED 1U
#define FETDRV_VREF_PORT GPIO_PRT9
#define FETDRV_VREF_PORT_NUM 9U
#define FETDRV_VREF_PIN 2U
#define FETDRV_VREF_NUM 2U
#define FETDRV_VREF_DRIVEMODE CY_GPIO_DM_ANALOG
#define FETDRV_VREF_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_2_HSIOM
	#define ioss_0_port_9_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_VREF_HSIOM ioss_0_port_9_pin_2_HSIOM
#define FETDRV_VREF_IRQ ioss_interrupts_gpio_9_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_VREF_HAL_PORT_PIN P9_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_VREF P9_2
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_VREF_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_VREF_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_VREF_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_ANALOG
#endif //defined (CY_USING_HAL)
#define FETDRV_BRAKE_ENABLED 1U
#define FETDRV_BRAKE_PORT GPIO_PRT9
#define FETDRV_BRAKE_PORT_NUM 9U
#define FETDRV_BRAKE_PIN 3U
#define FETDRV_BRAKE_NUM 3U
#define FETDRV_BRAKE_DRIVEMODE CY_GPIO_DM_STRONG
#define FETDRV_BRAKE_INIT_DRIVESTATE 0
#ifndef ioss_0_port_9_pin_3_HSIOM
	#define ioss_0_port_9_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_BRAKE_HSIOM ioss_0_port_9_pin_3_HSIOM
#define FETDRV_BRAKE_IRQ ioss_interrupts_gpio_9_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_BRAKE_HAL_PORT_PIN P9_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_BRAKE P9_3
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_BRAKE_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_BRAKE_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_BRAKE_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define FETDRV_GAIN_AZ_ENABLED 1U
#define FETDRV_GAIN_AZ_PORT GPIO_PRT9
#define FETDRV_GAIN_AZ_PORT_NUM 9U
#define FETDRV_GAIN_AZ_PIN 4U
#define FETDRV_GAIN_AZ_NUM 4U
#define FETDRV_GAIN_AZ_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define FETDRV_GAIN_AZ_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_4_HSIOM
	#define ioss_0_port_9_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define FETDRV_GAIN_AZ_HSIOM ioss_0_port_9_pin_4_HSIOM
#define FETDRV_GAIN_AZ_IRQ ioss_interrupts_gpio_9_IRQn
#if defined (CY_USING_HAL)
	#define FETDRV_GAIN_AZ_HAL_PORT_PIN P9_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_GAIN_AZ P9_4
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_GAIN_AZ_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_GAIN_AZ_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define FETDRV_GAIN_AZ_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif //defined (CY_USING_HAL)
#define CANFD_nFAULT_ENABLED 1U
#define CANFD_nFAULT_PORT GPIO_PRT9
#define CANFD_nFAULT_PORT_NUM 9U
#define CANFD_nFAULT_PIN 5U
#define CANFD_nFAULT_NUM 5U
#define CANFD_nFAULT_DRIVEMODE CY_GPIO_DM_HIGHZ
#define CANFD_nFAULT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_5_HSIOM
	#define ioss_0_port_9_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define CANFD_nFAULT_HSIOM ioss_0_port_9_pin_5_HSIOM
#define CANFD_nFAULT_IRQ ioss_interrupts_gpio_9_IRQn
#if defined (CY_USING_HAL)
	#define CANFD_nFAULT_HAL_PORT_PIN P9_5
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_nFAULT P9_5
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_nFAULT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_nFAULT_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	#define CANFD_nFAULT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif //defined (CY_USING_HAL)
#define SMART_IO_ENABLED 1U
#define SMART_IO_HW SMARTIO_PRT9

extern const cy_stc_gpio_pin_config_t ENCODER_QOAD_B1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENCODER_QOAD_B1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ENCODER_QOAD_A1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENCODER_QOAD_A1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ENCODER_QOAD_I1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENCODER_QOAD_I1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ENCODER_QOAD_I2_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENCODER_QOAD_I2_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ENCODER_QOAD_B2_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENCODER_QOAD_B2_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ENCODER_QOAD_A2_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENCODER_QOAD_A2_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t NC_0_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t NC_0_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ADC_ISENSE_C_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ADC_ISENSE_C_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ADC_ISENSE_B_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ADC_ISENSE_B_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ADC_ISENSE_A_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ADC_ISENSE_A_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ADC_VBUS_SENSE_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ADC_VBUS_SENSE_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ADC_TEMP1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ADC_TEMP1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t GPIO1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t GPIO1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t GPIO0_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t GPIO0_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t PWM_AL_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t PWM_AL_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t PWM_AH_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t PWM_AH_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t NC_4_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t NC_4_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ECO_IN_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ECO_IN_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ECO_OUT_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ECO_OUT_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ENC_SSC_DO_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENC_SSC_DO_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ENC_SSC_DI_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENC_SSC_DI_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ENC_SSC_SCK_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENC_SSC_SCK_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ENC_SSC_CS1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENC_SSC_CS1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t ENC_SSC_CS2_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENC_SSC_CS2_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t CANF_SILENT_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CANF_SILENT_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t LED0_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t LED0_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t LED1_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t LED1_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t DEBUG_UART_RX_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t DEBUG_UART_RX_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t DEBUG_UART_TX_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t DEBUG_UART_TX_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t CANFD_RX_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CANFD_RX_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t CANFD_TX_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CANFD_TX_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t GPIO2_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t GPIO2_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t GPIO3_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t GPIO3_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_PWM_CL_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_PWM_CL_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_PWM_CH_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_PWM_CH_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t SWO_config;
#define DEBUG_I2C_SCL_config SWO_config
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t SWO_obj;
	#define DEBUG_I2C_SCL_obj SWO_obj
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t TDI_config;
#define DEBUG_I2C_SDA_config TDI_config
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t TDI_obj;
	#define DEBUG_I2C_SDA_obj TDI_obj
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t SWDIO_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t SWDIO_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t SWDCLK_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t SWDCLK_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_MOSI_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_MOSI_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_MISO_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_MISO_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_SCK_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_SCK_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_CS_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_CS_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_PWM_BL_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_PWM_BL_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_PWM_BH_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_PWM_BH_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_ENABLE_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_ENABLE_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_nFAULT_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_nFAULT_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_VREF_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_VREF_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_BRAKE_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_BRAKE_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t FETDRV_GAIN_AZ_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t FETDRV_GAIN_AZ_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_gpio_pin_config_t CANFD_nFAULT_config;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CANFD_nFAULT_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_smartio_lutcfg_t SMART_IO_lutCfg4;
extern const cy_stc_smartio_lutcfg_t SMART_IO_lutCfg5;
extern const cy_stc_smartio_ducfg_t SMART_IO_duCfg;
extern const cy_stc_smartio_config_t SMART_IO_config;

void init_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PINS_H */
