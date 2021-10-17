/*******************************************************************************
* File Name: cycfg_dmas.h
*
* Description:
* DMA configuration
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

#if !defined(CYCFG_DMAS_H)
#define CYCFG_DMAS_H

#include "cycfg_notices.h"
#include "cy_dma.h"
#if defined (CY_USING_HAL)
	#include "cyhal_hwmgr.h"
#endif //defined (CY_USING_HAL)

#if defined(__cplusplus)
extern "C" {
#endif

#define ENCODER_CRC_TX_ENABLED 1U
#define ENCODER_CRC_TX_HW DW0
#define ENCODER_CRC_TX_CHANNEL 0U
#define ENCODER_CRC_TX_IRQ cpuss_interrupts_dw0_0_IRQn
#define ENCODER_CRC_RX_ENABLED 1U
#define ENCODER_CRC_RX_HW DW0
#define ENCODER_CRC_RX_CHANNEL 19U
#define ENCODER_CRC_RX_IRQ cpuss_interrupts_dw0_19_IRQn

extern const cy_stc_dma_descriptor_config_t ENCODER_CRC_TX_Descriptor_0_config;
extern const cy_stc_dma_descriptor_config_t ENCODER_CRC_TX_Descriptor_1_config;
extern cy_stc_dma_descriptor_t ENCODER_CRC_TX_Descriptor_0;
extern cy_stc_dma_descriptor_t ENCODER_CRC_TX_Descriptor_1;
extern const cy_stc_dma_channel_config_t ENCODER_CRC_TX_channelConfig;
extern const cy_stc_dma_crc_config_t ENCODER_CRC_TX_crcConfig;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENCODER_CRC_TX_obj;
#endif //defined (CY_USING_HAL)
extern const cy_stc_dma_descriptor_config_t ENCODER_CRC_RX_Descriptor_0_config;
extern const cy_stc_dma_descriptor_config_t ENCODER_CRC_RX_Descriptor_1_config;
extern const cy_stc_dma_descriptor_config_t ENCODER_CRC_RX_Descriptor_2_config;
extern const cy_stc_dma_descriptor_config_t ENCODER_CRC_RX_Descriptor_3_config;
extern const cy_stc_dma_descriptor_config_t ENCODER_CRC_RX_Descriptor_4_config;
extern cy_stc_dma_descriptor_t ENCODER_CRC_RX_Descriptor_0;
extern cy_stc_dma_descriptor_t ENCODER_CRC_RX_Descriptor_1;
extern cy_stc_dma_descriptor_t ENCODER_CRC_RX_Descriptor_2;
extern cy_stc_dma_descriptor_t ENCODER_CRC_RX_Descriptor_3;
extern cy_stc_dma_descriptor_t ENCODER_CRC_RX_Descriptor_4;
extern const cy_stc_dma_channel_config_t ENCODER_CRC_RX_channelConfig;
extern const cy_stc_dma_crc_config_t ENCODER_CRC_RX_crcConfig;
#if defined (CY_USING_HAL)
	extern const cyhal_resource_inst_t ENCODER_CRC_RX_obj;
#endif //defined (CY_USING_HAL)

void init_cycfg_dmas(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_DMAS_H */
