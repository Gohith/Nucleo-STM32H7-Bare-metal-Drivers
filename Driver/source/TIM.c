/*
 * TIM.c
 *
 *  Created on: Jan 12, 2026
 *      Author: Gohith
 */


#include<TIM.h>

/************************	MACROS	***************************/
#define CLEAR_CNT	0U
#define CLK_ENABLE	(1U << 0)
#define SR_UIF		(1U <<0)

/************************	GLOBAL VARIABLES	****************/

volatile timer_reg_t* TIM1 = (volatile timer_reg_t*)0x40010000U;

volatile timer_reg_t* TIM2 = (volatile timer_reg_t*)0x40000000U;			//!> Used for simple delay

volatile timer_reg_t* TIM3 = (volatile timer_reg_t*)0x40000400U;

volatile timer_reg_t* TIM4 = (volatile timer_reg_t*)0x40000800U;

volatile timer_reg_t* TIM5 = (volatile timer_reg_t*)0x40000C00U;

volatile timer_reg_t* TIM6 = (volatile timer_reg_t*)0x40001000U;

volatile timer_reg_t* TIM7 = (volatile timer_reg_t*)0x40001400U;

volatile timer_reg_t* TIM8 = (volatile timer_reg_t*)0x40010400U;

volatile timer_reg_t* TIM12 = (volatile timer_reg_t*)0x40001800U;

volatile timer_reg_t* TIM13 = (volatile timer_reg_t*)0x40001C00U;

volatile timer_reg_t* TIM14 = (volatile timer_reg_t*)0x40002000U;

volatile timer_reg_t* TIM15 = (volatile timer_reg_t*)0x40014000U;

volatile timer_reg_t* TIM16 = (volatile timer_reg_t*)0x40014400U;

volatile timer_reg_t* TIM17 = (volatile timer_reg_t*)0x40014800U;

/************************	USER FUNCTION PROTOTYPE	*************/
void TIM2_init(void);		//!> Timer peripheral initialization

/************************	GLOBAL FUNCTIONS DEFINITION	*****************/

/**
 * @breif	Funtion to get delay
 * @param	NONE
 * @return 	NONE
 */
void TIM_delay(void){
	TIM2_init();
	while(!(TIM2->SR & SR_UIF)){

	}
	TIM2->SR &= ~(SR_UIF);
}

/************************	USER FUNCTION DEFINITION	*************/

/**
 * @breif	Funtion to initilaize timer, by default it is hardcoded to have 1ms of delay at 64MHz clock
 * @param	NONE
 * @return 	NONE
 */
void TIM2_init(void){
	TIMx_handle_t hTim2 = {
			.prescaler = 64000-1,
			.reload = 1000-1,
	};
	TIM2->PSC = hTim2.prescaler;
	TIM2->ARR = hTim2.reload;
	TIM2->CNT = CLEAR_CNT;
	TIM2->CR1 = CLK_ENABLE;
}
