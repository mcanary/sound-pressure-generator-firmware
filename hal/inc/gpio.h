

#include <stdint.h>


/* GPIO register offsets */
#define GPIO_MODER      0x00
#define GPIO_OTYPER     0x04
#define GPIO_OSPEEDR    0x08
#define GPIO_PUPDR      0x0c
#define GPIO_IDR        0x10
#define GPIO_ODR        0x14
#define GPIO_AFRL       0x20
#define GPIO_AFRH       0x24


/* Port and pin enumerations */
#define GPIO_PORTA      0x40020000
#define GPIO_PORTB      0x40020400
#define GPIO_PORTC      0x40020800
#define GPIO_PORTD      0x40020c00
#define GPIO_PORTE      0x40021000
#define GPIO_PORTH      0x40021c00

#define GPIO_PIN_0      0x0
#define GPIO_PIN_1      0x1
#define GPIO_PIN_2      0x2
#define GPIO_PIN_3      0x3
#define GPIO_PIN_4      0x4
#define GPIO_PIN_5      0x5
#define GPIO_PIN_6      0x6
#define GPIO_PIN_7      0x7
#define GPIO_PIN_8      0x8
#define GPIO_PIN_9      0x9
#define GPIO_PIN_10     0xa
#define GPIO_PIN_11     0xb
#define GPIO_PIN_12     0xc
#define GPIO_PIN_13     0xd
#define GPIO_PIN_14     0xe
#define GPIO_PIN_15     0xf


/* GPIO State Enumerations */
#define GPIO_MODE_INPUT                 0x0
#define GPIO_MODE_GPO                   0x1
#define GPIO_MODE_ALTERNATE_FUNCTION    0x2
#define GPIO_MODE_ANALOG                0x3

#define GPIO_OUTPUT_TYPE_PUSH_PULL      0x0
#define GPIO_OUTPUT_TYPE_OPEN_DRAIN     0x1

#define GPIO_OUTPUT_SPEED_LOW           0x0
#define GPIO_OUTPUT_SPEED_MEDIUM        0x1
#define GPIO_OUTPUT_SPEED_FAST          0x2
#define GPIO_OUTPUT_SPEED_HIGH          0x3

#define GPIO_PUPD_NONE                  0x0
#define GPIO_PUPD_PULL_UP               0x1
#define GPIO_PUPD_PULL_DOWN             0x2


/* Typedefs */
typedef struct gpio_init_struct {
    uint8_t mode;
    uint8_t output_type;
    uint8_t output_speed;
    uint8_t pull_up_pull_down;
}gpio_init_struct;


/* Function prototypes */
void gpio_init(uint32_t port, uint8_t pin, gpio_init_struct * init_struct);
uint8_t gpio_read(uint32_t port, uint8_t pin);
void gpio_reset(uint32_t port, uint8_t pin);
void gpio_set(uint32_t port, uint8_t pin);

