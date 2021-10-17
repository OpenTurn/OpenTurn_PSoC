/*******************************************************************************
* File Name: cycfg_clocks.c
*
* Description:
* Clock configuration
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

#include "cycfg_clocks.h"

#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CLK_DEBUG_UART_obj = 
	{
		.type = CYHAL_RSC_CLOCK,
		.block_num = CLK_DEBUG_UART_HW,
		.channel_num = CLK_DEBUG_UART_NUM,
	};
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CLK_DEBUG_I2C_obj = 
	{
		.type = CYHAL_RSC_CLOCK,
		.block_num = CLK_DEBUG_I2C_HW,
		.channel_num = CLK_DEBUG_I2C_NUM,
	};
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CLK_CANFD_obj = 
	{
		.type = CYHAL_RSC_CLOCK,
		.block_num = CLK_CANFD_HW,
		.channel_num = CLK_CANFD_NUM,
	};
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CLK_ADC_obj = 
	{
		.type = CYHAL_RSC_CLOCK,
		.block_num = CLK_ADC_HW,
		.channel_num = CLK_ADC_NUM,
	};
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CLK_VREF_obj = 
	{
		.type = CYHAL_RSC_CLOCK,
		.block_num = CLK_VREF_HW,
		.channel_num = CLK_VREF_NUM,
	};
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CLK_PWM_obj = 
	{
		.type = CYHAL_RSC_CLOCK,
		.block_num = CLK_PWM_HW,
		.channel_num = CLK_PWM_NUM,
	};
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CLK_FETDRV_SPI_obj = 
	{
		.type = CYHAL_RSC_CLOCK,
		.block_num = CLK_FETDRV_SPI_HW,
		.channel_num = CLK_FETDRV_SPI_NUM,
	};
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CLK_ENC_SPI_obj = 
	{
		.type = CYHAL_RSC_CLOCK,
		.block_num = CLK_ENC_SPI_HW,
		.channel_num = CLK_ENC_SPI_NUM,
	};
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CLK_ENC_obj = 
	{
		.type = CYHAL_RSC_CLOCK,
		.block_num = CLK_ENC_HW,
		.channel_num = CLK_ENC_NUM,
	};
#endif //defined (CY_USING_HAL)


void init_cycfg_clocks(void)
{
	Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 0U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0U, 9U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 0U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CLK_DEBUG_UART_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 1U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 1U, 7U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 1U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CLK_DEBUG_I2C_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 2U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 2U, 0U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 2U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CLK_CANFD_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 3U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 3U, 5U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 3U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CLK_ADC_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 4U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 4U, 199U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 4U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CLK_VREF_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_8_BIT, 0U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 0U, 0U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CLK_PWM_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_8_BIT, 1U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 1U, 9U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_8_BIT, 1U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CLK_FETDRV_SPI_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_8_BIT, 2U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 2U, 3U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_8_BIT, 2U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CLK_ENC_SPI_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_8_BIT, 3U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 3U, 0U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_8_BIT, 3U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CLK_ENC_obj);
#endif //defined (CY_USING_HAL)
}
