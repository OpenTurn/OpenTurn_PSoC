/*
 * encoder.c
 *
 *  Created on: 23.01.2021
 *      Author: achim
 */

#include "resources.h"
#include "tle5012b.h"

uint8_t UART_Buffer[64];

uint16_t SPI_BUFFER[MAX_NUM_REG];
cy_stc_scb_spi_context_t ENCODER_SSC_context;

#define SSC_SPI                   ENCODER_SSC_HW
#define SSC_SPI_CONFIG            ENCODER_SSC_config
#define SSC_SPI_CONTEXT           ENCODER_SSC_context
#define SSC_CS_PORT               ENC_SSC_CS1_PORT
#define SSC_CS_PIN                ENC_SSC_CS1_PIN

#define Clear_CS()                Cy_GPIO_Write(SSC_CS_PORT, SSC_CS_PIN, 0)
#define Set_CS()                  Cy_GPIO_Write(SSC_CS_PORT, SSC_CS_PIN, 1)

#define SSC_INIT()                Cy_SCB_SPI_Init(SSC_SPI, &SSC_SPI_CONFIG, &SSC_SPI_CONTEXT);
#define SSC_ENABLE()              Cy_SCB_SPI_Enable(SSC_SPI)
#define SSC_DISABLE()             Cy_SCB_SPI_Disable(SSC_SPI, &SSC_SPI_CONTEXT)

#define SSC_READ()                Cy_SCB_SPI_Read(SSC_SPI)
#define SSC_Write(data)           Cy_SCB_SPI_Write(SSC_SPI, data)
#define SSC_RX_FIFO_BUFFER_COUNT  Cy_SCB_SPI_GetNumInRxFifo(SSC_SPI)

#define tle5012b_ReadRegister(adr, buffered)        (tle5012b_ReadDataOne(adr, &tle5012b_Register.registers[adr], buffered, true))
#define tle5012b_WriteRegister(adr, data)           (tle5012b_WriteDataOne(adr, data, true))

bool synched = false;

