

#include "rcc.h"


/* Constants */
volatile uint32_t * clock_control_register = (uint32_t *) (RCC_BASE + RCC_CR);
volatile uint32_t * main_pll_configuration_register = (uint32_t *) (RCC_BASE + RCC_PLLCFGR);
volatile uint32_t * clock_configuration_register = (uint32_t *) (RCC_BASE + RCC_CFGR);
volatile uint32_t * clock_interrupt_register = (uint32_t *) (RCC_BASE + RCC_CIR);
volatile uint32_t * ahb1_reset_register = (uint32_t *) (RCC_BASE + RCC_AHB1RSTR);
volatile uint32_t * ahb2_reset_register = (uint32_t *) (RCC_BASE + RCC_AHB2RSTR);
volatile uint32_t * apb1_reset_register = (uint32_t *) (RCC_BASE + RCC_APB1RSTR);
volatile uint32_t * apb2_reset_register = (uint32_t *) (RCC_BASE + RCC_APB2RSTR);
volatile uint32_t * ahb1_enable_register = (uint32_t *) (RCC_BASE + RCC_AHB1ENR);
volatile uint32_t * ahb2_enable_register = (uint32_t *) (RCC_BASE + RCC_AHB2ENR);
volatile uint32_t * apb1_enable_register = (uint32_t *) (RCC_BASE + RCC_APB1ENR);
volatile uint32_t * apb2_enable_register = (uint32_t *) (RCC_BASE + RCC_APB2ENR);
volatile uint32_t * ahb1_lp_enable_register = (uint32_t *) (RCC_BASE + RCC_AHB1LPENR);
volatile uint32_t * ahb2_lp_enable_register = (uint32_t *) (RCC_BASE + RCC_AHB2LPENR);
volatile uint32_t * apb1_lp_enable_register = (uint32_t *) (RCC_BASE + RCC_APB1LPENR);
volatile uint32_t * apb2_lp_enable_register = (uint32_t *) (RCC_BASE + RCC_APB2LPENR);
volatile uint32_t * backup_domain_conmtrol_register = (uint32_t *) (RCC_BASE + RCC_BDCR);
volatile uint32_t * clock_control_status_register = (uint32_t *) (RCC_BASE + RCC_CSR);
volatile uint32_t * ss_clock_generation_register = (uint32_t *) (RCC_BASE + RCC_SSCGR);
volatile uint32_t * i2s_pll_configuration_register = (uint32_t *) (RCC_BASE + RCC_PLLI2SCFGR);
volatile uint32_t * dedicated_clocks_configuration_register = (uint32_t *) (RCC_BASE + RCC_DCKCFGR);


void rcc_clock_init(rcc_clock_init_struct * clock_init_struct) {

    uint32_t clock_configuration = * clock_configuration_register;

    clock_configuration = clock_configuration & ~(0xfffffcff);

    clock_configuration = clock_configuration | (clock_init_struct->clock_output_2 << 30);
    clock_configuration = clock_configuration | (clock_init_struct->mco2_prescaler << 27);
    clock_configuration = clock_configuration | (clock_init_struct->mco1_prescaler << 24);
    clock_configuration = clock_configuration | (clock_init_struct->i2s_clock << 23);
    clock_configuration = clock_configuration | (clock_init_struct->clock_output_1 << 21);
    clock_configuration = clock_configuration | (clock_init_struct->rtc_prescaler << 16);
    clock_configuration = clock_configuration | (clock_init_struct->apb2_prescaler << 13);
    clock_configuration = clock_configuration | (clock_init_struct->apb1_prescaler << 10);
    clock_configuration = clock_configuration | (clock_init_struct->ahb_prescaler << 4);
    clock_configuration = clock_configuration | (clock_init_struct->system_clock);

    * clock_configuration_register = clock_configuration;

}

