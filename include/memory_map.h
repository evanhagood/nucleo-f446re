/**********************************************************
 * memory_map.h
 *
 * Macro definitions for memory-mapped peripheral addresses
 * and enumerations for GPIO port selection.
 *
 * @author Evan Hagood
 * @date 6/18/2025
 **********************************************************/

#ifndef MEM_MAP_H
#define MEM_MAP_H

#include <stdint.h>

/**********************************************************
 * RCC (Reset and Clock Control)
 **********************************************************/

#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x30)) // AHB1 peripheral clock enable
#define RCC_APB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x40)) // APB1 peripheral clock enable

/**********************************************************
 * GPIO Base Addresses
 **********************************************************/
#define GPIOA_BASE 0x40020000
#define GPIOB_BASE 0x40020400
#define GPIOC_BASE 0x40020800
#define GPIOD_BASE 0x40020C00
#define GPIOE_BASE 0x40021000
#define GPIOF_BASE 0x40021400
#define GPIOG_BASE 0x40021800
#define GPIOH_BASE 0x40021C00

/**********************************************************
 * GPIOA Specific Registers
 **********************************************************/
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_BASE + 0x00)) // Mode register
#define GPIOA_ODR (*(volatile uint32_t *)(GPIOA_BASE + 0x14))   // Output data register

/**********************************************************
 * GPIO Port Enum
 **********************************************************/
typedef enum
{
    GPIO_PORT_A = GPIOA_BASE,
    GPIO_PORT_B = GPIOB_BASE,
    GPIO_PORT_C = GPIOC_BASE,
    GPIO_PORT_D = GPIOD_BASE,
    GPIO_PORT_E = GPIOE_BASE,
    GPIO_PORT_F = GPIOF_BASE,
    GPIO_PORT_G = GPIOG_BASE,
    GPIO_PORT_H = GPIOH_BASE
} GPIO_Port;

#endif // MEM_MAP_H
