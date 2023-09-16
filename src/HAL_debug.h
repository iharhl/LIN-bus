#ifndef _HAL_H
#define _HAL_H

#include <stdbool.h>
#include <stdint.h>

// Prototypes
bool LIN_HAL_Tx_Break();
bool LIN_HAL_Tx_Byte(uint8_t byte);
bool LIN_HAL_Detect_Break();
uint8_t LIN_HAL_Rx_Byte();

#endif