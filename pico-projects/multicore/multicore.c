#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/irq.h"
#include "hardware/adc.h"

#define LED_ON  1
#define LED_OFF 0

/* Core 1 interrupt handler */
void core1_interrupt_handler() {
    /* Receive raw value. Convert and print temperature over USB serial */
    /* Executed each time Core 0 send data into the Fifo              */
    while(multicore_fifo_rvalid()) {
        uint16_t raw = multicore_fifo_pop_blocking();
        const float conversion_factor = 3.3f / (1<<12);

        float result = raw * conversion_factor;
        float temp = 27 - (result- 0.706)/0.001721;

        printf("Temp = %f C\n", temp);
    }

    /* Clear interrupt  */
    multicore_fifo_clear_irq();
}

/* Core 1 main code */
void core1_entry() {
    /* Configure Core 1 interrupt   */
    multicore_fifo_clear_irq();
    irq_set_exclusive_handler(SIO_IRQ_PROC1, core1_interrupt_handler);
    irq_set_enabled(SIO_IRQ_PROC1, true);

    /* Infinite loop which waits for interrupt  */
    while (1) {
        tight_loop_contents();
    }

}

/***************************************************************************/
/* Core 0 main code */
int main() {
    /* Initialize I/O   */
    stdio_init_all();

    /* launch Core 1 - Must be called before configuring interrupt    */
    multicore_launch_core1(core1_entry);

    /* Configure ADC    */
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);

    /* Primary Core 0 loop  */
    while (1) {
            uint16_t raw = adc_read();
            multicore_fifo_push_blocking((uint32_t) raw);
            sleep_ms(1000);
    }
}