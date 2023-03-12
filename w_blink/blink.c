#include "pico/stdlib.h"
#include "pico/multicore.h"


/**
 * Uses two cores to turn on two different external LEDS at different frequencies.
*/

#define GPIO_ON true
#define GPIO_OFF false

#define LED_PIN_1 15
#define LED_PIN_2 16


void blinkSlow() {
    gpio_init(LED_PIN_1);
    gpio_set_dir(LED_PIN_1, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN_1, GPIO_ON);
        sleep_ms(500);
        gpio_put(LED_PIN_1, GPIO_OFF);
        sleep_ms(500);
    }
}

void blinkFast() {
    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN_2, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN_2, GPIO_ON);
        sleep_ms(100);
        gpio_put(LED_PIN_2, GPIO_OFF);
        sleep_ms(100);
    }
}

int main() {
    multicore_launch_core1(blinkFast);
    blinkSlow();
}