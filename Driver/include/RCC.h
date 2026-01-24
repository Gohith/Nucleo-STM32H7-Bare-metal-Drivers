/*
 * RCC.h
 *
 *  Created on: Jan 10, 2026
 *      Author: Gohith
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>

/**********************	Data Types	*************************/
typedef struct{
	uint32_t reserved_1[56];	//!> RESERVED
	volatile uint32_t AHB4EN;	//!> 0x0E0
	uint32_t reserved_2[1];		//!> RESERVED
	volatile uint32_t APB1LENR;	//!> 0x0E8
	volatile uint32_t APB1HENR;	//!> 0x0EC
	volatile uint32_t APB2ENR;	//!> 0x0F0
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

typedef enum{
	RCC_TIM1,		//!> Advanced Timer 1
	RCC_TIM2,		//!> General Purpose Timer 2
	RCC_TIM3,		//!> General Purpose Timer 3
	RCC_TIM4,		//!> General Purpose Timer 4
	RCC_TIM5,		//!> General Purpose Timer 5
	RCC_TIM6,		//!> Basic Timer 6
	RCC_TIM7,		//!> Basic Timer 7
	RCC_TIM8,		//!> Advanced Timer 8
	RCC_TIM12,		//!> General Purpose Timer 12
	RCC_TIM13,		//!> General Purpose Timer 13
	RCC_TIM14,		//!> General Purpose Timer 14
	RCC_TIM15,		//!> General Purpose Timer 15
	RCC_TIM16,		//!> General Purpose Timer 16
	RCC_TIM17		//!> General Purpose Timer 17
}eTIMx_t;

typedef enum{
	RCC_USART1 = 1,	//APB2
	RCC_USART2,		//APB1
	RCC_USART3,		//APB1
	RCC_UART4,		//APB1
	RCC_UART5,		//APB1
	RCC_USART6,		//APB2
	RCC_UART7,		//APB1
	RCC_UART8		//APB1
}eUSARTx_t;

/***************** GLOBAL FUNCTION ****************/

void RCC_Enable_GPIOx(eGPIOx_t);
void RCC_Disable_GPIOx(eGPIOx_t);

void RCC_Enable_TIMx(eTIMx_t);
void RCC_Disable_TIMx(eTIMx_t);

void RCC_Enable_USARTx(eUSARTx_t);
void RCC_Disable_USARTx(eUSARTx_t);

#endif /* RCC_H_ */
