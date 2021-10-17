/*!
 * \name        IFX_6EDL7141.c - Library for the 6EDL7141 gate driver.
 * \author      // TODO
 * \copyright   // TODO
 * \version     // TODO
 * \brief       // TODO
 *
 */

#include "IFX_6EDL7141.h"

uint8_t SPI_BUFFER[MAX_NUM_REG_6EDL7141];
cy_stc_scb_spi_context_t FETDRV_SPI_context;

#ifndef IFX_6EDL7141_SPI_HW
  #define IFX_6EDL7141_SPI_HW          FETDRV_SPI_HW
#endif
#ifndef IFX_6EDL7141_SPI_CONFIG
  #define IFX_6EDL7141_SPI_CONFIG      FETDRV_SPI_config
#endif
#ifndef IFX_6EDL7141_SPI_CONTEXT
  #define IFX_6EDL7141_SPI_CONTEXT     FETDRV_SPI_context
#endif
#ifndef IFX_6EDL7141_SPI_CS
  #define IFX_6EDL7141_SPI_CS          0xff
#endif

#define DRV_INIT()                     Cy_SCB_SPI_Init(IFX_6EDL7141_SPI_HW, &IFX_6EDL7141_SPI_CONFIG, &IFX_6EDL7141_SPI_CONTEXT);
#define DRV_ENABLE()                   Cy_SCB_SPI_Enable(IFX_6EDL7141_SPI_HW)

#define DRV_READ()                     Cy_SCB_SPI_Read(IFX_6EDL7141_SPI_HW)
#define DRV_Select_CS()                Cy_SCB_SPI_SetActiveSlaveSelect(IFX_6EDL7141_SPI_HW, IFX_6EDL7141_SPI_CS)
#define DRV_Write(data)                Cy_SCB_SPI_Write(IFX_6EDL7141_SPI_HW, data)
#define DRV_RX_FIFO_BUFFER_COUNT       Cy_SCB_SPI_GetNumInRxFifo(IFX_6EDL7141_SPI_HW)


