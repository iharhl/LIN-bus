#include <stdio.h>
#include "src/LIN_master_node.h"
#include "src/LIN_slave_node.h"
#include "src/LIN.h"

int main()
{
    LIN_Sys_Init();
    LIN_Master_Tx_Header();
    LIN_Slave_Detect_Break();
    return 0;
}