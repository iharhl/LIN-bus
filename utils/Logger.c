#include "Logger.h"
#include <string.h>
#include <stdio.h>

void Debug_Log(char* fname, char* msg)
{
    int Filename_Size = strlen(fname);
    int Msg_Size = strlen(msg);

    printf("[ ");
    for (int i = 0; i < Filename_Size; i++) { printf("%c", fname[i]); }
    printf(" ] : ");
    for (int i = 0; i < Msg_Size; i++) { printf("%c", msg[i]); }
    printf("\n");
}