/*******************************************************************************
* File Name: cycfg_pins.c
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

#include "cycfg_pins.h"

const cy_stc_gpio_pin_config_t ENCODER_QOAD_B1_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = ENCODER_QOAD_B1_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENCODER_QOAD_B1_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ENCODER_QOAD_B1_PORT_NUM,
		.channel_num = ENCODER_QOAD_B1_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ENCODER_QOAD_A1_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = ENCODER_QOAD_A1_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENCODER_QOAD_A1_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ENCODER_QOAD_A1_PORT_NUM,
		.channel_num = ENCODER_QOAD_A1_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ENCODER_QOAD_I1_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = ENCODER_QOAD_I1_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENCODER_QOAD_I1_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ENCODER_QOAD_I1_PORT_NUM,
		.channel_num = ENCODER_QOAD_I1_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ENCODER_QOAD_I2_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = ENCODER_QOAD_I2_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENCODER_QOAD_I2_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ENCODER_QOAD_I2_PORT_NUM,
		.channel_num = ENCODER_QOAD_I2_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ENCODER_QOAD_B2_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = ENCODER_QOAD_B2_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENCODER_QOAD_B2_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ENCODER_QOAD_B2_PORT_NUM,
		.channel_num = ENCODER_QOAD_B2_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ENCODER_QOAD_A2_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = ENCODER_QOAD_A2_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENCODER_QOAD_A2_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ENCODER_QOAD_A2_PORT_NUM,
		.channel_num = ENCODER_QOAD_A2_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t NC_0_config = 
{
	.outVal = 0,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = NC_0_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t NC_0_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = NC_0_PORT_NUM,
		.channel_num = NC_0_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ADC_ISENSE_C_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = ADC_ISENSE_C_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ADC_ISENSE_C_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ADC_ISENSE_C_PORT_NUM,
		.channel_num = ADC_ISENSE_C_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ADC_ISENSE_B_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = ADC_ISENSE_B_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ADC_ISENSE_B_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ADC_ISENSE_B_PORT_NUM,
		.channel_num = ADC_ISENSE_B_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ADC_ISENSE_A_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = ADC_ISENSE_A_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ADC_ISENSE_A_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ADC_ISENSE_A_PORT_NUM,
		.channel_num = ADC_ISENSE_A_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ADC_VBUS_SENSE_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = ADC_VBUS_SENSE_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ADC_VBUS_SENSE_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ADC_VBUS_SENSE_PORT_NUM,
		.channel_num = ADC_VBUS_SENSE_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ADC_TEMP1_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = ADC_TEMP1_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ADC_TEMP1_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ADC_TEMP1_PORT_NUM,
		.channel_num = ADC_TEMP1_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t GPIO1_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = GPIO1_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t GPIO1_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = GPIO1_PORT_NUM,
		.channel_num = GPIO1_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t GPIO0_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = GPIO0_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t GPIO0_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = GPIO0_PORT_NUM,
		.channel_num = GPIO0_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t PWM_AL_config = 
{
	.outVal = 0,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = PWM_AL_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t PWM_AL_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = PWM_AL_PORT_NUM,
		.channel_num = PWM_AL_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t PWM_AH_config = 
{
	.outVal = 0,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = PWM_AH_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t PWM_AH_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = PWM_AH_PORT_NUM,
		.channel_num = PWM_AH_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t NC_4_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = NC_4_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t NC_4_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = NC_4_PORT_NUM,
		.channel_num = NC_4_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ECO_IN_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = ECO_IN_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ECO_IN_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ECO_IN_PORT_NUM,
		.channel_num = ECO_IN_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ECO_OUT_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = ECO_OUT_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ECO_OUT_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ECO_OUT_PORT_NUM,
		.channel_num = ECO_OUT_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ENC_SSC_DO_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = ENC_SSC_DO_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENC_SSC_DO_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ENC_SSC_DO_PORT_NUM,
		.channel_num = ENC_SSC_DO_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ENC_SSC_DI_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = ENC_SSC_DI_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENC_SSC_DI_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ENC_SSC_DI_PORT_NUM,
		.channel_num = ENC_SSC_DI_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ENC_SSC_SCK_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = ENC_SSC_SCK_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENC_SSC_SCK_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ENC_SSC_SCK_PORT_NUM,
		.channel_num = ENC_SSC_SCK_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ENC_SSC_CS1_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = ENC_SSC_CS1_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENC_SSC_CS1_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ENC_SSC_CS1_PORT_NUM,
		.channel_num = ENC_SSC_CS1_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t ENC_SSC_CS2_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = ENC_SSC_CS2_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENC_SSC_CS2_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = ENC_SSC_CS2_PORT_NUM,
		.channel_num = ENC_SSC_CS2_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t CANF_SILENT_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG,
	.hsiom = CANF_SILENT_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CANF_SILENT_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = CANF_SILENT_PORT_NUM,
		.channel_num = CANF_SILENT_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t LED0_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG,
	.hsiom = LED0_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t LED0_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = LED0_PORT_NUM,
		.channel_num = LED0_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t LED1_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG,
	.hsiom = LED1_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t LED1_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = LED1_PORT_NUM,
		.channel_num = LED1_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t DEBUG_UART_RX_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = DEBUG_UART_RX_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t DEBUG_UART_RX_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = DEBUG_UART_RX_PORT_NUM,
		.channel_num = DEBUG_UART_RX_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t DEBUG_UART_TX_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = DEBUG_UART_TX_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t DEBUG_UART_TX_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = DEBUG_UART_TX_PORT_NUM,
		.channel_num = DEBUG_UART_TX_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t CANFD_RX_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_PULLUP,
	.hsiom = CANFD_RX_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CANFD_RX_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = CANFD_RX_PORT_NUM,
		.channel_num = CANFD_RX_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t CANFD_TX_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG,
	.hsiom = CANFD_TX_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CANFD_TX_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = CANFD_TX_PORT_NUM,
		.channel_num = CANFD_TX_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t GPIO2_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = GPIO2_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t GPIO2_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = GPIO2_PORT_NUM,
		.channel_num = GPIO2_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t GPIO3_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = GPIO3_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t GPIO3_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = GPIO3_PORT_NUM,
		.channel_num = GPIO3_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_PWM_CL_config = 
{
	.outVal = 0,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = FETDRV_PWM_CL_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_PWM_CL_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_PWM_CL_PORT_NUM,
		.channel_num = FETDRV_PWM_CL_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_PWM_CH_config = 
{
	.outVal = 0,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = FETDRV_PWM_CH_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_PWM_CH_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_PWM_CH_PORT_NUM,
		.channel_num = FETDRV_PWM_CH_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t SWO_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = SWO_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t SWO_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = SWO_PORT_NUM,
		.channel_num = SWO_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t TDI_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_OD_DRIVESLOW,
	.hsiom = TDI_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t TDI_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = TDI_PORT_NUM,
		.channel_num = TDI_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t SWDIO_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_PULLUP,
	.hsiom = SWDIO_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t SWDIO_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = SWDIO_PORT_NUM,
		.channel_num = SWDIO_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t SWDCLK_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_PULLDOWN,
	.hsiom = SWDCLK_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t SWDCLK_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = SWDCLK_PORT_NUM,
		.channel_num = SWDCLK_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_MOSI_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = FETDRV_MOSI_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_MOSI_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_MOSI_PORT_NUM,
		.channel_num = FETDRV_MOSI_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_MISO_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = FETDRV_MISO_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_MISO_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_MISO_PORT_NUM,
		.channel_num = FETDRV_MISO_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_SCK_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = FETDRV_SCK_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_SCK_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_SCK_PORT_NUM,
		.channel_num = FETDRV_SCK_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_CS_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = FETDRV_CS_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_CS_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_CS_PORT_NUM,
		.channel_num = FETDRV_CS_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_PWM_BL_config = 
{
	.outVal = 0,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = FETDRV_PWM_BL_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_PWM_BL_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_PWM_BL_PORT_NUM,
		.channel_num = FETDRV_PWM_BL_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_PWM_BH_config = 
{
	.outVal = 0,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = FETDRV_PWM_BH_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_PWM_BH_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_PWM_BH_PORT_NUM,
		.channel_num = FETDRV_PWM_BH_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_ENABLE_config = 
{
	.outVal = 0,
	.driveMode = CY_GPIO_DM_STRONG,
	.hsiom = FETDRV_ENABLE_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_ENABLE_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_ENABLE_PORT_NUM,
		.channel_num = FETDRV_ENABLE_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_nFAULT_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_PULLUP_DOWN,
	.hsiom = FETDRV_nFAULT_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_nFAULT_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_nFAULT_PORT_NUM,
		.channel_num = FETDRV_nFAULT_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_VREF_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_ANALOG,
	.hsiom = FETDRV_VREF_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_VREF_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_VREF_PORT_NUM,
		.channel_num = FETDRV_VREF_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_BRAKE_config = 
{
	.outVal = 0,
	.driveMode = CY_GPIO_DM_STRONG,
	.hsiom = FETDRV_BRAKE_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_BRAKE_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_BRAKE_PORT_NUM,
		.channel_num = FETDRV_BRAKE_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t FETDRV_GAIN_AZ_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_STRONG_IN_OFF,
	.hsiom = FETDRV_GAIN_AZ_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_GAIN_AZ_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = FETDRV_GAIN_AZ_PORT_NUM,
		.channel_num = FETDRV_GAIN_AZ_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_gpio_pin_config_t CANFD_nFAULT_config = 
{
	.outVal = 1,
	.driveMode = CY_GPIO_DM_HIGHZ,
	.hsiom = CANFD_nFAULT_HSIOM,
	.intEdge = CY_GPIO_INTR_DISABLE,
	.intMask = 0UL,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
	.driveSel = CY_GPIO_DRIVE_1_2,
	.vregEn = 0UL,
	.ibufMode = 0UL,
	.vtripSel = 0UL,
	.vrefSel = 0UL,
	.vohSel = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CANFD_nFAULT_obj = 
	{
		.type = CYHAL_RSC_GPIO,
		.block_num = CANFD_nFAULT_PORT_NUM,
		.channel_num = CANFD_nFAULT_PIN,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_smartio_lutcfg_t SMART_IO_lutCfg4 = 
{
	.tr0 = CY_SMARTIO_LUTTR_DU_OUT,
	.tr1 = CY_SMARTIO_LUTTR_CHIP4,
	.tr2 = CY_SMARTIO_LUTTR_CHIP4,
	.opcode = CY_SMARTIO_LUTOPC_COMB,
	.lutMap = 128,
};
const cy_stc_smartio_lutcfg_t SMART_IO_lutCfg5 = 
{
	.tr0 = CY_SMARTIO_LUTTR_CHIP4,
	.tr1 = CY_SMARTIO_LUTTR_CHIP4,
	.tr2 = CY_SMARTIO_LUTTR_CHIP4,
	.opcode = CY_SMARTIO_LUTOPC_GATED_TR2,
	.lutMap = 16,
};
const cy_stc_smartio_ducfg_t SMART_IO_duCfg = 
{
	.tr0 = CY_SMARTIO_DUTR_ZERO,
	.tr1 = CY_SMARTIO_DUTR_LUT5_OUT,
	.tr2 = CY_SMARTIO_DUTR_ZERO,
	.data0 = CY_SMARTIO_DUDATA_DATAREG,
	.data1 = CY_SMARTIO_DUDATA_ZERO,
	.opcode = CY_SMARTIO_DUOPC_DECR_WRAP,
	.size = CY_SMARTIO_DUSIZE_8,
	.dataReg = 2,
};
const cy_stc_smartio_config_t SMART_IO_config = 
{
	.clkSrc = CY_SMARTIO_CLK_DIVACT,
	.bypassMask = CY_SMARTIO_CHANNEL0|CY_SMARTIO_CHANNEL1|CY_SMARTIO_CHANNEL2|CY_SMARTIO_CHANNEL3|0u|CY_SMARTIO_CHANNEL5|0u|0u,
	.ioSyncEn = 0u|0u|0u|0u|0u|0u|0u|0u,
	.chipSyncEn = 0u|0u|0u|0u|0u|0u|0u|0u,
	.lutCfg0 = NULL,
	.lutCfg1 = NULL,
	.lutCfg2 = NULL,
	.lutCfg3 = NULL,
	.lutCfg4 = &SMART_IO_lutCfg4,
	.lutCfg5 = &SMART_IO_lutCfg5,
	.lutCfg6 = NULL,
	.lutCfg7 = NULL,
	.duCfg = &SMART_IO_duCfg,
	.hldOvr = false,
};


void init_cycfg_pins(void)
{
	Cy_GPIO_Pin_Init(ENCODER_QOAD_B1_PORT, ENCODER_QOAD_B1_PIN, &ENCODER_QOAD_B1_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENCODER_QOAD_B1_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ENCODER_QOAD_A1_PORT, ENCODER_QOAD_A1_PIN, &ENCODER_QOAD_A1_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENCODER_QOAD_A1_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ENCODER_QOAD_I1_PORT, ENCODER_QOAD_I1_PIN, &ENCODER_QOAD_I1_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENCODER_QOAD_I1_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ENCODER_QOAD_I2_PORT, ENCODER_QOAD_I2_PIN, &ENCODER_QOAD_I2_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENCODER_QOAD_I2_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ENCODER_QOAD_B2_PORT, ENCODER_QOAD_B2_PIN, &ENCODER_QOAD_B2_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENCODER_QOAD_B2_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ENCODER_QOAD_A2_PORT, ENCODER_QOAD_A2_PIN, &ENCODER_QOAD_A2_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENCODER_QOAD_A2_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(NC_0_PORT, NC_0_PIN, &NC_0_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&NC_0_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ADC_ISENSE_C_PORT, ADC_ISENSE_C_PIN, &ADC_ISENSE_C_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ADC_ISENSE_C_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ADC_ISENSE_B_PORT, ADC_ISENSE_B_PIN, &ADC_ISENSE_B_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ADC_ISENSE_B_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ADC_ISENSE_A_PORT, ADC_ISENSE_A_PIN, &ADC_ISENSE_A_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ADC_ISENSE_A_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ADC_VBUS_SENSE_PORT, ADC_VBUS_SENSE_PIN, &ADC_VBUS_SENSE_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ADC_VBUS_SENSE_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ADC_TEMP1_PORT, ADC_TEMP1_PIN, &ADC_TEMP1_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ADC_TEMP1_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(GPIO1_PORT, GPIO1_PIN, &GPIO1_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&GPIO1_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(GPIO0_PORT, GPIO0_PIN, &GPIO0_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&GPIO0_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(PWM_AL_PORT, PWM_AL_PIN, &PWM_AL_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&PWM_AL_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(PWM_AH_PORT, PWM_AH_PIN, &PWM_AH_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&PWM_AH_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(NC_4_PORT, NC_4_PIN, &NC_4_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&NC_4_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ECO_IN_PORT, ECO_IN_PIN, &ECO_IN_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ECO_IN_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ECO_OUT_PORT, ECO_OUT_PIN, &ECO_OUT_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ECO_OUT_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ENC_SSC_DO_PORT, ENC_SSC_DO_PIN, &ENC_SSC_DO_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENC_SSC_DO_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ENC_SSC_DI_PORT, ENC_SSC_DI_PIN, &ENC_SSC_DI_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENC_SSC_DI_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ENC_SSC_SCK_PORT, ENC_SSC_SCK_PIN, &ENC_SSC_SCK_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENC_SSC_SCK_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ENC_SSC_CS1_PORT, ENC_SSC_CS1_PIN, &ENC_SSC_CS1_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENC_SSC_CS1_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(ENC_SSC_CS2_PORT, ENC_SSC_CS2_PIN, &ENC_SSC_CS2_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENC_SSC_CS2_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(CANF_SILENT_PORT, CANF_SILENT_PIN, &CANF_SILENT_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CANF_SILENT_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(LED0_PORT, LED0_PIN, &LED0_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&LED0_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(LED1_PORT, LED1_PIN, &LED1_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&LED1_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(DEBUG_UART_RX_PORT, DEBUG_UART_RX_PIN, &DEBUG_UART_RX_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&DEBUG_UART_RX_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(DEBUG_UART_TX_PORT, DEBUG_UART_TX_PIN, &DEBUG_UART_TX_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&DEBUG_UART_TX_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(CANFD_RX_PORT, CANFD_RX_PIN, &CANFD_RX_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CANFD_RX_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(CANFD_TX_PORT, CANFD_TX_PIN, &CANFD_TX_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CANFD_TX_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(GPIO2_PORT, GPIO2_PIN, &GPIO2_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&GPIO2_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(GPIO3_PORT, GPIO3_PIN, &GPIO3_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&GPIO3_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_PWM_CL_PORT, FETDRV_PWM_CL_PIN, &FETDRV_PWM_CL_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_PWM_CL_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_PWM_CH_PORT, FETDRV_PWM_CH_PIN, &FETDRV_PWM_CH_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_PWM_CH_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(SWO_PORT, SWO_PIN, &SWO_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&SWO_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(TDI_PORT, TDI_PIN, &TDI_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&TDI_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(SWDIO_PORT, SWDIO_PIN, &SWDIO_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&SWDIO_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(SWDCLK_PORT, SWDCLK_PIN, &SWDCLK_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&SWDCLK_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_MOSI_PORT, FETDRV_MOSI_PIN, &FETDRV_MOSI_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_MOSI_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_MISO_PORT, FETDRV_MISO_PIN, &FETDRV_MISO_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_MISO_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_SCK_PORT, FETDRV_SCK_PIN, &FETDRV_SCK_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_SCK_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_CS_PORT, FETDRV_CS_PIN, &FETDRV_CS_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_CS_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_PWM_BL_PORT, FETDRV_PWM_BL_PIN, &FETDRV_PWM_BL_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_PWM_BL_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_PWM_BH_PORT, FETDRV_PWM_BH_PIN, &FETDRV_PWM_BH_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_PWM_BH_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_ENABLE_PORT, FETDRV_ENABLE_PIN, &FETDRV_ENABLE_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_ENABLE_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_nFAULT_PORT, FETDRV_nFAULT_PIN, &FETDRV_nFAULT_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_nFAULT_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_VREF_PORT, FETDRV_VREF_PIN, &FETDRV_VREF_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_VREF_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_BRAKE_PORT, FETDRV_BRAKE_PIN, &FETDRV_BRAKE_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_BRAKE_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(FETDRV_GAIN_AZ_PORT, FETDRV_GAIN_AZ_PIN, &FETDRV_GAIN_AZ_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_GAIN_AZ_obj);
#endif //defined (CY_USING_HAL)

	Cy_GPIO_Pin_Init(CANFD_nFAULT_PORT, CANFD_nFAULT_PIN, &CANFD_nFAULT_config);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CANFD_nFAULT_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_SMARTIO9_CLOCK, CY_SYSCLK_DIV_8_BIT, 0U);
}
