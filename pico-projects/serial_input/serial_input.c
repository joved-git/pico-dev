#include <stdio.h>
#include "pico/stdlib.h"


#define LED_ON  1
#define LED_OFF 0

int main() {
    char inputChar;
    //int inputChar;

    /* Initialize I/O   */
    stdio_init_all();

    /* Initialize GPIO - Led is connected to pin 25     */
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    gpio_put(25, LED_ON);
    sleep_ms(100);
    gpio_put(25, LED_OFF);
    sleep_ms(100);
    gpio_put(25, LED_ON);
    sleep_ms(100);
    gpio_put(25, LED_OFF);
    sleep_ms(100);

    printf("Ready to operate !\n");

    /* Infinite loop    */
    while (1) {
        /* Get the user input   */
        printf("Command (1 = on or 0 = off)\n");

        /* Read the char    */
        inputChar = getchar();
        //scanf("%c", &inputChar);

        if (inputChar == '1') {
            gpio_put(25, LED_ON);
            printf("Led switch to on !\n");
        }

        if (inputChar == '0') {
            gpio_put(25, LED_OFF);
            printf("Led switch to off !\n");
        }
        
        /* Then wait    */
        //sleep_ms(1000);
    }

}