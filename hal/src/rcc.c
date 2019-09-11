

#include "rcc.h"


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

void rcc_pll_init(rcc_pll_init_struct * pll_init_struct) {

    uint32_t pll_configuration = * pll_configuration_register;

    pll_configuration = pll_configuration & ~(0x0f437fff);

    pll_configuration = pll_configuration | (pll_init_struct->pll_q << 24);
    pll_configuration = pll_configuration | (pll_init_struct->pll_source << 22);
    pll_configuration = pll_configuration | (pll_init_struct->pll_p << 16);
    pll_configuration = pll_configuration | (pll_init_struct->pll_n << 6);
    pll_configuration = pll_configuration | (pll_init_struct->pll_m);

    * pll_configuration_register = pll_configuration;

}

void rcc_enable_pll() {

    * clock_control_register = * clock_control_register | (0x1 << 24);

}

void rcc_disable_pll() {

    * clock_control_register = * clock_control_register & ~(0x1 << 24);

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

