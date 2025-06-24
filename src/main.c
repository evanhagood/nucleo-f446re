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
#include "memory_map.h"
#include "gpio.h"
#include "rcc.h"

volatile int delay()
{
    for (volatile int i = 0; i < 1000000; i++)
    {
        __asm__ volatile("nop");
    }
    return 0;
}

int main(void) {
    // set GPIOA pin 5 to general output (this function enables RCC)
    gpio_init(GPIO_PORT_A, 5, GPIO_MODE_OUTPUT, GPIO_NO_PULL, GPIO_SPEED_LOW);

    while(1) {
        gpio_write(GPIO_PORT_A, 5, 0);
        delay();
        gpio_write(GPIO_PORT_A, 5, 1);
        delay();
    }
}


void SystemInit(void) {
    // also stubbed out for vendor start up, not used here.
}

void __libc_init_array(void) {
    // stubbed out for the vendor startup script, not used here.
}