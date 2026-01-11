/*
 * RCC.h
 *
 *  Created on: Jan 10, 2026
 *      Author: Gohith
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>


typedef struct{
	uint32_t reserved[56];		// RESERVED
	volatile uint32_t AHB4EN;	//!> 0x0E0

}RCC_reg_t;

typedef enum{
	RCC_GPIOA,
	RCC_GPIOB,
	RCC_GPIOC,
	RCC_GPIOD,
	RCC_GPIOE,
	RCC_GPIOF,
	RCC_GPIOG,
	RCC_GPIOH,
	RCC_GPIOI,
	RCC_GPIOJ,
	RCC_GPIOK
}eGPIOx_t;

/***************** GLOBAL FUNCTION ****************/

void RCC_Enable_GPIOx(eGPIOx_t);
void RCC_Disable_GPIOx(eGPIOx_t);

#endif /* RCC_H_ */
