#ifndef _LIN_MASTER_NODE_H
#define _LIN_MASTER_NODE_H

#include <stdbool.h>
#include <stdint.h>
#include "LIN_network_management.h"
#include "LIN_data_layer.h"

typedef enum
{
    IDLE_STATE_MASTER,
    BREAK_STATE_MASTER,
    SYNC_STATE_MASTER,
    PID_STATE_MASTER,
} LIN_Master_State_Enum_t;

typedef struct
{
    uint8_t Offset_ms;
    uint8_t Response_Wait_ms;
    LIN_Frame_Slot_Struct_t slot;
} LIN_Master_Frame_Table_Struct_t;

/* ========== PRIVATE ============= */

/* STATE MACHINE */
bool LIN_Master_Goto_State(LIN_Master_State_Enum_t newState);

/* =========== PUBLIC ============= */

void LIN_Master_Init(LIN_Master_Frame_Table_Struct_t* masterFrameTablePtr, uint8_t masterFrameTableSize);

/* RECEIVE */
// bool LIN_Master_Rx_Data();

/* TRANSMIT */
bool LIN_Master_Tx_Header();
// bool LIN_Master_Tx_Data();

#endif