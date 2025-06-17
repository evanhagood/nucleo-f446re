/**********************************************************
 * main.c 
 * Simple bare-metal implementation for a blink on the STM32F446RE dev board
 * 
 * LD2 user LED is connected to PA5, GPIOA
 * 
 * @author Evan Hagood
 * @date 6/17/2025
*/
#include <stdint.h>
#define GPIOA_BASE      0x40020000
#define GPIOA_MODER     (*(volatile uint32_t*)(GPIOA_BASE + 0x0)) // GPIO port mode register
#define GPIOA_ODR       (*(volatile uint32_t*)(GPIOA_BASE + 0x14)) // GPIO port output data register
#define RCC_BASE        0x40023800
#define RCC_AHB1ENR     (*(volatile uint32_t*)(RCC_BASE + 0x30))

/**********************************************************
 * void delay(void)
 * 
 * busy waits the MCU for about a second
 * 
 * @param void
 * @return void
 */
static void delay(void) {
    for (volatile int i = 0; i < 100000; i++);
}

int main(void) {
    // enable RCC clock for GPIO
    RCC_AHB1ENR |= (1 << 0);
    // set GPIOA pin 5 to general output
    GPIOA_MODER &= ~(0x3 << (5 * 2)); // clear pin 5
    GPIOA_MODER |= (0x1 << (5 * 2)); // set pin 5 to 0b01

    while(1) {
        // turn on PA5
        GPIOA_ODR |= (1 << 5);
        delay();
        // turn off PA5
        GPIOA_ODR &= ~(1 << 5);
        delay();
    }
}


void SystemInit(void) {
    // also stubbed out for vendor start up, not used here.
}

void __libc_init_array(void) {
    // stubbed out for the vendor startup script, not used here.
}