/* DMA Config */
uint32_t ENCODER_DMA_GPIO_MASK = (1 << SSC_CS_PIN);
static uint32_t ENCODER_DMA_CRC_RX_seed = 0xFF000000;
uint8_t ENCODER_DMA_DATA[20] = {0x80, 0x21, 0xFF, 0xFF, 0xFF,
                                0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

uint32_t ENCODER_DMA_CRC_RX_result = 0x00000000;
uint16_t ENCODER_DMA_RX_data[20];



e_errorTypes_t tle5012b_CheckStat(uint16_t data);

uint8_t tle5012b_crc8(uint16 command, uint8_t *data, uint8_t length)
{
  uint32_t crc;
  int16_t i, bit;

  crc = CRC_SEED;

  crc ^= (command >> 8);
  for (bit = 0; bit < 8; bit++)
  {
    if ((crc & 0x80) != 0)
    {
      crc <<= 1;
      crc ^= CRC_POLYNOMIAL;
    }else{
      crc <<= 1;
    }
  }

  crc ^= (command & 0xFF);
  for (bit = 0; bit < 8; bit++)
  {
    if ((crc & 0x80) != 0)
    {
      crc <<= 1;
      crc ^= CRC_POLYNOMIAL;
    }else{
      crc <<= 1;
    }
  }

  for (i = 0; i < length; i++)
  {
    crc ^= data[i^1];
    for (bit = 0; bit < 8; bit++)
    {
      if ((crc & 0x80) != 0)
      {
        crc <<= 1;
        crc ^= CRC_POLYNOMIAL;
      }else{
        crc <<= 1;
      }
    }
  }

  return ((~crc) & CRC_SEED);
}


e_errorTypes_t tle5012b_Init(void)
{
  e_errorTypes_t ret = NO_ERROR;

  Set_CS();
  SSC_INIT();
  SSC_ENABLE();

  ret = tle5012b_UpdateAll();
  if(NO_ERROR != ret)
  {
    PrintDebugAlarm(ret);
    MotorParameter.MotorCtrlState = CRITICAL_ERROR;
    return ret;
  }

  ret |= tle5012b_SetAutoCal(Settings.calibration_mode);
  if(tle5012b_Register.mod2.reg != (0x0800 | Settings.calibration_mode))
  {
    PrintDebugAlarm(ret);
    MotorParameter.MotorCtrlState = CRITICAL_ERROR;
    return WRITE_ERROR;
  }

  return ret;
}


void tle5012b_SetupDMA(uint8_t address, uint8_t count, uint16_t *data, uint8_t *crc, bool buffered, uint32_t trigger)
{
  uint16_t temp = 0;

  temp = ((1 << 15) | (0x0 << 11) | ((buffered & 0x1) << 10) | ((address & 0x3F) << 4) | ((count & 0xF) << 0));

  if(4 < address)
  {
    temp = (temp | (0xA << 11));
  }
  ENCODER_DMA_DATA[0] = (temp >> 8);
  ENCODER_DMA_DATA[1] = temp & 0xFF;

  // TX DMA Init
  Cy_DMA_Descriptor_Init(&ENCODER_CRC_TX_Descriptor_0, &ENCODER_CRC_TX_Descriptor_0_config);
  Cy_DMA_Descriptor_Init(&ENCODER_CRC_TX_Descriptor_1, &ENCODER_CRC_TX_Descriptor_1_config);

  // TX DMA Set Source/Destination Addresses
  Cy_DMA_Descriptor_SetSrcAddress(&ENCODER_CRC_TX_Descriptor_0, (uint8_t *)&ENCODER_DMA_GPIO_MASK);
  Cy_DMA_Descriptor_SetDstAddress(&ENCODER_CRC_TX_Descriptor_0, (uint8_t *)&SSC_CS_PORT->OUT_CLR);

  Cy_DMA_Descriptor_SetSrcAddress(&ENCODER_CRC_TX_Descriptor_1, (uint8_t *)&ENCODER_DMA_DATA[0]);
  Cy_DMA_Descriptor_SetDstAddress(&ENCODER_CRC_TX_Descriptor_1, (uint8_t *)&SSC_SPI->TX_FIFO_WR);

  // TX DMA Enable
  Cy_DMA_Channel_Init(ENCODER_CRC_TX_HW, ENCODER_CRC_TX_CHANNEL, &ENCODER_CRC_TX_channelConfig);
  Cy_DMA_Channel_SetDescriptor(ENCODER_CRC_TX_HW, ENCODER_CRC_TX_CHANNEL, &ENCODER_CRC_TX_Descriptor_0);
  Cy_DMA_Channel_Enable(ENCODER_CRC_TX_HW, ENCODER_CRC_TX_CHANNEL);


  // RX DMA Init
  Cy_DMA_Descriptor_Init(&ENCODER_CRC_RX_Descriptor_0, &ENCODER_CRC_RX_Descriptor_0_config);
  Cy_DMA_Descriptor_Init(&ENCODER_CRC_RX_Descriptor_1, &ENCODER_CRC_RX_Descriptor_1_config);
  Cy_DMA_Descriptor_Init(&ENCODER_CRC_RX_Descriptor_2, &ENCODER_CRC_RX_Descriptor_2_config);
  Cy_DMA_Descriptor_Init(&ENCODER_CRC_RX_Descriptor_3, &ENCODER_CRC_RX_Descriptor_3_config);
  Cy_DMA_Descriptor_Init(&ENCODER_CRC_RX_Descriptor_4, &ENCODER_CRC_RX_Descriptor_4_config);

  // RX DMA CRC Init
  cy_stc_dma_crc_config_t ENCODER_CRC_RX_crcConf =
  {
      .dataReverse = false,
      .dataXor = 0xFF000000,
      .reminderReverse = false,
      .reminderXor = 0xFF000000,
      .polynomial = (0x1D << 24),
      .lfsrInitVal = 0xFF000000
  };
  Cy_DMA_Crc_Init(ENCODER_CRC_RX_HW, &ENCODER_CRC_RX_crcConf);

  // RX DMA Set Source/Destination Addresses
  Cy_DMA_Descriptor_SetSrcAddress(&ENCODER_CRC_RX_Descriptor_0, (uint8_t *)&SSC_SPI->RX_FIFO_RD);
  Cy_DMA_Descriptor_SetDstAddress(&ENCODER_CRC_RX_Descriptor_0, (uint8_t *)&ENCODER_DMA_RX_data[0]);

  Cy_DMA_Descriptor_SetSrcAddress(&ENCODER_CRC_RX_Descriptor_1, (uint8_t *)&ENCODER_DMA_GPIO_MASK);
  Cy_DMA_Descriptor_SetDstAddress(&ENCODER_CRC_RX_Descriptor_1, (uint8_t *)&SSC_CS_PORT->OUT_SET);

  Cy_DMA_Descriptor_SetSrcAddress(&ENCODER_CRC_RX_Descriptor_2, (uint8_t *)&ENCODER_DMA_CRC_RX_seed);
  Cy_DMA_Descriptor_SetDstAddress(&ENCODER_CRC_RX_Descriptor_2, (uint8_t *)&DW0->CRC_LFSR_CTL);

  Cy_DMA_Descriptor_SetSrcAddress(&ENCODER_CRC_RX_Descriptor_3, (uint8_t *)&ENCODER_DMA_RX_data[0]);
  Cy_DMA_Descriptor_SetDstAddress(&ENCODER_CRC_RX_Descriptor_3, (uint8_t *)&ENCODER_DMA_CRC_RX_result);

  Cy_DMA_Descriptor_SetSrcAddress(&ENCODER_CRC_RX_Descriptor_4, (uint8_t *)&DW0->CRC_REM_RESULT);
  Cy_DMA_Descriptor_SetDstAddress(&ENCODER_CRC_RX_Descriptor_4, (uint8_t *)&crc);

  // RX DMA Select Trigger source
  if(0 != trigger)
  {
    Cy_TrigMux_Select(trigger, false, TRIGGER_TYPE_EDGE);
  }

  // RX DMA Channel Init
  Cy_DMA_Channel_Init(ENCODER_CRC_RX_HW, ENCODER_CRC_RX_CHANNEL, &ENCODER_CRC_RX_channelConfig);

  // RX DMA Enable
  Cy_DMA_Channel_SetPriority(ENCODER_CRC_RX_HW, ENCODER_CRC_RX_CHANNEL, 3UL);
  Cy_DMA_Channel_Enable(ENCODER_CRC_RX_HW, ENCODER_CRC_RX_CHANNEL);
}

void tle5012b_EnableDMA(void)
{
  Cy_DMA_Enable(ENCODER_CRC_RX_HW);
  Cy_DMA_Enable(ENCODER_CRC_TX_HW);
}

void tle5012b_DisableDMA(void)
{
  Cy_DMA_Disable(ENCODER_CRC_RX_HW);
  Cy_DMA_Disable(ENCODER_CRC_TX_HW);
}

void tle5012b_SetSrcAddress(uint8_t address, uint8_t count, bool buffered)
{
  uint16_t temp = 0;

  temp = ((1 << 15) | (0x0 << 11) | ((buffered & 0x1) << 10) | ((address & 0x3F) << 4) | ((count & 0xF) << 0));

  if(4 < address)
  {
    temp = (temp | (0xA << 11));
  }
  ENCODER_DMA_DATA[0] = (temp >> 8);
  ENCODER_DMA_DATA[1] = temp & 0xFF;
}

void tle5012b_SetDesAddress(uint16_t *data)
{
  Cy_DMA_Descriptor_SetDstAddress(&ENCODER_CRC_RX_Descriptor_0, (uint8_t *)&data);
  Cy_DMA_Descriptor_SetSrcAddress(&ENCODER_CRC_RX_Descriptor_3, (uint8_t *)&data);
}

void tle5012b_SetTrigger(uint32_t trigger)
{
  Cy_TrigMux_Select(trigger, false, TRIGGER_TYPE_EDGE);
}

void tle5012b_SoftTrigger(void)
{
  Cy_TrigMux_SwTrigger(((1 << 30) | (0x10 << 8) | (0x03 << 0)), CY_TRIGGER_TWO_CYCLES);
}

uint32_t tle5012b_GetResolution(bool buffer)
{
  e_errorTypes_t ret = NO_ERROR;
  uint32_t temp = 14;
  
  if(true == buffer)
  {
    temp = temp - tle5012b_Register.mod4.IFAB_RES;
  }else{
    ret |= tle5012b_ReadRegister(REG_MOD_4, false);
    temp = temp - tle5012b_Register.mod4.IFAB_RES;
  }
  
  return (1 << temp);
}

e_errorTypes_t tle5012b_WriteDataArray(uint8_t address, uint8_t count, uint16_t *data, bool buffered)
{
  e_errorTypes_t ret = NO_ERROR;
  
  return ret;
}

e_errorTypes_t tle5012b_WriteDataOne(uint8_t address, uint16_t data, bool stats)
{
  uint16_t temp = 0;
  uint16_t temp2 = 0;
  e_errorTypes_t ret = NO_ERROR;
  
  temp = ((0 << 15) | (0x0 << 11) | (0 << 10) | ((address & 0x3F) << 4) | (stats << 0));
  
  if((0x04 < address) & ((0x12 > address)))
  {
    temp = (temp | (0xA << 11));
  }
  SPI_BUFFER[0] = temp;
  SPI_BUFFER[1] = data;
  
  if(true == stats)
  {
    SPI_BUFFER[2] = 0xFF;
  }
  
  Clear_CS();
  
  for(uint8_t i = 0; i < (stats + 2); i++)
  {
    SSC_Write(SPI_BUFFER[i]);
  }
  
  while (SSC_RX_FIFO_BUFFER_COUNT < (stats + 2))  {}
  
  Set_CS();
  
  /* read command */
  temp2 = SSC_READ();
  
  if(temp == temp2)
  {
    data = SSC_READ();
  
    if(true == stats)
    {
      temp = SSC_READ();

      ret = tle5012b_CheckStat(temp);
      volatile uint8_t temp22 = tle5012b_crc8(temp2, (uint8_t *)&data, 2);
      if((temp & 0xFF) != temp22)
      {
        ret = CRC_ERROR;
      }
    }
  }else{
    ret = SSC_ERROR;
  }
  
  return ret;
}

e_errorTypes_t tle5012b_ReadDataArray(uint8_t address, uint8_t count, uint16_t *data, bool buffered)
{
  uint16_t temp = 0;
  uint16_t temp2 = 0;
  e_errorTypes_t ret = NO_ERROR;
  
  temp = ((1 << 15) | (0x0 << 11) | ((buffered & 0x1) << 10) | ((address & 0x3F) << 4) | ((count & 0xF) << 0));
  
  if((0x04 < address) & ((0x12 > address)))
  {
    temp = (temp | (0xA << 11));
  }
  SPI_BUFFER[0] = temp;
  
  for(uint8_t i = 2; i < (count + 2); i++)
  {
    SPI_BUFFER[i] = 0;
  }
  
  Clear_CS();
  
  for(uint8_t i = 0; i < (count + 2); i++)
  {
    SSC_Write(SPI_BUFFER[i]);
  }
  
  while (SSC_RX_FIFO_BUFFER_COUNT < (count + 2))  {}
  
  Set_CS();
  
  /* read command */
  temp2 = SSC_READ();
  
  if(temp == temp2)
  {
    for(uint8_t i = 0; i < count; i++)
    {
      temp = SSC_READ();
      
      data[i] = temp;
    }
    
    temp = SSC_READ();
    
    ret = tle5012b_CheckStat(temp);
    volatile uint8_t temp22 = tle5012b_crc8(temp2, (uint8_t *)&data[0], (count) * 2);
    if((temp & 0xFF) != temp22)
    {
      ret = CRC_ERROR;
    }
  }else{
    ret = SSC_ERROR;
  }

  return ret;
}

e_errorTypes_t tle5012b_ReadDataOne(uint8_t address, uint16_t *data, bool buffered, bool stats)
{
  uint16_t temp = 0;
  uint16_t temp2 = 0;
  e_errorTypes_t ret = NO_ERROR;
  
  temp = ((1 << 15) | (0x0 << 11) | ((buffered & 0x1) << 10) | ((address & 0x3F) << 4) | (stats << 0));
  
  if((0x04 < address) & ((0x12 > address)))
  {
    temp = (temp | (0xA << 11));
  }
  SPI_BUFFER[0] = temp;
  
  for(uint8_t i = 2; i < (stats + 2); i++)
  {
    SPI_BUFFER[i] = 0xFF;
  }
  
  Clear_CS();
  
  for(uint8_t i = 0; i < (stats + 2); i++)
  {
    SSC_Write(SPI_BUFFER[i]);
  }
  
  while (SSC_RX_FIFO_BUFFER_COUNT < (stats + 2))  {}
  
  Set_CS();
  
  /* read command */
  temp2 = SSC_READ();
  
  if(temp == temp2)
  {
    temp = SSC_READ();
    
    data[0] = temp;
    
    if(true == stats)
    {
      temp = SSC_READ();
      
      ret = tle5012b_CheckStat(temp);
      volatile uint8_t temp22 = tle5012b_crc8(temp2, (uint8_t *)&data[0], 2);
      if(((temp & 0xFF) != temp22) && (NO_ERROR == ret))
      {
        ret = CRC_ERROR;
      }
    }
  }else{
    ret = SSC_ERROR;
  }
  
  return ret;
}

e_errorTypes_t tle5012b_CheckStat(uint16_t data)
{
  if(false == (data & (1 << 12))){return INVALID_ANGLE_ERROR;}
  if(false == (data & (1 << 13))){return INTERFACE_ACCESS_ERROR;}
  if(false == (data & (1 << 14))){return SYSTEM_ERROR;}

  //CRC_ERROR
//todo add crc check
  return  NO_ERROR;
}

e_errorTypes_t tle5012b_UpdateAll()
{
  e_errorTypes_t ret = NO_ERROR;
  ret |= tle5012b_ReadDataArray(0, 15, &tle5012b_Register.registers[0], true);
  ret |= tle5012b_ReadDataArray(15, 15, &tle5012b_Register.registers[15], true);
  ret |= tle5012b_ReadDataArray(30, 15, &tle5012b_Register.registers[30], true);
  ret |= tle5012b_ReadDataArray(45, 3, &tle5012b_Register.registers[45], true);

  if(ret == NO_ERROR)
  {
    synched = true;
  }

  return ret;
}

e_interfaceType_t tle5012b_GetInterfaceType()
{
//TODO
  e_errorTypes_t ret = NO_ERROR;
  
  return ret;
}

e_errorTypes_t tle5012b_SetInterfaceType(e_interfaceType_t iface)
{
//TODO
  e_errorTypes_t ret = NO_ERROR;

  return ret;
}

e_errorTypes_t tle5012b_ResetFirmware()
{
  e_errorTypes_t ret = NO_ERROR;

  tle5012b_WriteRegister(REG_ACSTAT, 0x0401);

  if(NO_ERROR == ret)
  {
    synched = false;
  }

  return ret;
}

e_errorTypes_t tle5012b_SetAutoCal(e_calibrationMode_t calMode)
{
  e_errorTypes_t ret = NO_ERROR;
  
  ret |= tle5012b_ReadRegister(REG_MOD_2, false);
  tle5012b_Register.mod2.AUTOCAL = calMode;
  ret |= tle5012b_WriteRegister(REG_MOD_2, tle5012b_Register.mod2.reg);
  
  ret |= tle5012b_UpdateCRC();
  
  // clear system error flag, was expected because crc is wrong
  ret = ret & ~(SYSTEM_ERROR);
  
  // read status to clear possible wrong STAT flags
  tle5012b_ReadRegister(REG_STAT, false);
  ret |= tle5012b_ReadRegister(REG_STAT, false);
  
  return ret;
}

e_errorTypes_t tle5012b_SetZeroPos(void)
{
  e_errorTypes_t ret = NO_ERROR;
  int16_t ang_val;
  int16_t ang_base;
  int16_t ang_base_new;
  uint8_t calibration;

  // auto cal  = off
  // Ignore return value as CRC will will be wrong and throw system error flag to be set
  tle5012b_ReadRegister(REG_MOD_2, false);
  calibration = tle5012b_Register.mod2.AUTOCAL;
  tle5012b_Register.mod2.AUTOCAL = 0;
  ret |= tle5012b_WriteRegister(REG_MOD_2, tle5012b_Register.mod2.reg);

  // read angel values
  ret |= tle5012b_ReadRegister(REG_AVAL, false);
  ret |= tle5012b_ReadRegister(REG_MOD_2, false);
  ret |= tle5012b_ReadRegister(REG_MOD_3, false);

  ang_val  = tle5012b_Register.aval.ANG_VAL << 1;
  ang_base = tle5012b_Register.mod3.reg & 0xFFF0;

  if(tle5012b_Register.mod2.ANG_DIR == 0)
  {
    ang_base_new = (ang_base - ang_val) & 0xFFF0;
  }else{
    ang_base_new = (ang_base + ang_val) & 0xFFF0;
  }

  tle5012b_Register.mod3.ANG_BASE = ang_base_new >> 4;

  ret |= tle5012b_WriteRegister(REG_MOD_3, tle5012b_Register.mod3.reg);
  ret |= tle5012b_ReadRegister(REG_MOD_3, false);

  if((tle5012b_Register.mod3.reg & 0xFFF0) != (uint16_t)ang_base_new)
  {
    Cy_SCB_UART_PutString(DEBUG_UART_HW, "TLE5012 MOD_3 Error: ");

    itoa(tle5012b_Register.mod3.reg, (char *)&UART_Buffer, 16);
    Cy_SCB_UART_PutArray(DEBUG_UART_HW, &UART_Buffer, 4);

    Cy_SCB_UART_Put(DEBUG_UART_HW, '-');

    itoa(ang_base_new, (char *)&UART_Buffer, 16);
    Cy_SCB_UART_PutArray(DEBUG_UART_HW, &UART_Buffer, 4);

    Cy_SCB_UART_Put(DEBUG_UART_HW, '\r');
    Cy_SCB_UART_Put(DEBUG_UART_HW, '\n');

    ret = WRITE_ERROR;
  }

  // auto cal  = on
  tle5012b_Register.mod2.AUTOCAL = calibration;
  ret |= tle5012b_WriteRegister(REG_MOD_2, tle5012b_Register.mod2.reg);
  // calculate new CRC
  ret |= tle5012b_UpdateCRC();

  // clear system error flag, was expected because crc is wrong
  ret = ret & ~(SYSTEM_ERROR);

  // read status to clear possible wrong STAT flags
  tle5012b_ReadRegister(REG_STAT, false);
  ret |= tle5012b_ReadRegister(REG_STAT, false);

  return ret;
}

e_errorTypes_t tle5012b_UpdateCRC(void)
{
  uint8_t crc = tle5012b_crc8(tle5012b_Register.mod2.reg, (uint8_t *)&tle5012b_Register.mod3.reg, 13);
  tle5012b_Register.tcoy.CRC_PAR = crc;

  return tle5012b_WriteRegister(REG_TCO_Y, tle5012b_Register.tcoy.reg);
}
