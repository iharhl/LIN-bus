#include "LIN_slave_node.h"
#include "HAL_debug.h"
#include "LIN_defines.h"
#include <stdio.h>

static LIN_Slave_State LIN_Slave_Current_State;

bool LIN_Slave_Goto_State(LIN_Slave_State newState)
{
    // Indicate if state execution was successfull
    bool result = true;

    // FSM
    switch (newState)
    {
    case IDLE_STATE_SLAVE:
    {
        printf("Slave in Idle\n");
        break;
    }
    case SYNC_RX_STATE_SLAVE:
    {
        printf("Slave in Idle\n");
        uint8_t rxByte = LIN_HAL_Rx_Byte();

        if (rxByte == 0x55) 
        { result = true; }
        else
        { result = false; }

        break;
    }
    case PID_STATE_SLAVE:
    {
        printf("Slave in Idle\n");
        uint8_t rxByte = LIN_HAL_Rx_Byte();

        if (rxByte == DEBUG_PID)
        { result = true; }
        else
        { result = false; }
        break;
    }
    case DATA_RX_STATE_SLAVE:
    {
        printf("Slave in Idle\n");
        break;
    }
    case CHECKSUM_RX_STATE_SLAVE:
    {
        printf("Slave in Idle\n");
        break;
    }
    default:
        break;
    }

    // ...
    if (result)
    {
        LIN_Slave_Current_State = newState;
    } else
    {
        /* TODO */

    }

    return result;
}

void LIN_Slave_Init()
{
    LIN_Slave_Goto_State(IDLE_STATE_SLAVE);
}

void LIN_Slave_Detect_Break()
{
    if (LIN_HAL_Detect_Break())
    {
        LIN_Slave_Goto_State(SYNC_RX_STATE_SLAVE);
    } else 
    {
        /* TODO: should be in a separate inf loop */
    }
}