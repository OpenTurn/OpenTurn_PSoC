/*******************************************************************************
* File Name: cycfg_peripherals.c
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

#include "cycfg_peripherals.h"

#define STD_ID_FILTER_0 \
{\
    .sfid2 = 0U, \
    .sfid1 = 0U, \
    .sfec = CY_CANFD_SFEC_STORE_RX_FIFO_0, \
    .sft = CY_CANFD_SFT_RANGE_SFID1_SFID2, \
 }
#define EXT_ID_FILTER_0 \
{\
    .f0_f = &CANFD_extIdFilterF0Config_0, \
    .f1_f = &CANFD_extIdFilterF1Config_0, \
 }
#define ENCODER_QUAD1_INPUT_DISABLED 0x7U
#define PWM_Timer_INPUT_DISABLED 0x7U
#define PWM_B_INPUT_DISABLED 0x7U
#define PWM_C_INPUT_DISABLED 0x7U
#define PWM_A_INPUT_DISABLED 0x7U

const cy_stc_canfd_bitrate_t CANFD_nominalBitrateConfig = 
{
	.prescaler = 2U - 1U,
	.timeSegment1 = 4U - 1U,
	.timeSegment2 = 5U - 1U,
	.syncJumpWidth = 4U - 1U,
};
const cy_stc_canfd_bitrate_t CANFD_dataBitrateConfig = 
{
	.prescaler = 2U - 1U,
	.timeSegment1 = 15U - 1U,
	.timeSegment2 = 8U - 1U,
	.syncJumpWidth = 4U - 1U,
};
const cy_stc_canfd_transceiver_delay_compensation_t CANFD_tdcConfig = 
{
	.tdcEnabled = false,
	.tdcOffset = 0U,
	.tdcFilterWindow = 0U,
};
const cy_stc_id_filter_t CANFD_stdIdFilter_0 = 
{
	.sfid2 = 0U,
	.sfid1 = 0U,
	.sfec = CY_CANFD_SFEC_STORE_RX_FIFO_0,
	.sft = CY_CANFD_SFT_RANGE_SFID1_SFID2,
};
static const cy_stc_id_filter_t CANFD_stdIdFilters[] = 
{
	[0] = STD_ID_FILTER_0,
};
static const cy_stc_canfd_sid_filter_config_t CANFD_sidFiltersConfig = 
{
	.numberOfSIDFilters = 1U,
	.sidFilter = CANFD_stdIdFilters,
};
const cy_stc_canfd_f0_t CANFD_extIdFilterF0Config_0 = 
{
	.efid1 = 0U,
	.efec = CY_CANFD_EFEC_STORE_RX_FIFO_0,
};
const cy_stc_canfd_f1_t CANFD_extIdFilterF1Config_0 = 
{
	.efid2 = 0U,
	.eft = CY_CANFD_EFT_RANGE_EFID1_EFID2,
};
const cy_stc_extid_filter_t CANFD_extIdFilter_0 = 
{
	.f0_f = &CANFD_extIdFilterF0Config_0,
	.f1_f = &CANFD_extIdFilterF1Config_0,
};
const cy_stc_extid_filter_t CANFD_extIdFilters[] = 
{
	[0] = EXT_ID_FILTER_0,
};
const cy_stc_canfd_extid_filter_config_t CANFD_extIdFiltersConfig = 
{
	.numberOfEXTIDFilters = 1U,
	.extidFilter = (cy_stc_extid_filter_t*)&CANFD_extIdFilters,
	.extIDANDMask = 536870911UL,
};
const cy_stc_canfd_global_filter_config_t CANFD_globalFilterConfig = 
{
	.nonMatchingFramesStandard = CY_CANFD_ACCEPT_IN_RXFIFO_0,
	.nonMatchingFramesExtended = CY_CANFD_ACCEPT_IN_RXFIFO_0,
	.rejectRemoteFramesStandard = false,
	.rejectRemoteFramesExtended = false,
};
const cy_en_canfd_fifo_config_t CANFD_rxFifo0Config = 
{
	.mode = CY_CANFD_FIFO_MODE_BLOCKING,
	.watermark = 0U,
	.numberOfFIFOElements = 0U,
	.topPointerLogicEnabled = false,
};
const cy_en_canfd_fifo_config_t CANFD_rxFifo1Config = 
{
	.mode = CY_CANFD_FIFO_MODE_BLOCKING,
	.watermark = 0U,
	.numberOfFIFOElements = 0U,
	.topPointerLogicEnabled = false,
};
const cy_stc_canfd_config_t CANFD_config = 
{
	.txCallback = NULL,
	.rxCallback = NULL,
	.errorCallback = NULL,
	.canFDMode = false,
	.bitrate = &CANFD_nominalBitrateConfig,
	.fastBitrate = &CANFD_dataBitrateConfig,
	.tdcConfig = &CANFD_tdcConfig,
	.sidFilterConfig = &CANFD_sidFiltersConfig,
	.extidFilterConfig = &CANFD_extIdFiltersConfig,
	.globalFilterConfig = &CANFD_globalFilterConfig,
	.rxBufferDataSize = CY_CANFD_BUFFER_DATA_SIZE_8,
	.rxFIFO1DataSize = CY_CANFD_BUFFER_DATA_SIZE_8,
	.rxFIFO0DataSize = CY_CANFD_BUFFER_DATA_SIZE_8,
	.txBufferDataSize = CY_CANFD_BUFFER_DATA_SIZE_8,
	.rxFIFO0Config = &CANFD_rxFifo0Config,
	.rxFIFO1Config = &CANFD_rxFifo1Config,
	.noOfRxBuffers = 1U,
	.noOfTxBuffers = 1U,
	.messageRAMaddress = CY_CAN0MRAM_BASE + 0U,
	.messageRAMsize = 4096U,
};
cy_stc_canfd_t0_t CANFD_T0RegisterBuffer_0 = 
{
	.id = 0U,
	.rtr = CY_CANFD_RTR_DATA_FRAME,
	.xtd = CY_CANFD_XTD_STANDARD_ID,
	.esi = CY_CANFD_ESI_ERROR_ACTIVE,
};
cy_stc_canfd_t1_t CANFD_T1RegisterBuffer_0 = 
{
	.dlc = 0U,
	.brs = false,
	.fdf = CY_CANFD_FDF_STANDARD_FRAME,
	.efc = false,
	.mm = 0U,
};
uint32_t CANFD_dataBuffer_0[] = 
{
	[CANFD_DATA_0] = 0U,
	[CANFD_DATA_1] = 0U,
};
cy_stc_canfd_tx_buffer_t CANFD_txBuffer_0 = 
{
	.t0_f = &CANFD_T0RegisterBuffer_0,
	.t1_f = &CANFD_T1RegisterBuffer_0,
	.data_area_f = CANFD_dataBuffer_0,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t CANFD_obj = 
	{
		.type = CYHAL_RSC_CAN,
		.block_num = 0U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
cy_stc_csd_context_t cy_csd_0_context = 
{
	.lockKey = CY_CSD_NONE_KEY,
};
const cy_stc_sysanalog_config_t AREF_config = 
{
	.startup = CY_SYSANALOG_STARTUP_FAST,
	.iztat = CY_SYSANALOG_IZTAT_SOURCE_SRSS,
	.vref = CY_SYSANALOG_VREF_SOURCE_LOCAL_1_2V,
	.deepSleep = CY_SYSANALOG_DEEPSLEEP_DISABLE,
};
const cy_stc_ctb_opamp_config_t OpAmp0_config = 
{
	.deepSleep = CY_CTB_DEEPSLEEP_DISABLE,
	.oaPower = CY_CTB_POWER_HIGH,
	.oaMode = CY_CTB_MODE_OPAMP10X,
	.oaPump = CY_CTB_PUMP_ENABLE,
	.oaCompEdge = CY_CTB_COMP_EDGE_BOTH,
	.oaCompLevel = CY_CTB_COMP_DSI_TRIGGER_OUT_PULSE,
	.oaCompBypass = CY_CTB_COMP_BYPASS_SYNC,
	.oaCompHyst = CY_CTB_COMP_HYST_DISABLE,
	.oaCompIntrEn = false,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t OpAmp0_obj = 
	{
		.type = CYHAL_RSC_OPAMP,
		.block_num = 0U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_ctb_opamp_config_t OpAmp1_config = 
{
	.deepSleep = CY_CTB_DEEPSLEEP_DISABLE,
	.oaPower = CY_CTB_POWER_HIGH,
	.oaMode = CY_CTB_MODE_OPAMP1X,
	.oaPump = CY_CTB_PUMP_ENABLE,
	.oaCompEdge = CY_CTB_COMP_EDGE_BOTH,
	.oaCompLevel = CY_CTB_COMP_DSI_TRIGGER_OUT_PULSE,
	.oaCompBypass = CY_CTB_COMP_BYPASS_SYNC,
	.oaCompHyst = CY_CTB_COMP_HYST_DISABLE,
	.oaCompIntrEn = false,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t OpAmp1_obj = 
	{
		.type = CYHAL_RSC_OPAMP,
		.block_num = 0U,
		.channel_num = 1U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_sar_common_config_t ADC_config = 
{
	.pwrUpDelay = 0UL,
	.scanCount = 1UL,
	.simultControl = CY_SAR_SAR0 | CY_SAR_SAR1,
	.simultTrigSource = CY_SAR_SAR0,
	.simultTrigEvent = CY_SAR_SIMULT_TRIG_EVENT_EDGE,
	.simultTrigSync = CY_SAR_SIMULT_TRIG_SYNC_SAR_CLOCK,
	.simultSamplesPerTrigger = CY_SAR_SIMULT_TRIG_SAMPLE_SINGLE,
	.simultEOSIntrSelect = CY_SAR_SIMULT_TRIG_INTR_EOS,
};
const cy_stc_sar_config_t ADC0_config = 
{
	.ctrl = (uint32_t) ADC0_CTL,
	.sampleCtrl = (uint32_t) ADC0_SAMPLE,
	.sampleTime01 = (5UL << (uint32_t)CY_SAR_SAMPLE_TIME0_SHIFT) | (2UL << (uint32_t)CY_SAR_SAMPLE_TIME1_SHIFT),
	.sampleTime23 = (2UL << (uint32_t)CY_SAR_SAMPLE_TIME2_SHIFT) | (2UL << (uint32_t)CY_SAR_SAMPLE_TIME3_SHIFT),
	.rangeThres = (3500UL << (uint32_t)CY_SAR_RANGE_HIGH_SHIFT) | (500UL << (uint32_t)CY_SAR_RANGE_LOW_SHIFT),
	.rangeCond = CY_SAR_RANGE_COND_OUTSIDE,
	.chanEn = 65543UL,
	.chanConfig = {(uint32_t) ADC0_CH0_CONFIG, (uint32_t) ADC0_CH1_CONFIG, (uint32_t) ADC0_CH2_CONFIG, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, (uint32_t) ADC0_INJ_CONFIG},
	.intrMask = CY_SAR_INTR_EOS | CY_SAR_INTR_INJ_EOC,
	.satIntrMask = 0UL,
	.rangeIntrMask = 7UL,
	.configRouting = false,
	.vrefMvValue = ADC0_VREF_MV,
	.clock = CY_SAR_CLK_PERI,
	.fifoCfgPtr = NULL,
	.trTimer = false,
	.scanCnt = false,
	.scanCntIntr = false,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ADC0_obj = 
	{
		.type = CYHAL_RSC_ADC,
		.block_num = 0,
		.channel_num = 0,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_sar_config_t ADC1_config = 
{
	.ctrl = (uint32_t) ADC1_CTL,
	.sampleCtrl = (uint32_t) ADC1_SAMPLE,
	.sampleTime01 = (5UL << (uint32_t)CY_SAR_SAMPLE_TIME0_SHIFT) | (5UL << (uint32_t)CY_SAR_SAMPLE_TIME1_SHIFT),
	.sampleTime23 = (2UL << (uint32_t)CY_SAR_SAMPLE_TIME2_SHIFT) | (2UL << (uint32_t)CY_SAR_SAMPLE_TIME3_SHIFT),
	.rangeThres = (3500UL << (uint32_t)CY_SAR_RANGE_HIGH_SHIFT) | (500UL << (uint32_t)CY_SAR_RANGE_LOW_SHIFT),
	.rangeCond = CY_SAR_RANGE_COND_OUTSIDE,
	.chanEn = 65543UL,
	.chanConfig = {(uint32_t) ADC1_CH0_CONFIG, (uint32_t) ADC1_CH1_CONFIG, (uint32_t) ADC1_CH2_CONFIG, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, (uint32_t) ADC1_INJ_CONFIG},
	.intrMask = CY_SAR_INTR_EOS | CY_SAR_INTR_INJ_EOC,
	.satIntrMask = 0UL,
	.rangeIntrMask = 7UL,
	.configRouting = false,
	.vrefMvValue = ADC1_VREF_MV,
	.clock = CY_SAR_CLK_PERI,
	.fifoCfgPtr = NULL,
	.trTimer = false,
	.scanCnt = false,
	.scanCntIntr = false,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ADC1_obj = 
	{
		.type = CYHAL_RSC_ADC,
		.block_num = 0,
		.channel_num = 0,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_scb_spi_config_t ENCODER_SSC_config = 
{
	.spiMode = CY_SCB_SPI_MASTER,
	.subMode = CY_SCB_SPI_MOTOROLA,
	.sclkMode = CY_SCB_SPI_CPHA0_CPOL0,
	.oversample = 10,
	.rxDataWidth = 16UL,
	.txDataWidth = 16UL,
	.enableMsbFirst = true,
	.enableInputFilter = false,
	.enableFreeRunSclk = false,
	.enableMisoLateSample = true,
	.enableTransferSeperation = false,
	.ssPolarity = ((CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT0) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT1) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT2) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT3)),
	.enableWakeFromSleep = false,
	.rxFifoTriggerLevel = 63UL,
	.rxFifoIntEnableMask = 0UL,
	.txFifoTriggerLevel = 63UL,
	.txFifoIntEnableMask = 0UL,
	.masterSlaveIntEnableMask = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENCODER_SSC_obj = 
	{
		.type = CYHAL_RSC_SCB,
		.block_num = 1U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_scb_uart_config_t DEBUG_UART_config = 
{
	.uartMode = CY_SCB_UART_STANDARD,
	.enableMutliProcessorMode = false,
	.smartCardRetryOnNack = false,
	.irdaInvertRx = false,
	.irdaEnableLowPowerReceiver = false,
	.oversample = 10,
	.enableMsbFirst = false,
	.dataWidth = 8UL,
	.parity = CY_SCB_UART_PARITY_NONE,
	.stopBits = CY_SCB_UART_STOP_BITS_1,
	.enableInputFilter = false,
	.breakWidth = 11UL,
	.dropOnFrameError = false,
	.dropOnParityError = false,
	.receiverAddress = 0x0UL,
	.receiverAddressMask = 0x0UL,
	.acceptAddrInFifo = false,
	.enableCts = false,
	.ctsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rtsRxFifoLevel = 0UL,
	.rtsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rxFifoTriggerLevel = 63UL,
	.rxFifoIntEnableMask = 0UL,
	.txFifoTriggerLevel = 63UL,
	.txFifoIntEnableMask = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t DEBUG_UART_obj = 
	{
		.type = CYHAL_RSC_SCB,
		.block_num = 2U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_scb_spi_config_t FETDRV_SPI_config = 
{
	.spiMode = CY_SCB_SPI_MASTER,
	.subMode = CY_SCB_SPI_MOTOROLA,
	.sclkMode = CY_SCB_SPI_CPHA1_CPOL0,
	.oversample = 10,
	.rxDataWidth = 8UL,
	.txDataWidth = 8UL,
	.enableMsbFirst = true,
	.enableInputFilter = true,
	.enableFreeRunSclk = false,
	.enableMisoLateSample = false,
	.enableTransferSeperation = false,
	.ssPolarity = ((CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT0) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT1) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT2) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT3)),
	.enableWakeFromSleep = false,
	.rxFifoTriggerLevel = 63UL,
	.rxFifoIntEnableMask = 0UL,
	.txFifoTriggerLevel = 63UL,
	.txFifoIntEnableMask = 0UL,
	.masterSlaveIntEnableMask = 0UL,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t FETDRV_SPI_obj = 
	{
		.type = CYHAL_RSC_SCB,
		.block_num = 4U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_mcwdt_config_t WATCHDOG_config = 
{
	.c0Match = 10000U,
	.c1Match = 32768U,
	.c0Mode = CY_MCWDT_MODE_NONE,
	.c1Mode = CY_MCWDT_MODE_NONE,
	.c2ToggleBit = 16U,
	.c2Mode = CY_MCWDT_MODE_NONE,
	.c0ClearOnMatch = true,
	.c1ClearOnMatch = false,
	.c0c1Cascade = false,
	.c1c2Cascade = false,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t WATCHDOG_obj = 
	{
		.type = CYHAL_RSC_LPTIMER,
		.block_num = 0U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_tcpwm_quaddec_config_t ENCODER_QUAD1_config = 
{
	.quadMode = CY_TCPWM_QUADDEC_MODE_RANGE1_CAPT,
	.resolution = CY_TCPWM_QUADDEC_X4,
	.interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
	.indexInputMode = ENCODER_QUAD1_INPUT_DISABLED & 0x3U,
	.indexInput = CY_TCPWM_INPUT_0,
	.stopInputMode = ENCODER_QUAD1_INPUT_DISABLED & 0x3U,
	.stopInput = CY_TCPWM_INPUT_0,
	.phiAInput = TCPWM0_GRP0_CNT2_COUNT_VALUE,
	.phiBInput = TCPWM0_GRP0_CNT2_START_VALUE,
	.phiAInputMode = CY_TCPWM_INPUT_LEVEL,
	.phiBInputMode = CY_TCPWM_INPUT_LEVEL,
	.trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
	.trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
	.captureOnIndex = ENCODER_QUAD1_INPUT_DISABLED & 0x3U,
	.compare0 = 16384,
	.compareBuf0 = 16384,
	.enableCompare0Swap = false,
	.compare1 = CY_TCPWM_GRP_CNT_CC0_DEFAULT,
	.compareBuf1 = CY_TCPWM_GRP_CNT_CC0_BUFF_DEFAULT,
	.enableCompare1Swap = false,
	.capture0OrIndex1InputMode = CY_TCPWM_INPUT_RISINGEDGE,
	.capture0OrIndex1Input = TCPWM0_GRP0_CNT2_CAPTURE0_VALUE,
	.period0 = 0xFFFFFFFF,
	.capture1InputMode = ENCODER_QUAD1_INPUT_DISABLED & 0x3U,
	.capture1Input = CY_TCPWM_INPUT_0,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t ENCODER_QUAD1_obj = 
	{
		.type = CYHAL_RSC_TCPWM,
		.block_num = 0U,
		.channel_num = 2U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_tcpwm_pwm_config_t PWM_Timer_config = 
{
	.pwmMode = CY_TCPWM_PWM_MODE_PWM,
	.clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
	.pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
	.deadTimeClocks = 0,
	.runMode = CY_TCPWM_PWM_CONTINUOUS,
	.period0 = 2500,
	.period1 = 32768,
	.enablePeriodSwap = false,
	.compare0 = 2490,
	.compare1 = 16384,
	.enableCompareSwap = false,
	.interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
	.invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
	.invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
	.killMode = CY_TCPWM_PWM_STOP_ON_KILL,
	.swapInputMode = PWM_Timer_INPUT_DISABLED & 0x3U,
	.swapInput = CY_TCPWM_INPUT_0,
	.reloadInputMode = PWM_Timer_INPUT_DISABLED & 0x3U,
	.reloadInput = CY_TCPWM_INPUT_0,
	.startInputMode = PWM_Timer_INPUT_DISABLED & 0x3U,
	.startInput = CY_TCPWM_INPUT_0,
	.killInputMode = PWM_Timer_INPUT_DISABLED & 0x3U,
	.killInput = CY_TCPWM_INPUT_0,
	.countInputMode = PWM_Timer_INPUT_DISABLED & 0x3U,
	.countInput = CY_TCPWM_INPUT_1,
	.swapOverflowUnderflow = false,
	.immediateKill = false,
	.tapsEnabled = 45,
	.compare2 = 2350,
	.compare3 = 16384,
	.enableCompare1Swap = false,
	.compare0MatchUp = false,
	.compare0MatchDown = false,
	.compare1MatchUp = false,
	.compare1MatchDown = false,
	.kill1InputMode = PWM_Timer_INPUT_DISABLED & 0x3U,
	.kill1Input = CY_TCPWM_INPUT_0,
	.pwmOnDisable = CY_TCPWM_PWM_OUTPUT_HIGHZ,
	.trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_OVERFLOW,
	.trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_UNDEFLOW,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t PWM_Timer_obj = 
	{
		.type = CYHAL_RSC_TCPWM,
		.block_num = 0U,
		.channel_num = 0U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_tcpwm_pwm_config_t PWM_B_config = 
{
	.pwmMode = CY_TCPWM_PWM_MODE_DEADTIME,
	.clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
	.pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
	.deadTimeClocks = 50,
	.runMode = CY_TCPWM_PWM_CONTINUOUS,
	.period0 = 2500,
	.period1 = 32768,
	.enablePeriodSwap = false,
	.compare0 = 0,
	.compare1 = 0,
	.enableCompareSwap = true,
	.interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
	.invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
	.invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
	.killMode = CY_TCPWM_PWM_STOP_ON_KILL,
	.swapInputMode = CY_TCPWM_INPUT_RISINGEDGE,
	.swapInput = TCPWM0_GRP1_CNT2_CAPTURE0_VALUE,
	.reloadInputMode = PWM_B_INPUT_DISABLED & 0x3U,
	.reloadInput = CY_TCPWM_INPUT_0,
	.startInputMode = CY_TCPWM_INPUT_RISINGEDGE,
	.startInput = TCPWM0_GRP1_CNT2_START_VALUE,
	.killInputMode = PWM_B_INPUT_DISABLED & 0x3U,
	.killInput = CY_TCPWM_INPUT_0,
	.countInputMode = PWM_B_INPUT_DISABLED & 0x3U,
	.countInput = CY_TCPWM_INPUT_1,
	.swapOverflowUnderflow = false,
	.immediateKill = true,
	.tapsEnabled = 45,
	.compare2 = 0,
	.compare3 = 0,
	.enableCompare1Swap = true,
	.compare0MatchUp = false,
	.compare0MatchDown = false,
	.compare1MatchUp = false,
	.compare1MatchDown = false,
	.kill1InputMode = PWM_B_INPUT_DISABLED & 0x3U,
	.kill1Input = CY_TCPWM_INPUT_0,
	.pwmOnDisable = CY_TCPWM_PWM_OUTPUT_LOW,
	.trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
	.trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t PWM_B_obj = 
	{
		.type = CYHAL_RSC_TCPWM,
		.block_num = 0U,
		.channel_num = 2U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_tcpwm_pwm_config_t PWM_C_config = 
{
	.pwmMode = CY_TCPWM_PWM_MODE_DEADTIME,
	.clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
	.pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
	.deadTimeClocks = 50,
	.runMode = CY_TCPWM_PWM_CONTINUOUS,
	.period0 = 2500,
	.period1 = 32768,
	.enablePeriodSwap = false,
	.compare0 = 0,
	.compare1 = 0,
	.enableCompareSwap = true,
	.interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
	.invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
	.invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
	.killMode = CY_TCPWM_PWM_STOP_ON_KILL,
	.swapInputMode = CY_TCPWM_INPUT_RISINGEDGE,
	.swapInput = TCPWM0_GRP1_CNT3_CAPTURE0_VALUE,
	.reloadInputMode = PWM_C_INPUT_DISABLED & 0x3U,
	.reloadInput = CY_TCPWM_INPUT_0,
	.startInputMode = CY_TCPWM_INPUT_RISINGEDGE,
	.startInput = TCPWM0_GRP1_CNT3_START_VALUE,
	.killInputMode = PWM_C_INPUT_DISABLED & 0x3U,
	.killInput = CY_TCPWM_INPUT_0,
	.countInputMode = PWM_C_INPUT_DISABLED & 0x3U,
	.countInput = CY_TCPWM_INPUT_1,
	.swapOverflowUnderflow = false,
	.immediateKill = true,
	.tapsEnabled = 45,
	.compare2 = 0,
	.compare3 = 0,
	.enableCompare1Swap = true,
	.compare0MatchUp = false,
	.compare0MatchDown = false,
	.compare1MatchUp = false,
	.compare1MatchDown = false,
	.kill1InputMode = PWM_C_INPUT_DISABLED & 0x3U,
	.kill1Input = CY_TCPWM_INPUT_0,
	.pwmOnDisable = CY_TCPWM_PWM_OUTPUT_LOW,
	.trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
	.trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t PWM_C_obj = 
	{
		.type = CYHAL_RSC_TCPWM,
		.block_num = 0U,
		.channel_num = 3U,
	};
#endif //defined (CY_USING_HAL)
const cy_stc_tcpwm_pwm_config_t PWM_A_config = 
{
	.pwmMode = CY_TCPWM_PWM_MODE_DEADTIME,
	.clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
	.pwmAlignment = CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN,
	.deadTimeClocks = 50,
	.runMode = CY_TCPWM_PWM_CONTINUOUS,
	.period0 = 2500,
	.period1 = 32768,
	.enablePeriodSwap = false,
	.compare0 = 0,
	.compare1 = 0,
	.enableCompareSwap = true,
	.interruptSources = (CY_TCPWM_INT_ON_TC & 0U) | (CY_TCPWM_INT_ON_CC0 & 0U) | (CY_TCPWM_INT_ON_CC1 & 0U),
	.invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
	.invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
	.killMode = CY_TCPWM_PWM_STOP_ON_KILL,
	.swapInputMode = CY_TCPWM_INPUT_RISINGEDGE,
	.swapInput = TCPWM0_GRP1_CNT4_CAPTURE0_VALUE,
	.reloadInputMode = PWM_A_INPUT_DISABLED & 0x3U,
	.reloadInput = CY_TCPWM_INPUT_0,
	.startInputMode = CY_TCPWM_INPUT_RISINGEDGE,
	.startInput = TCPWM0_GRP1_CNT4_START_VALUE,
	.killInputMode = PWM_A_INPUT_DISABLED & 0x3U,
	.killInput = CY_TCPWM_INPUT_0,
	.countInputMode = PWM_A_INPUT_DISABLED & 0x3U,
	.countInput = CY_TCPWM_INPUT_1,
	.swapOverflowUnderflow = false,
	.immediateKill = true,
	.tapsEnabled = 45,
	.compare2 = 0,
	.compare3 = 0,
	.enableCompare1Swap = true,
	.compare0MatchUp = false,
	.compare0MatchDown = false,
	.compare1MatchUp = false,
	.compare1MatchDown = false,
	.kill1InputMode = PWM_A_INPUT_DISABLED & 0x3U,
	.kill1Input = CY_TCPWM_INPUT_0,
	.pwmOnDisable = CY_TCPWM_PWM_OUTPUT_LOW,
	.trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
	.trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED,
};
#if defined (CY_USING_HAL)
	const cyhal_resource_inst_t PWM_A_obj = 
	{
		.type = CYHAL_RSC_TCPWM,
		.block_num = 0U,
		.channel_num = 4U,
	};
#endif //defined (CY_USING_HAL)


void init_cycfg_peripherals(void)
{
	Cy_SysClk_PeriphAssignDivider(PCLK_CANFD0_CLOCK_CAN0, CY_SYSCLK_DIV_16_BIT, 2U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&CANFD_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_CSD_CLOCK, CY_SYSCLK_DIV_16_BIT, 4U);

	Cy_CTB_SetDeepSleepMode(CTBM0, CY_CTB_DEEPSLEEP_DISABLE);

#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&OpAmp0_obj);
#endif //defined (CY_USING_HAL)

#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&OpAmp1_obj);
#endif //defined (CY_USING_HAL)

	Cy_CTB_SetPumpClkSource(PASS, CY_CTB_CLK_PUMP_SRSS);

	Cy_SysClk_PeriphAssignDivider(PCLK_PASS_CLOCK_SAR0, CY_SYSCLK_DIV_16_BIT, 3U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ADC0_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_PASS_CLOCK_SAR1, CY_SYSCLK_DIV_16_BIT, 3U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ADC1_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_SCB1_CLOCK, CY_SYSCLK_DIV_8_BIT, 2U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENCODER_SSC_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_SCB2_CLOCK, CY_SYSCLK_DIV_16_BIT, 0U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&DEBUG_UART_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_SCB4_CLOCK, CY_SYSCLK_DIV_8_BIT, 1U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&FETDRV_SPI_obj);
#endif //defined (CY_USING_HAL)

#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&WATCHDOG_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKS2, CY_SYSCLK_DIV_8_BIT, 3U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&ENCODER_QUAD1_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKS256, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&PWM_Timer_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKS258, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&PWM_B_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKS259, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&PWM_C_obj);
#endif //defined (CY_USING_HAL)

	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKS260, CY_SYSCLK_DIV_8_BIT, 0U);
#if defined (CY_USING_HAL)
	cyhal_hwmgr_reserve(&PWM_A_obj);
#endif //defined (CY_USING_HAL)
}
