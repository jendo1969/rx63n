/******************************************************************************
* DISCLAIMER

* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized.

* This software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.

* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES
* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, 
* INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
* PARTICULAR PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY 
* DISCLAIMED.

* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES 
* FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS 
* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

* Renesas reserves the right, without notice, to make changes to this 
* software and to discontinue the availability of this software.  
* By using this software, you agree to the additional terms and 
* conditions found by accessing the following link:
* http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010-2013 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_SCI_C0.c
* Version      : 1.00
* Device(s)    : 
* Tool-Chain   : 
* H/W Platform : 
* Description  : 
* Limitations  : 
******************************************************************************
* History : 14.06.2017 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_sci.h"
#include "r_pdl_definitions.h"
#include "R_PG_IntFuncsExtern.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_Set_C0(void)
*
* Function Name: R_PG_SCI_Set_C0
*
* Description  : シリアルI/Oチャネルの設定
*
* Arguments    : なし
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_SCI_Create
*                   : R_SCI_Set
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_SCI_Set_C0(void)
{
	bool res;

	res = R_SCI_Set(
		0,
		PDL_SCI_PIN_SCI0_RXD0_P21 | PDL_SCI_PIN_SCI0_TXD0_P20
	);

	if( !res ){
		return res;
	}

	return R_SCI_Create(
		0,
		PDL_SCI_ASYNC | PDL_SCI_TX_CONNECTED | PDL_SCI_RX_CONNECTED | PDL_SCI_RX_FILTER_DISABLE | PDL_SCI_HW_FLOW_NONE | PDL_SCI_LSB_FIRST | PDL_SCI_CLK_INT_IO | PDL_SCI_8_BIT_LENGTH | PDL_SCI_PARITY_NONE | PDL_SCI_STOP_1,
		BIT_31 | PDL_SCI_PCLK_DIV_1 | PDL_SCI_CYCLE_BIT_8 | 25 | (115384 & 0x00FFFF00ul),
		15,
		15
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_StartSending_C0(uint8_t * data, uint16_t count)
*
* Function Name: R_PG_SCI_StartSending_C0
*
* Description  : シリアルデータの送信開始
*
* Arguments    : uint8_t * data : 送信するデータの格納先の先頭のアドレス
*              : uint16_t count : 送信するデータ数
*              :                : 0を指定した場合はNULLのデータまで送信します
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_SCI_Send
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_SCI_StartSending_C0(uint8_t * data, uint16_t count)
{
	if( data == 0 ){ return false; }

	return R_SCI_Send(
		0,
		PDL_SCI_DMAC_DTC_TRIGGER_DISABLE,
		data,
		count,
		Sci0TrFunc
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_GetSentDataCount_C0(uint16_t * count)
*
* Function Name: R_PG_SCI_GetSentDataCount_C0
*
* Description  : シリアルデータの送信数取得
*
* Arguments    : uint16_t * count : 現在の送信処理で送信されたデータ数の格納先
*
* Return Value : true  : 取得に成功した場合
*              : false : 取得に失敗した場合
*
* Calling Functions : R_SCI_GetStatus
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_SCI_GetSentDataCount_C0(uint16_t * count)
{
	uint8_t status;

	if( count == 0 ){ return false; }

	return R_SCI_GetStatus(
		0,
		&status,
		PDL_NO_PTR,
		count,
		PDL_NO_PTR
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_StartReceiving_C0(uint8_t * data, uint16_t count)
*
* Function Name: R_PG_SCI_StartReceiving_C0
*
* Description  : シリアルデータの受信開始
*
* Arguments    : uint8_t * data : 受信したデータの格納先の先頭のアドレス
*              : uint16_t count : 受信するデータ数
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_SCI_Receive
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_SCI_StartReceiving_C0(uint8_t * data, uint16_t count)
{
	if( data == 0 ){ return false; }

	return R_SCI_Receive(
		0,
		PDL_SCI_DMAC_DTC_TRIGGER_DISABLE,
		data,
		count,
		Sci0ReFunc,
		Sci0ErFunc
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_StopCommunication_C0(void)
*
* Function Name: R_PG_SCI_StopCommunication_C0
*
* Description  : シリアルデータの送受信停止
*
* Arguments    : なし
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_SCI_Control
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_SCI_StopCommunication_C0(void)
{
	return R_SCI_Control(
		0,
		PDL_SCI_STOP_TX_AND_RX
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_GetReceivedDataCount_C0(uint16_t * count)
*
* Function Name: R_PG_SCI_GetReceivedDataCount_C0
*
* Description  : シリアルデータの受信数取得
*
* Arguments    : uint16_t * count : 現在の受信処理で受信したデータ数の格納先
*
* Return Value : true  : 取得に成功した場合
*              : false : 取得に失敗した場合
*
* Calling Functions : R_SCI_GetStatus
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_SCI_GetReceivedDataCount_C0(uint16_t * count)
{
	uint8_t status;

	if( count == 0 ){ return false; }

	return R_SCI_GetStatus(
		0,
		&status,
		PDL_NO_PTR,
		PDL_NO_PTR,
		count
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_GetReceptionErrorFlag_C0(bool * parity, bool * framing, bool * overrun)
*
* Function Name: R_PG_SCI_GetReceptionErrorFlag_C0
*
* Description  : シリアル受信エラーフラグの取得
*
* Arguments    : bool * parity : パリティエラーフラグの格納先
*              : bool * framing : フレーミングエラーフラグ格納先
*              : bool * overrun : オーバランエラーフラグの格納先
*
* Return Value : true  : 取得に成功した場合
*              : false : 取得に失敗した場合
*
* Calling Functions : R_SCI_GetStatus
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_SCI_GetReceptionErrorFlag_C0(bool * parity, bool * framing, bool * overrun)
{
	uint8_t status;
	bool res;

	res = R_SCI_GetStatus(
		0,
		&status,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( parity ){
		*parity = (status >> 3) & 0x01;
	}
	if( framing ){
		*framing = (status >> 4) & 0x01;
	}
	if( overrun ){
		*overrun = (status >> 5) & 0x01;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_ClearReceptionErrorFlag_C0(void)
*
* Function Name: R_PG_SCI_ClearReceptionErrorFlag_C0
*
* Description  : シリアル受信エラーフラグのクリア
*
* Arguments    : なし
*
* Return Value : true  : クリアに成功した場合
*              : false : クリアに失敗した場合
*
* Calling Functions : R_SCI_Control
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_SCI_ClearReceptionErrorFlag_C0(void)
{
	return R_SCI_Control(
		0,
		PDL_SCI_CLEAR_RECEIVE_ERROR_FLAGS
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_GetTransmitStatus_C0(bool * complete)
*
* Function Name: R_PG_SCI_GetTransmitStatus_C0
*
* Description  : シリアルデータ送信状態の取得
*
* Arguments    : bool * complete : 送信終了フラグ格納先
*
* Return Value : true  : 取得に成功した場合
*              : false : 取得に失敗した場合
*
* Calling Functions : R_SCI_GetStatus
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_SCI_GetTransmitStatus_C0(bool * complete)
{
	uint8_t status;
	bool res;

	res = R_SCI_GetStatus(
		0,
		&status,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( complete ){ *complete = (status >> 2) & 0x01; }

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_StopModule_C0(void)
*
* Function Name: R_PG_SCI_StopModule_C0
*
* Description  : シリアルI/Oチャネルの停止
*
* Arguments    : なし
*
* Return Value : true  : 停止に成功した場合
*              : false : 停止に失敗した場合
*
* Calling Functions : R_SCI_Destroy
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_SCI_StopModule_C0(void)
{
	return R_SCI_Destroy( 0 );

}



