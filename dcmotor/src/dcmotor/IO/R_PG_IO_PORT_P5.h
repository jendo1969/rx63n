/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010-2013 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_IO_PORT_P5.h
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

bool R_PG_IO_PORT_Set_P5(void);
bool R_PG_IO_PORT_Set_P51(void);
bool R_PG_IO_PORT_Read_P5(uint8_t * data);
bool R_PG_IO_PORT_Read_P50(uint8_t * data);
bool R_PG_IO_PORT_Read_P51(uint8_t * data);
bool R_PG_IO_PORT_Read_P52(uint8_t * data);
bool R_PG_IO_PORT_Read_P53(uint8_t * data);
bool R_PG_IO_PORT_Read_P54(uint8_t * data);
bool R_PG_IO_PORT_Read_P55(uint8_t * data);
bool R_PG_IO_PORT_Write_P5(uint8_t data);
bool R_PG_IO_PORT_Write_P51(uint8_t data);



