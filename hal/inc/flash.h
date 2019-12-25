

#ifndef FLASH_H
#define FLASH_H


#include <stdint.h>


/* Flash register offsets */
#define FLASH_BASE  0x40023C00

#define FLASH_ACR   0x00


/* Function prototypes */
void flash_set_latency(uint8_t latency);


#endif

