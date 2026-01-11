/*
 * RCC.c
 *
 *  Created on: Jan 10, 2026
 *      Author: Gohith
 */


#include <RCC.h>


volatile RCC_reg_t *RCC = (volatile RCC_reg_t *)0x58024400U;

/************* GLOBAL FUNCTIONS ******************/

void RCC_Enable_GPIOx(eGPIOx_t GPIOx){
	RCC->AHB4EN |= 1U << GPIOx;
}

void RCC_Disable_GPIOx(eGPIOx_t GPIOx){
	RCC->AHB4EN &= ~(1U << GPIOx);
}

