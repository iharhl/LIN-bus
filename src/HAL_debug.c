#include "HAL_debug.h"

bool LIN_HAL_Tx_Break() { return 1; }
bool LIN_HAL_Tx_Byte() { return 1; }
bool LIN_HAL_Detect_Break() { return 1; }
uint8_t LIN_HAL_Rx_Byte() { return 0x55; }