#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
#include "../src/LIN_master_node.h"
}

TEST(Master_Node, TxHeaderCheck)
{
    // Arrange
    bool result;

    // Act
    LIN_Master_Init(nullptr, 0);
    result = LIN_Master_Tx_Header();

    // Assert
    ASSERT_EQ(result, true);
}

TEST(Master_Node, GotoStateCheck)
{
    // Arrange
    bool result = true;
    LIN_Master_State_Enum_t breakState = BREAK_STATE_MASTER;
    LIN_Master_State_Enum_t syncState = SYNC_STATE_MASTER;
    LIN_Master_State_Enum_t pidState = PID_STATE_MASTER;

    // Act
    LIN_Master_Init(nullptr, 0); // TODO
    result = LIN_Master_Goto_State(breakState) && result;
    result = LIN_Master_Goto_State(syncState) && result;
    result = LIN_Master_Goto_State(pidState) && result;

    // Assert
    ASSERT_EQ(result, true);
}