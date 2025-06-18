/************************************************
 * rcc.h 
 * 
 * Declaration file for Reset and Clock Control module for the STM32. 
 * 
 * More functions are to be added to this module as needed in this project, right now only
 * - GPIOA
 * - Timer2
 * are supported.
 * 
 * @author Evan Hagood
 * @date 6/18/2025
 */

#ifndef RCC_H
#define RCC_H

void rcc_enable_gpioa(void);
void rcc_enable_timer2(void);


#endif // RCC_H