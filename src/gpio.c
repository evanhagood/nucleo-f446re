/************************************************
 * gpio.c 
 * 
 * Implementation for easy pin manipulation
 * 
 * @author Evan Hagood
 * @date 6/18/2025
 */

#include "gpio.h"
#include "memory_map.h"
#include "rcc.h"

typedef struct {
    volatile uint32_t MODER;    // port mode register; offset: 0x00
    volatile uint32_t OTYPER;   // port output type register; offset: 0x04
    volatile uint32_t OSPEEDR;  // port output speed register; offset: 0x08
    volatile uint32_t PUPDR;    // port pull-up / pull-down register; offset: 0x0C
    volatile uint32_t IDR;      // port input data register; offset: 0x10
    volatile uint32_t ODR;      // port output data register; offset: 0x14
    volatile uint32_t BSRR;     // bit set/reset register; offset: 0x18
} GPIO_TypeDef;

#define GPIO(port) ((GPIO_TypeDef*) (port))

void gpio_init(GPIO_Port port, uint8_t pin, gpio_mode_t mode, gpio_pull_t pull, gpio_speed_t speed) {
    rcc_enable_gpio(port);

    GPIO_TypeDef* gpio = GPIO(port);

    // clear and set each bitfield
    gpio -> MODER &= ~(0x03 << (pin * 2)); // each pin has two bits in the register; 0x03 == 0b11
    gpio -> MODER |= (mode << (pin * 2));

    gpio -> PUPDR &= ~(0x03 << (pin * 2));
    gpio -> PUPDR |= (pull << (pin * 2));

    gpio -> OSPEEDR &= ~(0x03 << (pin * 2));
    gpio -> OSPEEDR |= (speed << (pin * 2));

    // TODO: add support to set OTYPE like the rest
    // we don't need this now, and I kinda don't know what it is, but I know I don't need it yet.
    gpio -> OTYPER &= ~(1 << pin);
}

void gpio_write(GPIO_Port port, uint8_t pin, uint8_t state) {
    GPIO_TypeDef *gpio = GPIO(port);
    if(state) {
        gpio -> BSRR = (1 << pin);
    } else gpio -> BSRR = (1 << (pin + 16)); // top half of register
}

uint8_t gpio_read(GPIO_Port port, uint8_t pin) {
    GPIO_TypeDef *gpio = GPIO(port);
    return (gpio -> IDR & (1 << pin)) != 0;
}