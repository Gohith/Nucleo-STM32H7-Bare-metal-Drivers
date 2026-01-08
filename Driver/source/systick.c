/*
 * systick.c
 *
 *  Created on: Jan 8, 2026
 *      Author: g4zeal
 */

#include<systick.h>

volatile systick_register_t *SYST = (volatile systick_register_t*)0xE000E010U;

/****************** MACRO ****************************/
#define CTRL_ENABLE		(1U<<0)
#define CTRL_DISABLE	(0U<<0)
#define CLK_SOURCE		(1U<<2)
#define CTRL_COUNTFLAG	(1U<<16)
#define CTRL_CLEAR		(0U)
#define CTRL_INT		(1U<<1)

#define CPU_HZ	(64000000U)		//!> 64MHz (change this as per Clock frequency)
#define to_ms	(1000U)			//!> 1 second
/****************** GLOBAL VARIABLES ******************/
static volatile uint32_t systick_ticks = 0;

/****************** LOCAL FUNCTIONS PROTOTYPE *******************/
static void systick_counter_init(uint32_t);
static uint32_t systick_get_ticks(void);

/****************** GLOBAL FUNCTIONS ******************/
/**
 * @brief function to delay using the tick count
 * @param delay
 * @return NONE
 */
void systick_delay(uint32_t delay){
	systick_counter_init(CPU_HZ/ to_ms);

	uint32_t start_ticks = systick_get_ticks();
	while((systick_get_ticks() - start_ticks) < delay){
	}
	SYST->CSR = CTRL_DISABLE;
}
/****************** LOCAL FUNCTIONS *******************/
/**
 * @brief function to initialize the systick counter
 * @param value reload value to the counter
 * @return NONE
 */
void systick_counter_init(uint32_t value){

	SYST->RVR = value - 1;
	SYST->CVR = CTRL_CLEAR;
	SYST->CSR = (CTRL_ENABLE | CLK_SOURCE | CTRL_INT);
}

/**
 * @brief function to get the ticks counted
 * @param NONE
 * @return tick count
 */
static uint32_t systick_get_ticks(void){
	return systick_ticks;
}

/**
 * counter handler
 */
void SysTick_Handler(void){
	systick_ticks++;
}
