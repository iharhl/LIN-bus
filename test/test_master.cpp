#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
#include "../src/LIN_master_node.h"
}

TEST(Master_Node, TxHeader)
{
    // Arrange
    bool result;

    // Act
    LIN_Master_Init();
    result = LIN_Master_Tx_Header();

    // Assert
    ASSERT_EQ(result, true);
}

TEST(Master_Node, GotoState)
{
    // Arrange
    bool result = true;
    LIN_Master_State breakState = BREAK_STATE_MASTER;
    LIN_Master_State syncState = SYNC_STATE_MASTER;
    LIN_Master_State pidState = PID_STATE_MASTER;

    // Act
    LIN_Master_Init();
    result = LIN_Master_Goto_State(breakState) && result;
    result = LIN_Master_Goto_State(syncState) && result;
    result = LIN_Master_Goto_State(pidState) && result;

    // Assert
    ASSERT_EQ(result, true);
}