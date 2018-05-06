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
* File Name    : R_PG_LPC.c
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
#include "r_pdl_lpc.h"
#include "r_pdl_definitions.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_LPC_Set(void)
*
* Function Name: R_PG_LPC_Set
*
* Description  : 消費電力低減機能の設定
*
* Arguments    : なし
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_LPC_Create
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_LPC_Set(void)
{
	return R_LPC_Create(
		PDL_LPC_EXT_BUS_ON | PDL_LPC_IO_SAME | PDL_LPC_HIGH_SPEED_MODE | PDL_LPC_SLEEP_RETURN_SWITCH_DISABLE | PDL_LPC_DEEPCUT_RAM_USB,
		PDL_LPC_CANCEL_IRQ0_DISABLE | PDL_LPC_CANCEL_IRQ1_DISABLE | PDL_LPC_CANCEL_IRQ2_DISABLE | PDL_LPC_CANCEL_IRQ3_DISABLE | PDL_LPC_CANCEL_IRQ4_DISABLE | PDL_LPC_CANCEL_IRQ5_DISABLE | PDL_LPC_CANCEL_IRQ6_DISABLE | PDL_LPC_CANCEL_IRQ7_DISABLE,
		PDL_LPC_CANCEL_IRQ8_DISABLE | PDL_LPC_CANCEL_IRQ9_DISABLE | PDL_LPC_CANCEL_IRQ10_DISABLE | PDL_LPC_CANCEL_IRQ11_DISABLE | PDL_LPC_CANCEL_IRQ12_DISABLE | PDL_LPC_CANCEL_IRQ13_DISABLE | PDL_LPC_CANCEL_IRQ14_DISABLE | PDL_LPC_CANCEL_IRQ15_DISABLE,
		PDL_LPC_CANCEL_LVD1_DISABLE | PDL_LPC_CANCEL_LVD2_DISABLE | PDL_LPC_CANCEL_RTCI_DISABLE | PDL_LPC_CANCEL_RTCA_DISABLE | PDL_LPC_CANCEL_NMI_DISABLE | PDL_LPC_CANCEL_IICD_DISABLE | PDL_LPC_CANCEL_IICC_DISABLE | PDL_LPC_CANCEL_USB_DISABLE | PDL_LPC_CANCEL_CAN_DISABLE,
		PDL_LPC_MAIN_262144,
		PDL_LPC_SUB_512,
		PDL_LPC_PLL_4194304
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_LPC_Sleep(void)
*
* Function Name: R_PG_LPC_Sleep
*
* Description  : スリープモードへの移行
*
* Arguments    : なし
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_LPC_Control
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_LPC_Sleep(void)
{
	return R_LPC_Control( PDL_LPC_MODE_SLEEP );

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_LPC_AllModuleClockStop(void)
*
* Function Name: R_PG_LPC_AllModuleClockStop
*
* Description  : 全モジュールクロックスタンバイモードへの移行
*
* Arguments    : なし
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_LPC_Control
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_LPC_AllModuleClockStop(void)
{
	return R_LPC_Control( PDL_LPC_MODE_ALL_MODULE_CLOCK_STOP | PDL_LPC_TMR_OFF );

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_LPC_DeepSoftwareStandby(void)
*
* Function Name: R_PG_LPC_DeepSoftwareStandby
*
* Description  : ディープソフトウェアスタンバイモードへの移行
*
* Arguments    : なし
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_LPC_Control
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_LPC_DeepSoftwareStandby(void)
{
	return R_LPC_Control( PDL_LPC_MODE_DEEP_SOFTWARE_STANDBY );

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_LPC_SoftwareStandby(void)
*
* Function Name: R_PG_LPC_SoftwareStandby
*
* Description  : ソフトウェアスタンバイモードへの移行
*
* Arguments    : なし
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_LPC_Control
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_LPC_SoftwareStandby(void)
{
	return R_LPC_Control( PDL_LPC_MODE_SOFTWARE_STANDBY );

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_LPC_ChangeOperatingPowerControl(uint8_t mode)
*
* Function Name: R_PG_LPC_ChangeOperatingPowerControl
*
* Description  : 動作電力制御モードを変更
*
* Arguments    : uint8_t mode : 動作電力制御モード
*              :              : (0:高速動作モード  1:低速動作モード1  2:低速動作モード2)
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_LPC_Control
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_LPC_ChangeOperatingPowerControl(uint8_t mode)
{
	uint32_t control;

	switch( mode ){
		case 0:
			control = PDL_LPC_CHANGE_HIGH_SPEED;
			break;
		case 1:
			control = PDL_LPC_CHANGE_LOW_SPEED_1;
			break;
		case 2:
			control = PDL_LPC_CHANGE_LOW_SPEED_2;
			break;
		default:
			return false;
	}

	return R_LPC_Control( control );

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_LPC_ChangeSleepModeReturnClock(uint8_t return_clock)
*
* Function Name: R_PG_LPC_ChangeSleepModeReturnClock
*
* Description  : スリープモード復帰クロックソースを変更
*
* Arguments    : uint8_t return_clock : スリープモード復帰クロックソース
*              :                      : (0:切り替え無効  1:HOCO  2:メインクロック)
*
* Return Value : true  : 設定が正しく行われた場合
*              : false : 設定に失敗した場合
*
* Calling Functions : R_LPC_Control
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_LPC_ChangeSleepModeReturnClock(uint8_t return_clock)
{
	uint32_t control;

	switch( return_clock ){
		case 0:
			control = PDL_LPC_SLEEP_RETURN_CHANGE_DISABLE;
			break;
		case 1:
			control = PDL_LPC_SLEEP_RETURN_CHANGE_HOCO;
			break;
		case 2:
			control = PDL_LPC_SLEEP_RETURN_CHANGE_MAIN;
			break;
		default:
			return false;
	}

	return R_LPC_Control( control );

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_LPC_GetOperatingPowerControlFlag(bool * during_transition)
*
* Function Name: R_PG_LPC_GetOperatingPowerControlFlag
*
* Description  : 動作電力制御モード遷移状態フラグを取得
*
* Arguments    : bool * during_transition : 動作電力制御モード遷移状態フラグの格納先
*
* Return Value : true  : フラグの取得が正しく行われた場合
*              : false : フラグの取得に失敗した場合
*
* Calling Functions : R_LPC_GetStatus
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_LPC_GetOperatingPowerControlFlag(bool * during_transition)
{
	uint32_t data1;
	uint8_t data2;
	bool res;

	res = R_LPC_GetStatus(
		&data1,
		&data2
	);

	if( during_transition ){ *during_transition = (data1 >> 24) & 0x01; }

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_LPC_GetPowerOnResetFlag(bool * reset)
*
* Function Name: R_PG_LPC_GetPowerOnResetFlag
*
* Description  : パワーオンリセットフラグの取得
*
* Arguments    : bool * reset : パワーオンリセットフラグの格納先
*
* Return Value : true  : フラグの取得が正しく行われた場合
*              : false : フラグの取得に失敗した場合
*
* Calling Functions : R_LPC_GetStatus
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_LPC_GetPowerOnResetFlag(bool * reset)
{
	uint32_t data1;
	uint8_t data2;
	bool res;

	res = R_LPC_GetStatus(
		&data1,
		&data2
	);

	if( reset ){ *reset = (data1 >> 16) & 0x01; }

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_LPC_GetLVDDetectionFlag(bool * lvd0, bool * lvd1, bool * lvd2)
*
* Function Name: R_PG_LPC_GetLVDDetectionFlag
*
* Description  : LVD検出フラグを取得
*
* Arguments    : bool * lvd0 : LVD0検出フラグの格納先
*              : bool * lvd1 : LVD1検出フラグの格納先
*              : bool * lvd2 : LVD2検出フラグの格納先
*
* Return Value : true  : フラグの取得が正しく行われた場合
*              : false : フラグの取得に失敗した場合
*
* Calling Functions : R_LPC_GetStatus
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_LPC_GetLVDDetectionFlag(bool * lvd0, bool * lvd1, bool * lvd2)
{
	uint32_t data1;
	uint8_t data2;
	bool res;

	res = R_LPC_GetStatus(
		&data1,
		&data2
	);

	if( lvd0 ){
		*lvd0 = (data1 >> 17) & 0x01;
	}
	if( lvd1 ){
		*lvd1 = (data1 >> 18) & 0x01;
	}
	if( lvd2 ){
		*lvd2 = (data1 >> 19) & 0x01;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_LPC_GetDeepSoftwareStandbyResetFlag(bool * reset)
*
* Function Name: R_PG_LPC_GetDeepSoftwareStandbyResetFlag
*
* Description  : ディープソフトウェアスタンバイリセットフラグの取得
*
* Arguments    : bool * reset : ディープソフトウェアスタンバイリセットフラグの格納先
*
* Return Value : true  : フラグの取得が正しく行われた場合
*              : false : フラグの取得に失敗した場合
*
* Calling Functions : R_LPC_GetStatus
*
* Details      : 詳細についてはリファレンスマニュアルを参照してください。
******************************************************************************/
bool R_PG_LPC_GetDeepSoftwareStandbyResetFlag(bool * reset)
{
	uint32_t data1;
	uint8_t data2;
	bool res;

	res = R_LPC_GetStatus(
		&data1,
		&data2
	);

	if( reset ){ *reset = (data1 >> 23) & 0x01; }

	return res;
}



