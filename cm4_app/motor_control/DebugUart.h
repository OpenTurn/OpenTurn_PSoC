/*
 * DebugUart.h
 *
 *  Created on: 20.02.2021
 *      Author: achim
 */



#ifndef MOTOR_CONTROL_DEBUGUART_H_
#define MOTOR_CONTROL_DEBUGUART_H_
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"

#include "stdint.h"
#include "stdlib.h"
#include "stdbool.h"
#include "resources.h"

#define UART_DEBUG

//Disable Debug messages
#define UART_ALARM
#define UART_ERROR
#define UART_WARNING
#define UART_INFO

#define DebugUartSCB                DEBUG_UART_HW
#define DebugUartConfig             DEBUG_UART_config
#define DebugUart_INTR_NUM          ((IRQn_Type) scb_2_interrupt_IRQn)
#define DebugUart_INTR_PRIORITY     (7U)

void DebugUartInit(void);

void PrintDebugI32(int32_t data);
void PrintDebugU32(uint32_t data);
void PrintDebugH32(uint32_t data);

void PrintDebugI16(int16_t data);
void PrintDebugU16(uint16_t data);
void PrintDebugH16(uint16_t data);

void PrintDebugI8(int8_t data);
void PrintDebugU8(uint8_t data);
void PrintDebugH8(uint8_t data);

void PrintDebugFloat(float data, uint8_t fraction);


#ifdef UART_DEBUG
    #define PrintDebug(str)                                 Cy_SCB_UART_PutString ((DebugUartSCB), str)
    #define PrintDebugChar(val)                             Cy_SCB_UART_Put ((DebugUartSCB), val)
    #define PrintDebugCharBlocking(val)                     while(0 == Cy_SCB_UART_Put ((DebugUartSCB), val)){}

#ifdef UART_ALARM

    #define PrintDebugAlarm(val)                            do{                         \
                                                                PrintDebug("\r\nALARM@");   \
                                                                PrintDebug(__FILE__);   \
                                                                PrintDebugChar(':');        \
                                                                PrintDebugU32(__LINE__);   \
                                                                PrintDebugChar(':');        \
                                                                PrintDebugH32(val);     \
                                                            }                           \
                                                            while(0)
#else
    #define PrintDebugAlarm(val)                            asm("")
#endif /*  UART_ALARM */

#ifdef UART_ERROR
    #define PrintDebugError(val)                            do{                         \
                                                               PrintDebug("\r\nError@");   \
                                                               PrintDebug(__FILE__);   \
                                                               PrintDebugChar(':');        \
                                                               PrintDebugU32(__LINE__);   \
                                                               PrintDebugChar(':');        \
                                                               PrintDebugH32(val);     \
                                                           }                           \
                                                           while(0)
#else
    #define PrintDebugError(val)                          asm("")
#endif /*  UART_ERROR */

#ifdef UART_WARNING
    #define PrintDebugWarning(val)                         do{                         \
                                                               PrintDebug("\r\nWarning@");   \
                                                               PrintDebug(__FILE__);   \
                                                               PrintDebugChar(':');        \
                                                               PrintDebugU32(__LINE__);   \
                                                               PrintDebugChar(':');        \
                                                               PrintDebugH32(val);     \
                                                           }                           \
														   while(0)

#else
    #define PrintDebugWarning(val)                          asm("")
#endif /*  UART_WARNING */

#ifdef UART_INFO
    #define PrintDebugInfo(val)                            do{                         \
                                                               PrintDebug("\r\nInfo@");   \
                                                               PrintDebug(__FILE__);   \
                                                               PrintDebugChar(':');        \
                                                               PrintDebugU32(__LINE__);   \
                                                               PrintDebugChar(':');        \
                                                               PrintDebugH32(val);     \
                                                           }                           \
														   while(0)
#else
    #define PrintDebugInfo(val)                          asm("")
#endif /* #ifdef UART_INFO */

    #define PrintDebugStrI32(str, val)                    PrintDebug(str); PrintDebugI32(val)
    #define PrintDebugStrU32(str, val)                    PrintDebug(str); PrintDebugU32(val)
    #define PrintDebugStrH32(str, val)                    PrintDebug(str); PrintDebugH32(val)

    #define PrintDebugStrI16(str, val)                    PrintDebug(str); PrintDebugI16(val)
    #define PrintDebugStrU16(str, val)                    PrintDebug(str); PrintDebugU16(val)
    #define PrintDebugStrH16(str, val)                    PrintDebug(str); PrintDebugH16(val)

    #define PrintDebugStrI8(str, val)                     PrintDebug(str); PrintDebugI8(val)
    #define PrintDebugStrU8(str, val)                     PrintDebug(str); PrintDebugU8(val)
    #define PrintDebugStrH8(str, val)                     PrintDebug(str); PrintDebugH8(val)

	  //#define PrintDebugStrFloat(str, val, frac)            PrintDebug(str); PrintDebugFloat(val, frac)
    #define PrintDebugStrFloat(str, val, frac)            PrintDebug(str); PrintDebug(ftoa(val, frac))

#else
    #define PrintDebug(str)                               asm("")
    #define PrintDebugChar(val)                           asm("")
    #define PrintDebugAlarm(val)                          asm("")
    #define PrintDebugError(val)                          asm("")
    #define PrintDebugWarning(val)                        asm("")
    #define PrintDebugInfo(val)                           asm("")

    #define PrintDebugStrI32(str, val)                    asm("")
    #define PrintDebugStrU32(str, val)                    asm("")
    #define PrintDebugStrH32(str, val)                    asm("")

    #define PrintDebugStrI16(str, val)                    asm("")
    #define PrintDebugStrU16(str, val)                    asm("")
    #define PrintDebugStrH16(str, val)                    asm("")

    #define PrintDebugStrI8(str, val)                     asm("")
    #define PrintDebugStrU8(str, val)                     asm("")
    #define PrintDebugStrH8(str, val)                     asm("")

	#define PrintDebugStrFloat(str, val, frac)            asm("")
#endif // DEBUG

#endif /* MOTOR_CONTROL_DEBUGUART_H_ */
