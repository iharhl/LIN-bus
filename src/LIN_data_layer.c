#include "LIN_data_layer.h"

uint8_t LIN_PID_Add_Parity_Bits(uint8_t frame_identifier)
{
    uint8_t pid = 0;

    /* Parity bit 0 */
	pid = (uint8_t)( LIN_GET_PID_BIT(frame_identifier,0) ^ \
                        LIN_GET_PID_BIT(frame_identifier,1) ^ \
                        LIN_GET_PID_BIT(frame_identifier,2) ^ \
                        LIN_GET_PID_BIT(frame_identifier,4) << 6);

    /* Parity bit 1 */
    pid |= (uint8_t)(~( LIN_GET_PID_BIT(frame_identifier,1) ^ \
                           LIN_GET_PID_BIT(frame_identifier,3) ^ \
                           LIN_GET_PID_BIT(frame_identifier,4) ^ \
                           LIN_GET_PID_BIT(frame_identifier,5)) << 7);

    /* Assemble full PID field */
    pid |= (uint8_t)(LIN_FRAME_ID_MAX & frame_identifier);

    return pid;
}

uint8_t LIN_Checksum(uint8_t pid, uint8_t data_size, const uint8_t* data_ptr);