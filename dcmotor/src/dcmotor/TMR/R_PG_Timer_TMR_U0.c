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
* File Name    : R_PG_Timer_TMR_U0.c
* Version      : 1.00
* Device(s)    : 
* Tool-Chain   : 
* H/W Platform : 
* Description  : 
* Limitations  : 
******************************************************************************
* History : 05.05.2018 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_tmr.h"
#include "r_pdl_definitions.h"
#include "R_PG_IntFuncsExtern.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_Start_TMR_U0(void)
*
* Function Name: R_PG_Timer_Start_TMR_U0
*
* Description  : TMRを設定しカウント動作を開始
*
* Arguments    : なし
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_TMR_CreateUnit
*                   : R_TMR_Set
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_Timer_Start_TMR_U0(void)
{
	bool res;

	res = R_TMR_Set(
		0,
		PDL_TMR_TMR0_TMO0_P22
	);

	if( !res ){
		return res;
	}

	return R_TMR_CreateUnit(
		0,
		PDL_TMR_CLK_PCLK_DIV_1024 | PDL_TMR_CLEAR_CM_A | PDL_TMR_ADC_TRIGGER_DISABLE | PDL_TMR_CM_A_DTC_TRIGGER_DISABLE | PDL_TMR_CM_B_DTC_TRIGGER_DISABLE,
		PDL_TMR_OUTPUT_HIGH_CM_A | PDL_TMR_OUTPUT_LOW_CM_B,
		0,
		4687,
		2343,
		PDL_NO_FUNC,
		Tmr0CmAIntFunc,
		Tmr0CmBIntFunc,
		10
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_HaltCount_TMR_U0(void)
*
* Function Name: R_PG_Timer_HaltCount_TMR_U0
*
* Description  : TMRのカウント動作を一時停止
*
* Arguments    : なし
*
* Return Value : true  : 停止に成功した場合
*              : false : 停止に失敗した場合
*
* Calling Functions : R_TMR_ControlUnit
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_Timer_HaltCount_TMR_U0(void)
{
	return R_TMR_ControlUnit(
		0,
		PDL_TMR_STOP,
		0,
		0,
		0
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_ResumeCount_TMR_U0(void)
*
* Function Name: R_PG_Timer_ResumeCount_TMR_U0
*
* Description  : TMRのカウント動作を再開
*
* Arguments    : なし
*
* Return Value : true  : カウント動作の再開が正しく行われた場合
*              : false : カウント動作の再開に失敗した場合
*
* Calling Functions : R_TMR_ControlUnit
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_Timer_ResumeCount_TMR_U0(void)
{
	return R_TMR_ControlUnit(
		0,
		PDL_TMR_START,
		0,
		0,
		0
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetCounterValue_TMR_U0(uint16_t * counter_val)
*
* Function Name: R_PG_Timer_GetCounterValue_TMR_U0
*
* Description  : TMRのカウンタ値を取得
*
* Arguments    : uint16_t * counter_val : カウンタ値の格納先
*
* Return Value : true  : 取得に成功した場合
*              : false : 取得に失敗した場合
*
* Calling Functions : R_TMR_ReadUnit
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_Timer_GetCounterValue_TMR_U0(uint16_t * counter_val)
{
	if( counter_val == 0 ){ return false; }

	return R_TMR_ReadUnit(
		0,
		PDL_NO_PTR,
		counter_val,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetCounterValue_TMR_U0(uint16_t counter_val)
*
* Function Name: R_PG_Timer_SetCounterValue_TMR_U0
*
* Description  : TMRのカウンタ値を設定
*
* Arguments    : uint16_t counter_val : カウンタに設定する値
*
* Return Value : true  : カウンタ値の設定に成功した場合
*              : false : カウンタ値の設定に失敗した場合
*
* Calling Functions : R_TMR_ControlUnit
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_Timer_SetCounterValue_TMR_U0(uint16_t counter_val)
{
	return R_TMR_ControlUnit(
		0,
		PDL_TMR_COUNTER,
		counter_val,
		0,
		0
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetRequestFlag_TMR_U0(bool * cma, bool * cmb, bool * ov)
*
* Function Name: R_PG_Timer_GetRequestFlag_TMR_U0
*
* Description  : TMRの割り込み要求フラグの取得とクリア
*
* Arguments    : bool * cma : コンペアマッチAフラグの格納先
*              : bool * cmb : コンペアマッチBフラグの格納先
*              : bool * ov : オーバフローフラグの格納先
*
* Return Value : true  : フラグの取得が正しく行われた場合
*              : false : フラグの取得に失敗した場合
*
* Calling Functions : R_TMR_ReadUnit
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_Timer_GetRequestFlag_TMR_U0(bool * cma, bool * cmb, bool * ov)
{
	uint8_t data;
	bool res;

	res = R_TMR_ReadUnit(
		0,
		&data,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( cma ){
		*cma = (data >> 4) & 0x01;
	}
	if( cmb ){
		*cmb = (data >> 5) & 0x01;
	}
	if( ov ){
		*ov = (data >> 6) & 0x01;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_StopModule_TMR_U0(void)
*
* Function Name: R_PG_Timer_StopModule_TMR_U0
*
* Description  : TMRのユニットを停止
*
* Arguments    : なし
*
* Return Value : true  : 停止に成功した場合
*              : false : 停止に失敗した場合
*
* Calling Functions : R_TMR_Destroy
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_Timer_StopModule_TMR_U0(void)
{
	return R_TMR_Destroy( 0 );

}



