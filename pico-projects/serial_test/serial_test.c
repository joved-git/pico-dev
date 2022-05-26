#include "pico/stdlib.h"
#include <stdio.h>

#define LED_ON  1
#define LED_OFF 0

int main() {
    /* Initialize I/O   */
    stdio_init_all();

    /* Initialize GPIO - Led is connected to pin 25     */
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    /* Infinite loop    */
    while (1) {
        /* Led is on 3 times    */
        printf("LED is blinking\n");
        gpio_put(25, LED_ON);
        sleep_ms(100);
        gpio_put(25, LED_OFF);
        sleep_ms(100);
        gpio_put(25, LED_ON);
        sleep_ms(100);
        gpio_put(25, LED_OFF);
        sleep_ms(100);
        gpio_put(25, LED_ON);
        sleep_ms(100);
        gpio_put(25, LED_OFF);

        printf("LED is off\n");
        
        /* Then wait    */
        sleep_ms(1000);
    }

}