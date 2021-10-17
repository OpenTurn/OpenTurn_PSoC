/*******************************************************************************
* File Name: cycfg_clocks.h
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

#if !defined(CYCFG_CLOCKS_H)
#define CYCFG_CLOCKS_H

#include "cycfg_notices.h"
#include "cy_sysclk.h"
#if defined (CY_USING_HAL)
	#include "cyhal_hwmgr.h"
#endif //defined (CY_USING_HAL)

#if defined(__cplusplus)
extern "C" {
#endif

#define CLK_DEBUG_UART_ENABLED 1U
#define CLK_DEBUG_UART_HW CY_SYSCLK_DIV_16_BIT
#define CLK_DEBUG_UART_NUM 0U
#define CLK_DEBUG_I2C_ENABLED 1U
#define CLK_DEBUG_I2C_HW CY_SYSCLK_DIV_16_BIT
#define CLK_DEBUG_I2C_NUM 1U
#define CLK_CANFD_ENABLED 1U
#define CLK_CANFD_HW CY_SYSCLK_DIV_16_BIT
#define CLK_CANFD_NUM 2U
#define CLK_ADC_ENABLED 1U
#define CLK_ADC_HW CY_SYSCLK_DIV_16_BIT
#define CLK_ADC_NUM 3U
#define CLK_VREF_ENABLED 1U
#define CLK_VREF_HW CY_SYSCLK_DIV_16_BIT
#define CLK_VREF_NUM 4U
#define CLK_PWM_ENABLED 1U
#define CLK_PWM_HW CY_SYSCLK_DIV_8_BIT
#define CLK_PWM_NUM 0U
#define CLK_FETDRV_SPI_ENABLED 1U
#define CLK_FETDRV_SPI_HW CY_SYSCLK_DIV_8_BIT
#define CLK_FETDRV_SPI_NUM 1U
#define CLK_ENC_SPI_ENABLED 1U
#define CLK_ENC_SPI_HW CY_SYSCLK_DIV_8_BIT
#define CLK_ENC_SPI_NUM 2U
#define CLK_ENC_ENABLED 1U
#define CLK_ENC_HW CY_SYSCLK_DIV_8_BIT
#define CLK_ENC_NUM 3U

#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CLK_DEBUG_UART_obj;
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CLK_DEBUG_I2C_obj;
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CLK_CANFD_obj;
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CLK_ADC_obj;
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CLK_VREF_obj;
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CLK_PWM_obj;
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CLK_FETDRV_SPI_obj;
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CLK_ENC_SPI_obj;
#endif //defined (CY_USING_HAL)
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t CLK_ENC_obj;
#endif //defined (CY_USING_HAL)

void init_cycfg_clocks(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_CLOCKS_H */