e_6EDL7141_errorTypes_t IFX_6EDL7141_Init(void)
{
  e_6EDL7141_errorTypes_t ret = IFX_6EDL7141_NO_ERROR;
  
  ret |= (e_6EDL7141_errorTypes_t)DRV_INIT();
  DRV_ENABLE();
  
  if(ret != IFX_6EDL7141_NO_ERROR)
  {
    return IFX_6EDL7141_ERROR;
  }

  ret |= IFX_6EDL7141_ReadAllRegister();
  
  ret |= IFX_6EDL7141_ClearFaults();
  
  _6EDL7141_Register.SUPPLY_CFG.PVCC_SETPT = 0;       // PVCC 12V (default)
  _6EDL7141_Register.SUPPLY_CFG.CS_REF_CFG = 0;       // Vref DVDD/2 (default)
  _6EDL7141_Register.SUPPLY_CFG.DVDD_OCP_CFG = 0;     // DVDD OCP 450mA (default)
  _6EDL7141_Register.SUPPLY_CFG.DVDD_SFTSTRT = 0;     // 100us (default)
  _6EDL7141_Register.SUPPLY_CFG.DVDD_SETPT = 0;       // use external pin set DVDD (default)
  _6EDL7141_Register.SUPPLY_CFG.BK_FREQ = 0;          // 500kHz Buck (default)
  _6EDL7141_Register.SUPPLY_CFG.DVDD_TON_DELAY = 3;   // turn on Delay 800us (default)
  _6EDL7141_Register.SUPPLY_CFG.CP_PRECHARGE_EN = 1;  // Precharge Charge Pumps (enabled)
  ret |= IFX_6EDL7141_WriteRegister(REG_SUPPLY_CFG, &_6EDL7141_Register.SUPPLY_CFG.reg);
  
  _6EDL7141_Register.ADC_CFG.ADC_OD_REQ = 0;          // No OD Request
  _6EDL7141_Register.ADC_CFG.ADC_OD_INSEL = 0;        // OD = IDIGITAL
  _6EDL7141_Register.ADC_CFG.ADC_EN_FILT = 0;         // No filter for OD channel
  _6EDL7141_Register.ADC_CFG.ADC_FILT_CFG = 0;        // 8 samples average
  _6EDL7141_Register.ADC_CFG.ADC_FILT_CFG_PVDD = 0;   // 32 samples average for PVDD
  ret |= IFX_6EDL7141_WriteRegister(REG_ADC_CFG, &_6EDL7141_Register.ADC_CFG.reg);
  
  _6EDL7141_Register.PWM_CFG.PWM_MODE = 0;            // 6 PWM Mode (default)
  _6EDL7141_Register.PWM_CFG.PWM_FREEW_CFG = 0;       // Do Not Care
  _6EDL7141_Register.PWM_CFG.BRAKE_CFG = 0;           // Low Side Brake
  _6EDL7141_Register.PWM_CFG.PWM_RECIRC = 0;          // Do Not Care
  ret |= IFX_6EDL7141_WriteRegister(REG_PWM_CFG, &_6EDL7141_Register.PWM_CFG.reg);
  
  _6EDL7141_Register.SENSOR_CFG.HALL_DEGLITCH = 1;    // Do Not Care??
  _6EDL7141_Register.SENSOR_CFG.OTS_DIS = 0;          // Enable Overtemperature Shutdown
  _6EDL7141_Register.SENSOR_CFG.CS_TMODE = 3;         // Enable OpAmps (always on)
  ret |= IFX_6EDL7141_WriteRegister(REG_SENSOR_CFG, &_6EDL7141_Register.SENSOR_CFG.reg);
  
  _6EDL7141_Register.WD_CFG.WD_EN = 0;                // todo: ENABLE!!!
  _6EDL7141_Register.WD_CFG.WD_INSEL = 4;             // FAULT Status Register Read
  _6EDL7141_Register.WD_CFG.WD_FLTCFG = 1;            // use Status Register and nFault pin (enabled)
  _6EDL7141_Register.WD_CFG.WD_TIMER_T = 100;         // period = 10ms
  ret |= IFX_6EDL7141_WriteRegister(REG_WD_CFG, &_6EDL7141_Register.WD_CFG.reg);
  
  _6EDL7141_Register.WD_CFG2.WD_BRAKE = 1;            // Brake on watchdog timer overflow (enabled)
  _6EDL7141_Register.WD_CFG2.WD_EN_LATCH = 1;         // Fault latched (enabled)
  _6EDL7141_Register.WD_CFG2.WD_DVDD_RSTRT_ATT = 0;   // DVDD restart attemps 0 (default)
  _6EDL7141_Register.WD_CFG2.WD_DVDD_RSTRT_DLY = 0;   // DVDD restart delay 0.5ms (default)
  _6EDL7141_Register.WD_CFG2.WD_RLOCK_EN = 0;         // Rotor locked detection Disable (default)
  _6EDL7141_Register.WD_CFG2.WD_RLOCK_T = 0;          // Rotor locked watchdog timeout 1s (default)
  _6EDL7141_Register.WD_CFG2.WD_BK_DIS = 0;           // Buck watchdog enabled (default)
  ret |= IFX_6EDL7141_WriteRegister(REG_WD_CFG2, &_6EDL7141_Register.WD_CFG2.reg);
  
  _6EDL7141_Register.IDRIVE_CFG.IHS_SRC = 11;         // 200mA High-side source current
  _6EDL7141_Register.IDRIVE_CFG.IHS_SINK= 11;         // 200mA High-side sink current
  _6EDL7141_Register.IDRIVE_CFG.ILS_SRC = 11;         // 200mA Low-side source current
  _6EDL7141_Register.IDRIVE_CFG.ILS_SINK = 11;        // 200mA Low-side sink current
  ret |= IFX_6EDL7141_WriteRegister(REG_IDRIVE_CFG, &_6EDL7141_Register.IDRIVE_CFG.reg);
  
  _6EDL7141_Register.IDRIVE_PRE_CFG.I_PRE_SRC = 11;   // 200mA Pre-charge source current setting
  _6EDL7141_Register.IDRIVE_PRE_CFG.I_PRE_SINK = 11;  // 200mA Pre-charge sink current setting
  _6EDL7141_Register.IDRIVE_PRE_CFG.I_PRE_EN = 0;     // Pre-charge current enabled (default)
  ret |= IFX_6EDL7141_WriteRegister(REG_IDRIVE_PRE_CFG, &_6EDL7141_Register.IDRIVE_PRE_CFG.reg);
  
  _6EDL7141_Register.TDRIVE_SRC_CFG.TDRIVE1 = 0;      // 0ns TDRIVE1 timing
  _6EDL7141_Register.TDRIVE_SRC_CFG.TDRIVE2 = 0;      // 0ns TDRIVE2 timing
  ret |= IFX_6EDL7141_WriteRegister(REG_TDRIVE_SRC_CFG, &_6EDL7141_Register.TDRIVE_SRC_CFG.reg);
  
  _6EDL7141_Register.TDRIVE_SINK_CFG.TDRIVE3 = 0;     // 0ns TDRIVE3 timing
  _6EDL7141_Register.TDRIVE_SINK_CFG.TDRIVE4 = 0;     // 0ns TDRIVE4 timing
  ret |= IFX_6EDL7141_WriteRegister(REG_TDRIVE_SINK_CFG, &_6EDL7141_Register.TDRIVE_SINK_CFG.reg);
  
  _6EDL7141_Register.DT_CFG.DT_RISE = 5;              // Dead time rise (of phase node voltage) 0.52us
  _6EDL7141_Register.DT_CFG.DT_FALL = 5;              // Dead time fall (of phase node voltage) 0.52us
  ret |= IFX_6EDL7141_WriteRegister(REG_DT_CFG, &_6EDL7141_Register.DT_CFG.reg);
  
  _6EDL7141_Register.CP_CFG.CP_CLK_CFG = 0;           // Charge pump clock frequency 781.25 kHz (default)
  _6EDL7141_Register.CP_CFG.CP_CLK_SS_DIS = 0;        // Charge pump clock spread spectrum enabled (default)
  ret |= IFX_6EDL7141_WriteRegister(REG_CP_CFG, &_6EDL7141_Register.CP_CFG.reg);
  
  _6EDL7141_Register.CSAMP_CFG.CS_GAIN = 4;           // Gain of current sense amplifiers 20 V/V
  _6EDL7141_Register.CSAMP_CFG.CS_GAIN_ANA = 0;       // Gain is selected via register configuration (CS_GAIN bitfield)
  _6EDL7141_Register.CSAMP_CFG.CS_EN = 7;             // Enable all current shunt amplifiers
  _6EDL7141_Register.CSAMP_CFG.CS_BLANK = 0;          // Current shunt amplifier blanking time 100ns
  _6EDL7141_Register.CSAMP_CFG.CS_EN_DCCAL = 1;       // Enable DC Calibration of CS amplifier
  _6EDL7141_Register.CSAMP_CFG.CS_OCP_DEGLITCH = 1;   // Current sense amplifier OCP deglitch 2us
  _6EDL7141_Register.CSAMP_CFG.CS_OCPFLT_CFG = 0;     // OCP fault trigger after 8 OCP events
  ret |= IFX_6EDL7141_WriteRegister(REG_CSAMP_CFG, &_6EDL7141_Register.CSAMP_CFG.reg);
  
  _6EDL7141_Register.CSAMP_CFG2.CS_OCP_PTHR = 8;      // Current sense amplifier OCP positive thresholds 100mV todo: !!!!
  _6EDL7141_Register.CSAMP_CFG2.CS_OCP_NTHR = 8;      // Current sense amplifier OCP negative thresholds 100mV todo: !!!!
  _6EDL7141_Register.CSAMP_CFG2.CS_OCP_LATCH = 1;     // OCP latched
  _6EDL7141_Register.CSAMP_CFG2.CS_MODE = 0;          // Measure Shunt resistor
  _6EDL7141_Register.CSAMP_CFG2.CS_OCP_BRAKE = 1;     // Brake on OCP fault
  _6EDL7141_Register.CSAMP_CFG2.CS_TRUNC_DIS = 1;     // PWM truncation disabled
  _6EDL7141_Register.CSAMP_CFG2.VREF_INSEL = 0;       // Use internal Vref
  _6EDL7141_Register.CSAMP_CFG2.CS_NEG_OCP_DIS = 0;   // Negative OCP fault is enabled
  _6EDL7141_Register.CSAMP_CFG2.CS_AZ_CFG = 3;        // Auto-Zero enabled with External Enhanced Sensing
  ret |= IFX_6EDL7141_WriteRegister(REG_CSAMP_CFG2, &_6EDL7141_Register.CSAMP_CFG2.reg);
  
  ret |= IFX_6EDL7141_ReadAllRegister();
  
  // DO NOT WRITE OTP REGISTER
  
  return ret;
}

