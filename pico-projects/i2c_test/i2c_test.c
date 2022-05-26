#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define LED_ON  1
#define LED_OFF 0

#define I2C_PORT i2c0

static int addr = 0x68;

/* Board initialization */
void rtc_init() {
    /* Check to see if connection is correct - Read the CHIP_ID    */
    sleep_ms(1000);

/*
    uint8_t reg = 0x00;
    uint8_t chipId[1];
    i2c_write_blocking(I2C_PORT, addr, &reg, 1, true);
    i2c_read_blocking(I2C_PORT, addr, chipId, 1, false);

    if (chipId[0] != 0xA0) {
        printf("Chip Id is not correct - Check connection.\n");
        sleep_ms(5000);
    }
*/
    /* Init the board with some parameters here (if needed) */
}

int main() {
    uint8_t reg = 0x00;
    uint8_t second[1];

    /* Initialize I/O   */
    stdio_init_all();

    // Configure the I2C communication
    i2c_init(I2C_PORT, 400000);

    /* Initialize GPIO for I2C  */
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);
   
    /* Call the board initialization function   */
    rtc_init();

    /* Infinite loop    */
    while (1) {
        /* Read the number of seconds   */
        i2c_write_blocking(I2C_PORT, addr, &reg, 1, true);
        i2c_read_blocking(I2C_PORT, addr, second, 1, false);
        
        printf("sec = %d\n", second[0]);
        
        /* Then wait    */
        sleep_ms(1000);
    }

}