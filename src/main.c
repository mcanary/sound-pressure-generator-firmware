

#include "main.h"


int main() {

    system_init();

    // Turn on LEDs
    gpio_set(GPIO_PORTD, GPIO_PIN_12);
    gpio_set(GPIO_PORTD, GPIO_PIN_13);
    gpio_reset(GPIO_PORTD, GPIO_PIN_12);
    gpio_reset(GPIO_PORTD, GPIO_PIN_13);

    gpio_set(GPIO_PORTD, GPIO_PIN_14);
    gpio_set(GPIO_PORTD, GPIO_PIN_15);

    uint32_t counter = 0;
    bool led_on_flag = false;

    while (1)
    {
    	if (counter == (0x0008ffff))
    	{
    	    if (led_on_flag)
    	    {
    	        gpio_reset(GPIO_PORTD, GPIO_PIN_12);
    	        gpio_reset(GPIO_PORTD, GPIO_PIN_13);
    	        led_on_flag = false;
    	    }
    	    else
    	    {
    	        gpio_set(GPIO_PORTD, GPIO_PIN_12);
    	        gpio_set(GPIO_PORTD, GPIO_PIN_13);
    	        led_on_flag = true;
    	    }
    	    counter = 0;
    	}
    	counter++;
    }

}

