#ifndef _LIN_DATA_LAYER_H
#define _LIN_DATA_LAYER_H

#include <stdint.h>

#define LIN_GET_PID_BIT(id,bit) (((id) >> (bit)) & 0x01u)
#define LIN_FRAME_ID_MAX 0x63

typedef enum
{
    FRAME_TYPE_TRANSMIT,
    FRAME_TYPE_RECEIVE,
} LIN_Frame_Type_Enum_t;

typedef struct
{
    uint8_t pid;
    LIN_Frame_Type_Enum_t frame_type;
    uint8_t data_size;
    uint8_t* data_ptr;
} LIN_Frame_Slot_Struct_t;

uint8_t LIN_PID_Add_Parity_Bits(uint8_t frame_identifier);
uint8_t LIN_Checksum(uint8_t pid, uint8_t data_size, const uint8_t* data_ptr);

#endif