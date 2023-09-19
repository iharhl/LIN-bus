#ifndef _LIN_MASTER_NODE_H
#define _LIN_MASTER_NODE_H

#include <stdbool.h>

typedef enum
{
    IDLE_STATE_MASTER,
    BREAK_STATE_MASTER,
    SYNC_STATE_MASTER,
    PID_STATE_MASTER,
} LIN_Master_State;

/* ========== PRIVATE ============= */

/* STATE MACHINE */
bool LIN_Master_Goto_State(LIN_Master_State newState);

/* =========== PUBLIC ============= */

void LIN_Master_Init();

/* RECEIVE */
// bool LIN_Master_Rx_Data();

/* TRANSMIT */
bool LIN_Master_Tx_Header();
// bool LIN_Master_Tx_Data();

#endif