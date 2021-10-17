/*
 * led.c
 *
 *  Created on: 23.01.2021
 *      Author: achim
 */

#include "resources.h"

inline void LED0_ON(void)
{
    Cy_GPIO_Set(LED0_PORT, LED0_PIN);
}

inline void LED0_OFF(void)
{
    Cy_GPIO_Clr(LED0_PORT, LED0_PIN);
}

inline void LED0_TOGGLE(void)
{
    Cy_GPIO_Inv(LED0_PORT, LED0_PIN);
}

inline void LED1_ON(void)
{
    Cy_GPIO_Set(LED1_PORT, LED1_PIN);
}

inline void LED1_OFF(void)
{
    Cy_GPIO_Clr(LED1_PORT, LED1_PIN);
}

inline void LED1_TOGGLE(void)
{
    Cy_GPIO_Inv(LED1_PORT, LED1_PIN);
}




