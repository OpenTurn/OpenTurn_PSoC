/*
 * DebugUart.c
 *
 *  Created on: 20.02.2021
 *      Author: achim
 */

#include "DebugUart.h"

cy_stc_scb_uart_context_t DebugUart_context;

/* Populate configuration structure (code specific for CM4) */
const cy_stc_sysint_t uartIntrConfig =
{
    .intrSrc      = DebugUart_INTR_NUM,
    .intrPriority = DebugUart_INTR_PRIORITY,
};

void DebugUart_Isr(void)
{
    Cy_SCB_UART_Interrupt(DebugUartSCB, &DebugUart_context);
}


void DebugUartInit(void)
{
    // UART Init
    Cy_SCB_UART_Init(DebugUartSCB, &DebugUartConfig, &DebugUart_context);
    Cy_SCB_UART_Enable(DebugUartSCB);

    (void) Cy_SysInt_Init(&uartIntrConfig, &DebugUart_Isr);
    NVIC_EnableIRQ(uartIntrConfig.intrSrc);
}


void PrintDebugI32(int32_t data) {
#ifdef UART_DEBUG
  char value[14];

  itoa(data, value, 10);

  Cy_SCB_UART_PutString (DebugUartSCB, value);
#endif /* UART_DEBUG */
  return;
}

void PrintDebugU32(uint32_t data) {
#ifdef UART_DEBUG
  char value[14];

  utoa(data, value, 10);

  Cy_SCB_UART_PutString (DebugUartSCB, value);
#endif /* UART_DEBUG */
  return;
}

void PrintDebugH32(uint32_t data) {
#ifdef UART_DEBUG
  char value[10];

  utoa(data, value, 16);

  Cy_SCB_UART_PutString (DebugUartSCB, value);
#endif /* UART_DEBUG */
  return;
}

void PrintDebugI16(int16_t data) {
#ifdef UART_DEBUG
  char value[8];

  itoa(data, value, 10);

  Cy_SCB_UART_PutString (DebugUartSCB, value);
#endif /* UART_DEBUG */
  return;
}

void PrintDebugU16(uint16_t data) {
#ifdef UART_DEBUG
  char value[8];

  utoa(data, value, 10);

  Cy_SCB_UART_PutString (DebugUartSCB, value);
#endif /* UART_DEBUG */
  return;
}

void PrintDebugH16(uint16_t data) {
#ifdef UART_DEBUG
  char value[8];

  utoa(data, value, 16);

  Cy_SCB_UART_PutString (DebugUartSCB, value);
#endif /* UART_DEBUG */
  return;
}

void PrintDebugI8(int8_t data) {
#ifdef UART_DEBUG
  char value[6];

  itoa(data, value, 10);

  Cy_SCB_UART_PutString (DebugUartSCB, value);
#endif /* UART_DEBUG */
  return;
}

void PrintDebugU8(uint8_t data) {
#ifdef UART_DEBUG
  char value[6];

  utoa(data, value, 10);

  Cy_SCB_UART_PutString (DebugUartSCB, value);
#endif /* UART_DEBUG */
  return;
}

void PrintDebugH8(uint8_t data) {
#ifdef UART_DEBUG
  char value[4];

  utoa(data, value, 16);

  Cy_SCB_UART_PutString (DebugUartSCB, value);
#endif /* UART_DEBUG */
  return;
}

void PrintDebugFloat(float data, uint8_t fraction) {
#ifdef UART_DEBUG
	char value[14];
	char value_tmp[14];
	float data_cp = data;

	if(data_cp < 0)
	{
		PrintDebugCharBlocking('-');
		data = data * -1.0f;
	}

	volatile union u_temp{
		float ftemp;
		uint32_t u32temp;
	}temp;
	temp.ftemp = data;

	switch(fraction)
	{
	  case 1:
			  asm("VCVT.U32.F32 %0, %1, 1" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 2:
			  asm("VCVT.U32.F32 %0, %1, 2" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 3:
			  asm("VCVT.U32.F32 %0, %1, 3" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 4:
			  asm("VCVT.U32.F32 %0, %1, 4" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 5:
			  asm("VCVT.U32.F32 %0, %1, 5" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 6:
			  asm("VCVT.U32.F32 %0, %1, 6" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 7:
			  asm("VCVT.U32.F32 %0, %1, 7" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 8:
			  asm("VCVT.U32.F32 %0, %1, 8" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 9:
			  asm("VCVT.U32.F32 %0, %1, 9" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 10:
			  asm("VCVT.U32.F32 %0, %1, 10" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 11:
			  asm("VCVT.U32.F32 %0, %1, 11" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 12:
			  asm("VCVT.U32.F32 %0, %1, 12" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 13:
			  asm("VCVT.U32.F32 %0, %1, 13" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 14:
			  asm("VCVT.U32.F32 %0, %1, 14" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 15:
			  asm("VCVT.U32.F32 %0, %1, 15" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 16:
			  asm("VCVT.U32.F32 %0, %1, 16" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 17:
			  asm("VCVT.U32.F32 %0, %1, 17" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 18:
			  asm("VCVT.U32.F32 %0, %1, 18" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 19:
			  asm("VCVT.U32.F32 %0, %1, 19" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 20:
			  asm("VCVT.U32.F32 %0, %1, 20" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 21:
			  asm("VCVT.U32.F32 %0, %1, 21" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 22:
			  asm("VCVT.U32.F32 %0, %1, 22" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 23:
			  asm("VCVT.U32.F32 %0, %1, 23" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 24:
			  asm("VCVT.U32.F32 %0, %1, 24" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 25:
			  asm("VCVT.U32.F32 %0, %1, 25" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 26:
			  asm("VCVT.U32.F32 %0, %1, 26" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 27:
			  asm("VCVT.U32.F32 %0, %1, 27" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 28:
			  asm("VCVT.U32.F32 %0, %1, 28" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 29:
			  asm("VCVT.U32.F32 %0, %1, 29" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 30:
			  asm("VCVT.U32.F32 %0, %1, 30" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	  case 31:
			  asm("VCVT.U32.F32 %0, %1, 31" : "=t" (temp.u32temp) : "t" (temp.ftemp));
		  break;
	}


	utoa(temp.u32temp >> fraction, value, 10);
	Cy_SCB_UART_PutString(DebugUartSCB, value);

  uint64_t temp2 = 0;
  uint64_t pow10[8] = {1,
            10,
            100,
            1000,
            10000,
            100000,
            1000000,
            10000000,
            100000000};

	temp2 = temp.u32temp & ((1 << fraction) - 1);
	if(fraction > 7)
	{
	  temp2 = (temp2 >> (fraction - 7));
	  fraction = 7;
	}
	temp2 = ((temp2 * pow10[fraction]) >> fraction);

	utoa(temp2, value_tmp, 10);
	utoa(pow10[fraction], value, 10);
	value[0] = '0';

	strcpy(&value[sizeof(value_tmp)-fraction], &value_tmp[0]);

	PrintDebugCharBlocking('.');
	Cy_SCB_UART_PutString(DebugUartSCB, value);
#endif /* UART_DEBUG */
	return;
}