e_6EDL7141_errorTypes_t IFX_6EDL7141_EnableCalibrationMode(void)
{
  IFX_6EDL7141_ReadRegister(REG_CSAMP_CFG, &_6EDL7141_Register.CSAMP_CFG.reg);
  _6EDL7141_Register.CSAMP_CFG.CS_EN_DCCAL = 1; // Enable DC Calibration of CS amplifier
  IFX_6EDL7141_WriteRegister(REG_CSAMP_CFG, &_6EDL7141_Register.CSAMP_CFG.reg);
  
  return IFX_6EDL7141_NO_ERROR;
}

e_6EDL7141_errorTypes_t IFX_6EDL7141_DisableCalibrationMode(void)
{
  IFX_6EDL7141_ReadRegister(REG_CSAMP_CFG, &_6EDL7141_Register.CSAMP_CFG.reg);
  _6EDL7141_Register.CSAMP_CFG.CS_EN_DCCAL = 0; // Disable DC Calibration of CS amplifier
  IFX_6EDL7141_WriteRegister(REG_CSAMP_CFG, &_6EDL7141_Register.CSAMP_CFG.reg);
  
  return IFX_6EDL7141_NO_ERROR;
}

fault_st_t IFX_6EDL7141_ReadFaults(void)
{
  fault_st_t temp;
  
  IFX_6EDL7141_ReadRegister(REG_FAULT_ST, &temp.reg);
  
  return temp;
}

