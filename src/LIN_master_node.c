#include "LIN_master_node.h"
#include "LIN_defines.h"
#include "HAL_debug.h"
#include "../utils/Logger.h"
#include <stdio.h>
#include <stddef.h>

static LIN_Master_State LIN_Master_Current_State;

bool LIN_Master_Goto_State(LIN_Master_State newState)
{
    // Indicate if state execution was successfull
    bool result = true;

    // TODO: error checker

    // FSM
    switch(newState)
    {
        case IDLE_STATE_MASTER:
        {
            LIN_Master_Current_State = newState;
            // Debug_Log(__FILE__, "Idle");
            break;
        }
        case BREAK_STATE_MASTER:
        {
            LIN_Master_Current_State = newState;
            // Debug_Log(__FILE__, "Send Break");
            result = LIN_HAL_Tx_Break() && result;
            break;
        }
        case SYNC_STATE_MASTER:
        {
            LIN_Master_Current_State = newState;
            // Debug_Log(__FILE__, "Sync");
            result = LIN_HAL_Tx_Byte(0x55) && result;
            break;
        }
        case PID_STATE_MASTER:
        {
            LIN_Master_Current_State = newState;
            // Debug_Log(__FILE__, "PID");
            result = LIN_HAL_Tx_Byte(DEBUG_PID) && result;
            break;
        }
        default:
            /* ??? */
            break;
    }
    return result;
}

bool LIN_Master_Tx_Header()
{
    bool result = true;
    
    if (LIN_Master_Current_State == IDLE_STATE_MASTER)
    {
        LIN_Master_Goto_State(BREAK_STATE_MASTER);
        LIN_Master_Goto_State(SYNC_STATE_MASTER);
        LIN_Master_Goto_State(PID_STATE_MASTER);
    } else
    {
        // Debug_Log(__FILE__, "Not in Idle before Tx Header");
    }
    LIN_Master_Goto_State(IDLE_STATE_MASTER);
    return result;
}

void LIN_Master_Init()
{
    LIN_Master_Goto_State(IDLE_STATE_MASTER);
}
