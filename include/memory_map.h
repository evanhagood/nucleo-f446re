/**********************************************************
 * memory_map.h 
 * 
 * macro definitions for memory locations of different peripherals
 */

#ifndef MEM_MAP_H
#define MEM_MAP_H

// Reset and Clock Control
#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x30)) // rcc adv high performance bus ENABLE
#define RCC_APB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x40)) // rcc adb peripheral bus ENABLE

// GPIOA
#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_BASE + 0x0)) // GPIOA port mode register
#define GPIOA_ODR (*(volatile uint32_t *)(GPIOA_BASE + 0x14))  // GPIOA port output data register

#endif // MEM_MAP_H