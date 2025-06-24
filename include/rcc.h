/************************************************
 * rcc.h 
 * 
 * Declaration file for Reset and Clock Control module for the STM32. 
 * 
 * More functions are to be added to this module as needed in this project, right now only
 * - GPIO, ports A - I
 * - Timer2
 * are supported.
 * 
 * @author Evan Hagood
 * @date 6/18/2025
 */

#ifndef RCC_H
#define RCC_H

typedef enum
{
    RCC_GPIO_PORT_A = 0,
    RCC_GPIO_PORT_B,
    RCC_GPIO_PORT_C,
    RCC_GPIO_PORT_D,
    RCC_GPIO_PORT_E,
    RCC_GPIO_PORT_F,
    RCC_GPIO_PORT_G,
    RCC_GPIO_PORT_H,
} rcc_gpio_port_t;

void rcc_enable_gpio(rcc_gpio_port_t port);
void rcc_enable_timer2(void);


#endif // RCC_H