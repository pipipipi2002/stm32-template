#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#define LED_LD2_PIN GPIO7
#define LED_LD2_PORT GPIOB

static void main_rcc_setup(void) {
    /* Set System frequency to 72 MHz */
    rcc_clock_setup_hse(&rcc_3v3[RCC_CLOCK_3V3_72MHZ], 8);
}

static void main_gpio_setup(void) {
    /* Enable clock on GPIOB */
    rcc_periph_clock_enable(RCC_GPIOB); 

    /* Set pin mode output for LD2 (blue led)*/
    gpio_mode_setup(LED_LD2_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_LD2_PIN);
}

static void main_delay_cycles(uint32_t u32DelayCycles) {
    while (u32DelayCycles--) {
        __asm__("nop");
    }
}

int main(void) {
    main_rcc_setup();
    main_gpio_setup();

    while (1) {
        gpio_toggle(LED_LD2_PORT, LED_LD2_PIN);
        main_delay_cycles(72000000 / 4);
    }
    return 0;
}