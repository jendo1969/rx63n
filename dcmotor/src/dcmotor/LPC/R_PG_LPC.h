/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010-2013 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_LPC.h
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
#include "r_pdl_lpc_RX63Nxx.h"

#define R_PG_LPC_WriteBackup(a, b) R_LPC_WriteBackup( (a), (b) )
#define R_PG_LPC_ReadBackup(a, b) R_LPC_ReadBackup( (a), (b) )
#define R_PG_LPC_GetStatus(a, b) R_LPC_GetStatus( (a), (b) )
bool R_PG_LPC_Set(void);
bool R_PG_LPC_Sleep(void);
bool R_PG_LPC_AllModuleClockStop(void);
bool R_PG_LPC_DeepSoftwareStandby(void);
bool R_PG_LPC_SoftwareStandby(void);
bool R_PG_LPC_ChangeOperatingPowerControl(uint8_t mode);
bool R_PG_LPC_ChangeSleepModeReturnClock(uint8_t return_clock);
bool R_PG_LPC_GetOperatingPowerControlFlag(bool * during_transition);
bool R_PG_LPC_GetPowerOnResetFlag(bool * reset);
bool R_PG_LPC_GetLVDDetectionFlag(bool * lvd0, bool * lvd1, bool * lvd2);
bool R_PG_LPC_GetDeepSoftwareStandbyResetFlag(bool * reset);



