/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010-2013 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_SCI_C2.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 05.05.2018 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include <stdint.h>
#include <stdbool.h>

bool R_PG_SCI_Set_C2(void);
bool R_PG_SCI_SendAllData_C2(uint8_t * data, uint16_t count);
bool R_PG_SCI_GetSentDataCount_C2(uint16_t * count);
bool R_PG_SCI_ReceiveAllData_C2(uint8_t * data, uint16_t count);
bool R_PG_SCI_StopCommunication_C2(void);
bool R_PG_SCI_GetReceivedDataCount_C2(uint16_t * count);
bool R_PG_SCI_GetReceptionErrorFlag_C2(bool * parity, bool * framing, bool * overrun);
bool R_PG_SCI_ClearReceptionErrorFlag_C2(void);
bool R_PG_SCI_GetTransmitStatus_C2(bool * complete);
bool R_PG_SCI_StopModule_C2(void);