void rcc_main_pll_init(rcc_main_pll_init_struct * main_pll_init_struct) {

    uint32_t main_pll_configuration = * main_pll_configuration_register;

    main_pll_configuration = main_pll_configuration & ~(0x0f437fff);

    main_pll_configuration = main_pll_configuration | (main_pll_init_struct->pll_q << 24);
    main_pll_configuration = main_pll_configuration | (main_pll_init_struct->pll_source << 22);
    main_pll_configuration = main_pll_configuration | (main_pll_init_struct->pll_p << 16);
    main_pll_configuration = main_pll_configuration | (main_pll_init_struct->pll_n << 6);
    main_pll_configuration = main_pll_configuration | (main_pll_init_struct->pll_m);

    * main_pll_configuration_register = main_pll_configuration;

}

void rcc_i2s_pll_init(rcc_i2s_pll_init_struct * i2s_pll_init_struct) {

    uint32_t i2s_pll_configuration = * i2s_pll_configuration_register;

    i2s_pll_configuration = i2s_pll_configuration & ~(0x70007fff);

    i2s_pll_configuration = i2s_pll_configuration | (i2s_pll_init_struct->i2s_pll_r << 28);
    i2s_pll_configuration = i2s_pll_configuration | (i2s_pll_init_struct->i2s_pll_n << 6);
    i2s_pll_configuration = i2s_pll_configuration | (i2s_pll_init_struct->i2s_pll_m);

    * i2s_pll_configuration_register = i2s_pll_configuration;

}

void rcc_enable_main_pll() {

    * clock_control_register = * clock_control_register | (0x1 << 24);

}

void rcc_disable_main_pll() {

    * clock_control_register = * clock_control_register & ~(0x1 << 24);

}

void rcc_enable_i2s_pll() {

    * clock_control_register = * clock_control_register | (0x1 << 26);

}

void rcc_disable_i2s_pll() {

    * clock_control_register = * clock_control_register & ~(0x1 << 26);

}

void rcc_enable_hse() {

    * clock_control_register = * clock_control_register | (0x1 << 16);

}

void rcc_disable_hse() {

    * clock_control_register = * clock_control_register & ~(0x1 << 16);

}

void rcc_enable_hsi() {

    * clock_control_register = * clock_control_register | (0x1);

}

void rcc_disable_hsi() {

    * clock_control_register = * clock_control_register & ~(0x1);

}

uint8_t rcc_main_pll_ready() {

    return (* clock_control_register & (0x1 << 25) >> 25);

}

uint8_t rcc_i2s_pll_ready() {

    return (* clock_control_register & (0x1 << 27) >> 27);

}

uint8_t rcc_hse_ready() {

    return (* clock_control_register & (0x1 << 17) >> 17);

}

uint8_t rcc_hsi_ready() {

    return (* clock_control_register & (0x1 << 1) >> 1);

}

void rcc_ahb1_enable(uint8_t ahb1_peripheral) {

    * ahb1_enable_register = * ahb1_enable_register | (0x1 << ahb1_peripheral);

}

void rcc_ahb2_enable(uint8_t ahb2_peripheral) {

    * ahb2_enable_register = * ahb2_enable_register | (0x1 << ahb2_peripheral);

}

void rcc_apb1_enable(uint8_t apb1_peripheral) {

    * apb1_enable_register = * apb1_enable_register | (0x1 << apb1_peripheral);

}

void rcc_apb2_enable(uint8_t apb2_peripheral) {

    * apb2_enable_register = * apb2_enable_register | (0x1 << apb2_peripheral);

}

void rcc_ahb1_reset(uint8_t ahb1_peripheral) {

    * ahb1_reset_register = * ahb1_reset_register | (0x1 << ahb1_peripheral);

}

void rcc_ahb2_reset(uint8_t ahb2_peripheral) {

    * ahb2_reset_register = * ahb2_reset_register | (0x1 << ahb2_peripheral);

}

void rcc_apb1_reset(uint8_t apb1_peripheral) {

    * apb1_reset_register = * apb1_reset_register | (0x1 << apb1_peripheral);

}

void rcc_apb2_reset(uint8_t apb2_peripheral) {

    * apb2_reset_register = * apb2_reset_register | (0x1 << apb2_peripheral);

}

