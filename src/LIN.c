#include "LIN.h"
#include <stdio.h>

bool LIN_Sys_Init()
{
    printf("LIN bus init begin\n");
    LIN_Master_Init();
    LIN_Slave_Init();
    printf("LIN bus init end\n");
    return true;
}