/************************************************
 * rcc.c 
 * 
 * Implementation for the Reset and Clock Control module on the STM32
 * 
 * @author Evan Hagood
 * @date 6/18/2025
 */

#include "rcc.h"
#include "memory_map.h"
#include <stdint.h>


/************************************************
 * void rcc_enable_gpioa(rcc_gpio_port_t port)
 * 
 * @brief Enables the clock for GPIOA
 * @param GPIO Port (see rcc.h for definition)
 */
void rcc_enable_gpio(rcc_gpio_port_t port) {
    if(port > GPIO_PORT_H) return;
    RCC_AHB1ENR |= (1 << port);
}

/************************************************
 * void rcc_enable_timer2(void)
 *
 * @brief Enables the clock for TIM2
 */
void rcc_enable_timer2(void) {
    RCC_APB1ENR |= (1 << 0); // TIM2 = bit 0
}