supply_st_t IFX_6EDL7141_ReadSupplyStatus(void)
{
  supply_st_t temp;
  
  IFX_6EDL7141_ReadRegister(REG_SUPPLY_ST, &temp.reg);
  
  return temp;
}

e_6EDL7141_errorTypes_t IFX_6EDL7141_ClearFaults(void)
{
  fault_clr_t temp = {.reg = 0};
  temp.CLR_FLTS = 1;
  
  return IFX_6EDL7141_WriteRegister(REG_FAULT_CLR, &temp.reg);
}

e_6EDL7141_errorTypes_t IFX_6EDL7141_ClearLatchedFaults(void)
{
  fault_clr_t temp = {.reg = 0};
  temp.CLR_LATCH = 1;
  
  return IFX_6EDL7141_WriteRegister(REG_FAULT_CLR, &temp.reg);
}


e_6EDL7141_errorTypes_t IFX_6EDL7141_ReadAllRegister(void)
{
  for(int i = 0x00; i <= 0x07; i++)
  {
    IFX_6EDL7141_ReadRegister(i, &_6EDL7141_Register.registers[i]);
  }
  
  for(int i = 0x10; i <= 0x1F; i++)
  {
    IFX_6EDL7141_ReadRegister(i, &_6EDL7141_Register.registers[i]);
  }
  
  return IFX_6EDL7141_NO_ERROR;
}

float IFX_6EDL7141_CalcPVDD(void)
{
  float result;
  
  IFX_6EDL7141_ReadRegister(REG_SUPPLY_ST, &_6EDL7141_Register.SUPPLY_ST.reg);
  
  result = _6EDL7141_Register.SUPPLY_ST.PVDD_VAL * 0.581f + 5.52f;
  
  return result;
}

float IFX_6EDL7141_CalcTemp(void)
{
  float result;
  
  IFX_6EDL7141_ReadRegister(REG_TEMP_ST, &_6EDL7141_Register.TEMP_ST.reg);
  
  result = (float)_6EDL7141_Register.TEMP_ST.TEMP_VAL * 2.0f - 94.0f;
  
  return result;
}

