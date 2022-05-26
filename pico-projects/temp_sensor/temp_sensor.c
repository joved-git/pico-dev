#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/irq.h"
#include "hardware/adc.h"

#define LED_ON  1
#define LED_OFF 0

/***************************************************************************/
/* Core 0 main code */
int main() {
    /* Initialize I/O   */
    stdio_init_all();

    /* Configure ADC    */
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);

    /* Primary Core 0 loop  */
    while (1) {
            uint16_t raw = adc_read();
            
            const float conversion = 3.3f / (1<<12);    /* 3.3 V under 12-bit value */

            float voltage = raw * conversion;
            float temperature = 27 - (voltage- 0.706)/0.001721;

            printf("Temp = %f C\n", temperature);
            sleep_ms(1000);
    }
}