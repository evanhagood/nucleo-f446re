/************************************************
 * gpio.h
 *
 * Sets up GPIO peripherals for the STM32
 *
 * @author Evan Hagood
 * @date 6/18/2025
 */

#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>
#include "memory_map.h"

typedef enum
{
    GPIO_MODE_INPUT     = 0x00,
    GPIO_MODE_OUTPUT    = 0x01,
    GPIO_MODE_AF        = 0x02, // alternate function mode, as fuck.
    GPIO_MODE_ANALOG    = 0x03
} gpio_mode_t;

typedef enum
{
    GPIO_TYPE_PUSHPULL  = 0x00,
    GPIO_TYPE_OPENDRAIN = 0x01
} gpio_type_t;

typedef enum
{
    GPIO_NO_PULL        = 0x00,
    GPIO_PULL_UP        = 0x01,
    GPIO_PULL_DOWN      = 0x02
} gpio_pull_t;

typedef enum
{
    GPIO_SPEED_LOW      = 0x00,
    GPIO_SPEED_MEDIUM   = 0x01,
    GPIO_SPEED_HIGH     = 0x02,
    GPIO_SPEED_VERYHIGH = 0x03
} gpio_speed_t;

void gpio_init(GPIO_Port port, uint8_t pin, gpio_mode_t mode, gpio_pull_t pull, gpio_speed_t speed);

/**
 * @brief Sets a GPIO pin to high or low.
 */
void gpio_write(GPIO_Port port, uint8_t pin, uint8_t value);

/**
 * @brief Toggles a GPIO pin.
 */
void gpio_toggle(GPIO_Port port, uint8_t pin);

/**
 * @brief Reads the state of a GPIO pin.
 * @retval 0 if low, non-zero if high
 */
uint8_t gpio_read(GPIO_Port port, uint8_t pin);

#endif // GPIO_H