float IFX_6EDL7141_CalcVCCLS(void)
{
  float result;
  
  IFX_6EDL7141_ReadRegister(REG_CP_ST, &_6EDL7141_Register.CP_ST.reg);
  
  result = (float)_6EDL7141_Register.CP_ST.VCCLS_VAL * 16.0f / 127.0f;
  
  return result;
}

float IFX_6EDL7141_CalcVCCHS(void)
{
  float result;
  
  IFX_6EDL7141_ReadRegister(REG_CP_ST, &_6EDL7141_Register.CP_ST.reg);
  
  result = (float)_6EDL7141_Register.CP_ST.VCCHS_VAL * 16.0f / 127.0f;
  
  return result;
}

float IFX_6EDL7141_CalcDeviceCurrent(void)
{
  IFX_6EDL7141_ReadRegister(REG_ADC_CFG, &_6EDL7141_Register.ADC_CFG.reg);
  _6EDL7141_Register.ADC_CFG.ADC_OD_INSEL = 0;
  _6EDL7141_Register.ADC_CFG.ADC_OD_REQ = 1;
  IFX_6EDL7141_WriteRegister(REG_ADC_CFG, &_6EDL7141_Register.ADC_CFG.reg);
  
  do{
    IFX_6EDL7141_ReadRegister(REG_ADC_ST, &_6EDL7141_Register.ADC_ST.reg);
//todo: blocking!!!
  }while(_6EDL7141_Register.ADC_ST.ADC_OD_RDY == 0);
  
  IFX_6EDL7141_ReadRegister(REG_ADC_ST, &_6EDL7141_Register.ADC_ST.reg);
  
  return (float)_6EDL7141_Register.ADC_ST.ADC_OD_VAL * 0.24f;
}

float IFX_6EDL7141_CalcDVDD(void)
{
  float result = 0.0f;
  
  IFX_6EDL7141_ReadRegister(REG_ADC_CFG, &_6EDL7141_Register.ADC_CFG.reg);
  _6EDL7141_Register.ADC_CFG.ADC_OD_INSEL = 1;
  _6EDL7141_Register.ADC_CFG.ADC_OD_REQ = 1;
  IFX_6EDL7141_WriteRegister(REG_ADC_CFG, &_6EDL7141_Register.ADC_CFG.reg);
  
  do{
    IFX_6EDL7141_ReadRegister(REG_ADC_ST, &_6EDL7141_Register.ADC_ST.reg);
//todo: blocking!!!
  }while(_6EDL7141_Register.ADC_ST.ADC_OD_RDY == 0);
  
  IFX_6EDL7141_ReadRegister(REG_FUNC_ST, &_6EDL7141_Register.FUNC_ST.reg);
  
  if(_6EDL7141_Register.FUNC_ST.DVDD_ST == 0)
  {
    result = (float)_6EDL7141_Register.ADC_ST.ADC_OD_VAL * 3.3f / 127.0f;
  }
  else
  {
    result = (float)_6EDL7141_Register.ADC_ST.ADC_OD_VAL * 5.0f / 127.0f;
  }
  return result;
}

float IFX_6EDL7141_CalcVDDB(void)
{
  float result = 0.0f;
  
  IFX_6EDL7141_ReadRegister(REG_ADC_CFG, &_6EDL7141_Register.ADC_CFG.reg);
  _6EDL7141_Register.ADC_CFG.ADC_OD_INSEL = 2;
  _6EDL7141_Register.ADC_CFG.ADC_OD_REQ = 1;
  IFX_6EDL7141_WriteRegister(REG_ADC_CFG, &_6EDL7141_Register.ADC_CFG.reg);
  
  do{
    IFX_6EDL7141_ReadRegister(REG_ADC_ST, &_6EDL7141_Register.ADC_ST.reg);
//todo: blocking!!!
  }while(_6EDL7141_Register.ADC_ST.ADC_OD_RDY == 0);
  
  IFX_6EDL7141_ReadRegister(REG_SUPPLY_CFG, &_6EDL7141_Register.SUPPLY_CFG.reg);
  
  if(_6EDL7141_Register.SUPPLY_CFG.PVCC_SETPT == 3)
  {
    result = (float)_6EDL7141_Register.ADC_ST.ADC_OD_VAL * 6.5f / 127.0f;
  }
  else if(_6EDL7141_Register.SUPPLY_CFG.PVCC_SETPT == 2)
  {
    result = (float)_6EDL7141_Register.ADC_ST.ADC_OD_VAL * 7.0f / 127.0f;
  }
  else
  {
    result = (float)_6EDL7141_Register.ADC_ST.ADC_OD_VAL * 8.0f / 127.0f;
  }
  return result;
}

