

#include <stdint.h>


/* RCC register offsets */
#define RCC_BASE        0x40023800

#define RCC_CR          0x00
#define RCC_PLLCFGR     0x04
#define RCC_CFGR        0x08
#define RCC_CIR         0x0c
#define RCC_AHB1RSTR    0x10
#define RCC_AHB2RSTR    0x14
#define RCC_APB1RSTR    0x20
#define RCC_APB2RSTR    0x24
#define RCC_AHB1ENR     0x30
#define RCC_AHB2ENR     0x34
#define RCC_APB1ENR     0x40
#define RCC_APB2ENR     0x44
#define RCC_AHB1LPENR   0x50
#define RCC_AHB2LPENR   0x54
#define RCC_APB1LPENR   0x60
#define RCC_APB2LPENR   0x64
#define RCC_BDCR        0x70
#define RCC_CSR         0x74
#define RCC_SSCGR       0x80
#define RCC_PLLI2SCFGR  0x84
#define RCC_DCKCFGR     0x8c


/* RCC State Enumerations */
#define RCC_PLL_SOURCE_HSI      0x0
#define RCC_PLL_SOURCE_HSE      0x1

#define RCC_SYS_CLK_HSI         0x0
#define RCC_SYS_CLK_HSE         0x1
#define RCC_SYS_CLK_PLL         0x2

#define RCC_AHB_PRESCALER_1     0x0
#define RCC_AHB_PRESCALER_2     0x8
#define RCC_AHB_PRESCALER_4     0x9
#define RCC_AHB_PRESCALER_8     0xa
#define RCC_AHB_PRESCALER_16    0xb
#define RCC_AHB_PRESCALER_64    0xc
#define RCC_AHB_PRESCALER_128   0xd
#define RCC_AHB_PRESCALER_256   0xe
#define RCC_AHB_PRESCALER_512   0xf

#define RCC_APB_PRESCALER_1     0x0
#define RCC_APB_PRESCALER_2     0x4
#define RCC_APB_PRESCALER_4     0x5
#define RCC_APB_PRESCALER_8     0x6
#define RCC_APB_PRESCALER_16    0x7

#define RCC_MCO1_SOURCE_HSI     0x0
#define RCC_MCO1_SOURCE_LSE     0x1
#define RCC_MCO1_SOURCE_HSE     0x2
#define RCC_MCO1_SOURCE_PLL     0x3

#define RCC_MCO2_SOURCE_SYSCLK  0x0
#define RCC_MCO2_SOURCE_PLLI2S  0x1
#define RCC_MCO2_SOURCE_HSE     0x2
#define RCC_MCO2_SOURCE_PLL     0x3

#define RCC_I2S_CLK_PLLI2S      0x0
#define RCC_I2S_CLK_EXTERNAL    0x1

#define RCC_AHB1_GPIOA          0x00
#define RCC_AHB1_GPIOB          0x01
#define RCC_AHB1_GPIOC          0x02
#define RCC_AHB1_GPIOD          0x03
#define RCC_AHB1_GPIOE          0x04
#define RCC_AHB1_GPIOH          0x07
#define RCC_AHB1_CRCRST         0x0c
#define RCC_AHB1_DMA1           0x15
#define RCC_AHB1_DMA2           0x16

#define RCC_AHB2_OTGFS          0x07

#define RCC_APB1_TIM2           0x00
#define RCC_APB1_TIM3           0x01
#define RCC_APB1_TIM4           0x02
#define RCC_APB1_TIM5           0x03
#define RCC_APB1_WWDG           0x0b
#define RCC_APB1_SPI2           0x0e
#define RCC_APB1_SPI3           0x0f
#define RCC_APB1_USART2         0x11
#define RCC_APB1_I2C1           0x15
#define RCC_APB1_I2C2           0x16
#define RCC_APB1_I2C3           0x17
#define RCC_APB1_PWR            0x1c

#define RCC_APB2_TIM1           0x00
#define RCC_APB2_USART1         0x04
#define RCC_APB2_USART6         0x05
#define RCC_APB2_ADC1           0x08
#define RCC_APB2_SDIO           0x0b
#define RCC_APB2_SPI1           0x0c
#define RCC_APB2_SPI4           0x0d
#define RCC_APB2_SYSCFG         0x0e
#define RCC_APB2_TIM9           0x10
#define RCC_APB2_TIM10          0x11
#define RCC_APB2_TIM11          0x12
#define RCC_APB2_SPI5           0x14


/* Typedefs */
typedef struct rcc_main_pll_init_struct {
    uint8_t pll_m;
    uint16_t pll_n;
    uint8_t pll_p;
    uint8_t pll_source;
    uint8_t pll_q;
}rcc_main_pll_init_struct;

typedef struct rcc_clock_init_struct {
    uint8_t system_clock;
    uint8_t i2s_clock;
    uint8_t ahb_prescaler;
    uint8_t apb1_prescaler;
    uint8_t apb2_prescaler;
    uint8_t rtc_prescaler;
    uint8_t clock_output_1;
    uint8_t clock_output_2;
    uint8_t mco1_prescaler;
    uint8_t mco2_prescaler;
}rcc_clock_init_struct;

typedef struct rcc_i2s_pll_init_struct {
    uint8_t i2s_pll_m;
    uint16_t i2s_pll_n;
    uint8_t i2s_pll_r;
}rcc_i2s_pll_init_struct;


/* Function prototypes */
void rcc_clock_init(rcc_clock_init_struct * clock_init_struct);
void rcc_main_pll_init(rcc_main_pll_init_struct * main_pll_init_struct);
void rcc_i2s_pll_init(rcc_i2s_pll_init_struct * i2s_pll_init_struct);

void rcc_enable_main_pll();
void rcc_disable_main_pll();
void rcc_enable_i2s_pll();
void rcc_disable_i2s_pll();
void rcc_enable_hse();
void rcc_disable_hse();
void rcc_enable_hsi();
void rcc_disable_hsi();

uint8_t rcc_main_pll_ready();
uint8_t rcc_i2s_pll_ready();
uint8_t rcc_hse_ready();
uint8_t rcc_hsi_ready();

void rcc_ahb1_enable(uint8_t ahb1_peripheral);
void rcc_ahb2_enable(uint8_t ahb2_peripheral);
void rcc_apb1_enable(uint8_t apb1_peripheral);
void rcc_apb2_enable(uint8_t apb2_peripheral);

void rcc_ahb1_reset(uint8_t ahb1_peripheral);
void rcc_ahb2_reset(uint8_t ahb2_peripheral);
void rcc_apb1_reset(uint8_t apb1_peripheral);
void rcc_apb2_reset(uint8_t apb2_peripheral);

