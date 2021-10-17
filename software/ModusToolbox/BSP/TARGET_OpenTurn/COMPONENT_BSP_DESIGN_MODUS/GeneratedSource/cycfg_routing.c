/*******************************************************************************
* File Name: cycfg_routing.c
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

#include "cycfg_routing.h"

#include "cy_trigmux.h"

#include "stdbool.h"

#include "cy_device_headers.h"

void init_cycfg_routing(void)
{
	Cy_TrigMux_Connect(TRIG_IN_MUX_2_HSIOM_TR_OUT0, TRIG_OUT_MUX_2_TCPWM0_TR_IN8, false, TRIGGER_TYPE_LEVEL);
	Cy_TrigMux_Connect(TRIG_IN_MUX_2_HSIOM_TR_OUT1, TRIG_OUT_MUX_2_TCPWM0_TR_IN9, false, TRIGGER_TYPE_LEVEL);
	Cy_TrigMux_Connect(TRIG_IN_MUX_3_HSIOM_TR_OUT20, TRIG_OUT_MUX_3_TCPWM0_TR_IN21, false, TRIGGER_TYPE_LEVEL);
	Cy_TrigMux_Connect(TRIG_IN_MUX_3_TCPWM0_TR_OUT0256, TRIG_OUT_MUX_3_TCPWM0_TR_IN22, false, TRIGGER_TYPE_LEVEL);
	Cy_TrigMux_Connect(TRIG_IN_MUX_3_TCPWM0_TR_OUT1256, TRIG_OUT_MUX_3_TCPWM0_TR_IN23, false, TRIGGER_TYPE_LEVEL);
	Cy_TrigMux_Connect(TRIG_IN_MUX_4_PASS_SAR0_DONE, TRIG_OUT_MUX_4_HSIOM_TR_IO_OUTPUT0, false, TRIGGER_TYPE_EDGE);
	Cy_TrigMux_Connect(TRIG_IN_MUX_9_TCPWM0_TR_OUT0256, TRIG_OUT_MUX_9_PASS_TR_SAR_IN0, false, TRIGGER_TYPE_LEVEL);
	CTBM0->CTD_SW = CTBM_V2_CTD_SW_CTDH_CA0_Msk |
		CTBM_V2_CTD_SW_CTDO_COS_Msk |
		CTBM_V2_CTD_SW_CTDS_COR_Msk;
	CTBM0->OA0_SW = CTBM_V2_OA0_SW_OA0M_A81_Msk |
		CTBM_V2_OA0_SW_OA0O_D81_Msk;
	CTBM0->OA1_SW = CTBM_V2_OA1_SW_OA1M_A82_Msk |
		CTBM_V2_OA1_SW_OA1P_A73_Msk;
	SAR0->MUX_SWITCH_SQ_CTRL = SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P1_Msk |
		SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P2_Msk |
		SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P3_Msk |
		SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P4_Msk;
	SAR0->MUX_SWITCH0 = SAR_V2_MUX_SWITCH0_MUX_FW_P1_VPLUS_Msk |
		SAR_V2_MUX_SWITCH0_MUX_FW_P2_VPLUS_Msk |
		SAR_V2_MUX_SWITCH0_MUX_FW_P3_VPLUS_Msk |
		SAR_V2_MUX_SWITCH0_MUX_FW_P4_VPLUS_Msk;
	SAR1->MUX_SWITCH_SQ_CTRL = SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P1_Msk |
		SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P2_Msk |
		SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P3_Msk |
		SAR_V2_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_P5_Msk;
	SAR1->MUX_SWITCH0 = SAR_V2_MUX_SWITCH0_MUX_FW_P1_VPLUS_Msk |
		SAR_V2_MUX_SWITCH0_MUX_FW_P2_VPLUS_Msk |
		SAR_V2_MUX_SWITCH0_MUX_FW_P3_VPLUS_Msk |
		SAR_V2_MUX_SWITCH0_MUX_FW_P5_VPLUS_Msk;
	PASS->SAR_TR_OUT_CTRL = (PASS->SAR_TR_OUT_CTRL & ~PASS_V2_SAR_TR_OUT_CTRL_SAR0_TR_OUT_SEL_Msk) | (0x0 << PASS_V2_SAR_TR_OUT_CTRL_SAR0_TR_OUT_SEL_Pos);
	CTBM0->CTB_CTRL |= CTBM_V2_CTB_CTRL_ENABLED_Msk;
	SAR0->CTRL |= SAR_V2_CTRL_ENABLED_Msk;
	SAR1->CTRL |= SAR_V2_CTRL_ENABLED_Msk;
}
