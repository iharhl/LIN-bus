#ifndef _LIN_SLAVE_NODE_H
#define _LIN_SLAVE_NODE_H

#include <stdbool.h>

typedef enum
{
    IDLE_STATE_SLAVE,
    SYNC_RX_STATE_SLAVE,
    PID_STATE_SLAVE,
    DATA_RX_STATE_SLAVE,
    CHECKSUM_RX_STATE_SLAVE,
    DATA_TX_STATE_SLAVE,
    CHECKSUM_TX_STATE_SLAVE,
} LIN_Slave_State;

/* ========== PRIVATE ============= */

/* STATE MACHINE */
bool LIN_Slave_Goto_State(LIN_Slave_State newState);

/* =========== PUBLIC ============= */

void LIN_Slave_Init();
void LIN_Slave_Detect_Break();


#endif