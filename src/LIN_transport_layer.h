#ifndef _LIN_TRANSPORT_LAYER_H
#define _LIN_TRANSPORT_LAYER_H

#include <stdint.h>

typedef enum
{
	LIN_SID_ASSIGN_NAD = 0xB0,
	LIN_SID_READ_BY_ID = 0xB2,
	LIN_SID_CONDITIONAL_CHANGE_NAD = 0xB3,
	LIN_SID_DUMP_DATA = 0xB4,
	LIN_SID_SAVED_CONFIGURATION = 0xB6,
	LIN_SID_ASSIGN_FRAME_ID_RANGE = 0xB7
} LIN_SID_Enum_t;

typedef enum
{
	OPEN_LIN_PCI_SF,
	OPEN_LIN_PCI_FF,
	OPEN_LIN_PCI_CF
} LIN_PCI_Type_Enum_t;

// TODO ?
typedef enum
{
	LIN_NAD_SLEEP = 0x00,
	LIN_NAD_FUNCTIONAL = 0x7E,
	LIN_NAD_BROADCAST = 0x7F
} LIN_NAD_Type_Enum_t;

typedef struct
{
    LIN_SID_Enum_t sid;
    LIN_PCI_Type_Enum_t pci;
    LIN_NAD_Type_Enum_t nad;
    uint8_t data[5];
} LIN_SF_Request_Struct_t;

typedef struct
{
    uint8_t rsid;
    LIN_PCI_Type_Enum_t pci;
    LIN_NAD_Type_Enum_t nad;
    uint8_t data[5];
} LIN_SF_Response_Struct_t;

#endif