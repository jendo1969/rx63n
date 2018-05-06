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
* Description  : TMR��ݒ肵�J�E���g������J�n
*
* Arguments    : �Ȃ�
*
* Return Value : true  : �ݒ肪�������s��ꂽ�ꍇ
*              : false : �ݒ�Ɏ��s�����ꍇ
*
* Calling Functions : R_TMR_CreateUnit
*                   : R_TMR_Set
*
* Details      : �ڍׂɂ��Ă̓��t�@�����X�}�j���A�����Q�Ƃ��Ă��������B
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
* Description  : TMR�̃J�E���g������ꎞ��~
*
* Arguments    : �Ȃ�
*
* Return Value : true  : ��~�ɐ��������ꍇ
*              : false : ��~�Ɏ��s�����ꍇ
*
* Calling Functions : R_TMR_ControlUnit
*
* Details      : �ڍׂɂ��Ă̓��t�@�����X�}�j���A�����Q�Ƃ��Ă��������B
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
* Description  : TMR�̃J�E���g������ĊJ
*
* Arguments    : �Ȃ�
*
* Return Value : true  : �J�E���g����̍ĊJ���������s��ꂽ�ꍇ
*              : false : �J�E���g����̍ĊJ�Ɏ��s�����ꍇ
*
* Calling Functions : R_TMR_ControlUnit
*
* Details      : �ڍׂɂ��Ă̓��t�@�����X�}�j���A�����Q�Ƃ��Ă��������B
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
* Description  : TMR�̃J�E���^�l���擾
*
* Arguments    : uint16_t * counter_val : �J�E���^�l�̊i�[��
*
* Return Value : true  : �擾�ɐ��������ꍇ
*              : false : �擾�Ɏ��s�����ꍇ
*
* Calling Functions : R_TMR_ReadUnit
*
* Details      : �ڍׂɂ��Ă̓��t�@�����X�}�j���A�����Q�Ƃ��Ă��������B
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
* Description  : TMR�̃J�E���^�l��ݒ�
*
* Arguments    : uint16_t counter_val : �J�E���^�ɐݒ肷��l
*
* Return Value : true  : �J�E���^�l�̐ݒ�ɐ��������ꍇ
*              : false : �J�E���^�l�̐ݒ�Ɏ��s�����ꍇ
*
* Calling Functions : R_TMR_ControlUnit
*
* Details      : �ڍׂɂ��Ă̓��t�@�����X�}�j���A�����Q�Ƃ��Ă��������B
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
* Description  : TMR�̊��荞�ݗv���t���O�̎擾�ƃN���A
*
* Arguments    : bool * cma : �R���y�A�}�b�`A�t���O�̊i�[��
*              : bool * cmb : �R���y�A�}�b�`B�t���O�̊i�[��
*              : bool * ov : �I�[�o�t���[�t���O�̊i�[��
*
* Return Value : true  : �t���O�̎擾���������s��ꂽ�ꍇ
*              : false : �t���O�̎擾�Ɏ��s�����ꍇ
*
* Calling Functions : R_TMR_ReadUnit
*
* Details      : �ڍׂɂ��Ă̓��t�@�����X�}�j���A�����Q�Ƃ��Ă��������B
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
* Description  : TMR�̃��j�b�g���~
*
* Arguments    : �Ȃ�
*
* Return Value : true  : ��~�ɐ��������ꍇ
*              : false : ��~�Ɏ��s�����ꍇ
*
* Calling Functions : R_TMR_Destroy
*
* Details      : �ڍׂɂ��Ă̓��t�@�����X�}�j���A�����Q�Ƃ��Ă��������B
******************************************************************************/
bool R_PG_Timer_StopModule_TMR_U0(void)
{
	return R_TMR_Destroy( 0 );

}



