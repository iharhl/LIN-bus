#include "HAL_debug.h"
#include <assert.h>

bool LIN_HAL_Tx_Break() { return 1; }
bool LIN_HAL_Tx_Byte(uint8_t byte) 
{
    assert(byte); // TODO: remove
    return 1;
}
bool LIN_HAL_Detect_Break() { return 1; }
uint8_t LIN_HAL_Rx_Byte() { return 0x55; }