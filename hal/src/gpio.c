

#include "gpio.h"


void gpio_init(uint32_t port, uint8_t pin, gpio_init_struct * init_struct) {

    volatile uint32_t * mode_register = (uint32_t *) (port + GPIO_MODER);
    volatile uint32_t * otype_register = (uint32_t *) (port + GPIO_OTYPER);
    volatile uint32_t * ospeed_register = (uint32_t *) (port + GPIO_OSPEEDR);
    volatile uint32_t * pupd_register = (uint32_t *) (port + GPIO_PUPDR);

    uint32_t mode = * mode_register & ~(0x3 << (2 * pin));
    uint32_t otype = * otype_register & ~(0x1 << pin);
    uint32_t ospeed = * ospeed_register & ~(0x3 << (2 * pin));
    uint32_t pupd = * pupd_register & ~(0x3 << (2 * pin));

    mode = mode | (init_struct->mode << (0x2 * pin));
    otype = otype | (init_struct->output_type << pin);
    ospeed = ospeed | (init_struct->output_speed << (0x2 * pin));
    pupd = pupd | (init_struct->pull_up_pull_down << (0x2 * pin));

    * mode_register = mode;
    * otype_register = otype;
    * ospeed_register = ospeed;
    * pupd_register = pupd;

}

uint8_t gpio_read(uint32_t port, uint8_t pin) {

    volatile uint32_t * id_register = (uint32_t *) (port + GPIO_IDR);
    return ((* id_register & (0x1 << pin)) >> pin);
    
}

void gpio_reset(uint32_t port, uint8_t pin) {

    volatile uint32_t * od_register = (uint32_t *) (port + GPIO_ODR);
    * od_register = * od_register & ~(0x1 << pin);

}

void gpio_set(uint32_t port, uint8_t pin) {

    volatile uint32_t * od_register = (uint32_t *) (port + GPIO_ODR);
    * od_register = * od_register | (0x1 << pin);

}