e_6EDL7141_errorTypes_t IFX_6EDL7141_ReadRegister(e_reg_6EDL7141_t reg, uint16_t *data)
{
  uint16_t temp = 0;
  
  SPI_BUFFER[0] = ((0 << 8) | (reg & 0x7F));
  
  SPI_BUFFER[1] = 0x00;
  SPI_BUFFER[2] = 0x00;
  
#if (IFX_6EDL7141_SPI_CS < 4)
  DRV_Select_CS();
#endif
  
  for(uint8_t i = 0; i < 3; i++)
  {
    DRV_Write(SPI_BUFFER[i]);
  }
  
  while (DRV_RX_FIFO_BUFFER_COUNT < (3))  {}
  
  /* read command */
  temp  = DRV_READ();
  temp  = (DRV_READ() << 8);
  temp |= DRV_READ();
  
  data[0] = temp;
  
  return IFX_6EDL7141_NO_ERROR;
}

e_6EDL7141_errorTypes_t IFX_6EDL7141_WriteRegister(e_reg_6EDL7141_t reg, uint16_t *data)
{
  if(reg >= REG_OTP_PROG)
  {
    // ignore OTP register writes
    return IFX_6EDL7141_PARAM_ERROR;
  }
  SPI_BUFFER[0] = ((1 << 7) | (reg & 0x7F));
  
  SPI_BUFFER[1] = data[0] >> 8;
  SPI_BUFFER[2] = data[0] & 0xFF;
  
#if (IFX_6EDL7141_SPI_CS < 4)
  DRV_Select_CS();
#endif
  
  for(uint8_t i = 0; i < 3; i++)
  {
    DRV_Write(SPI_BUFFER[i]);
  }
  
  while (DRV_RX_FIFO_BUFFER_COUNT < (3))  {}
  
  /* clear FIFO */
  DRV_READ();
  DRV_READ();
  DRV_READ();
  
  return IFX_6EDL7141_NO_ERROR;
}

e_6EDL7141_errorTypes_t IFX_6EDL7141_SetOTP(uint32_t key, uint8_t user_id)
{
  if(key != 0x49465821) // = ASCII "IFX!"
  {
    // Wrong Key
    return IFX_6EDL7141_PARAM_ERROR;
  }

  IFX_6EDL7141_ReadRegister(REG_OTP_ST, &_6EDL7141_Register.OTP_ST.reg);
  if(1 == _6EDL7141_Register.OTP_ST.OTP_USED)
  {
    // OTP already performed
    return IFX_6EDL7141_OPT_FAILED;
  }

  SPI_BUFFER[0] = ((1 << 7) | REG_OTP_PROG);

  SPI_BUFFER[1] = 0x00;
  SPI_BUFFER[2] = (user_id << 1) | (0x01);

#if (IFX_6EDL7141_SPI_CS < 4)
  DRV_Select_CS();
#endif

  for(uint8_t i = 0; i < 3; i++)
  {
    DRV_Write(SPI_BUFFER[i]);
  }

  while (DRV_RX_FIFO_BUFFER_COUNT < (3))  {}

  /* clear FIFO */
  DRV_READ();
  DRV_READ();
  DRV_READ();

  IFX_6EDL7141_ReadRegister(REG_OTP_ST, &_6EDL7141_Register.OTP_ST.reg);
  if(1 != _6EDL7141_Register.OTP_ST.OTP_PASS)
  {
    // OTP not passed
    return IFX_6EDL7141_OPT_FAILED;
  }

  return IFX_6EDL7141_NO_ERROR;
}
