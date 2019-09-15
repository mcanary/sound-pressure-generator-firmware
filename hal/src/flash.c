

#include "flash.h"


/* Constants */
volatile uint32_t * access_control_register = (uint32_t *) (FLASH_BASE + FLASH_ACR);


void flash_set_latency(uint8_t latency) {

    uint32_t access_control = * access_control_register;
    access_control = access_control & ~(0xf);
    * access_control_register = (* access_control_register & ~(0xf)) | latency;

};

