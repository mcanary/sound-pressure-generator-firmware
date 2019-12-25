

#include "system_init.h"


gpio_init_struct gpio_led_config = {
    .mode = GPIO_MODE_GPO,
    .output_type = GPIO_OUTPUT_TYPE_PUSH_PULL,
    .output_speed = GPIO_OUTPUT_SPEED_HIGH,
    .pull_up_pull_down = GPIO_PUPD_NONE
};


rcc_main_pll_init_struct main_pll_config = {
    .pll_m = 4,
    .pll_n = 192,
    .pll_p = 4,
    .pll_source = RCC_PLL_SOURCE_HSE,
    .pll_q = 8
};


rcc_clock_init_struct clock_config = {
    .system_clock = RCC_SYS_CLK_PLL,
    .i2s_clock = RCC_I2S_CLK_PLLI2S,
    .ahb_prescaler = 1,
    .apb1_prescaler = 4,
    .apb2_prescaler = 1,
    .rtc_prescaler = 8,
    .clock_output_1 = RCC_MCO1_SOURCE_HSE,
    .clock_output_2 = RCC_MCO2_SOURCE_HSE,
    .mco1_prescaler = 5,
    .mco2_prescaler = 5
};


rcc_i2s_pll_init_struct i2s_pll_config = {
    .i2s_pll_m = 5,
    .i2s_pll_n = 200,
    .i2s_pll_r = 2
};


void system_init()
{

    // Initialize system clock to 98MHz
    // flash_set_latency(3);
    // rcc_enable_hse();
    // rcc_main_pll_init(&main_pll_config);
    // rcc_i2s_pll_init(&i2s_pll_config);
    // rcc_enable_main_pll();
    // rcc_clock_init(&clock_config);

    // Enable AHB bus clock
    rcc_ahb1_enable(RCC_AHB1_GPIOD);

    // Initialize LED GPIOs
    gpio_init(GPIO_PORTD, GPIO_PIN_12, &gpio_led_config);
    gpio_init(GPIO_PORTD, GPIO_PIN_13, &gpio_led_config);
    gpio_init(GPIO_PORTD, GPIO_PIN_14, &gpio_led_config);
    gpio_init(GPIO_PORTD, GPIO_PIN_15, &gpio_led_config);

}


