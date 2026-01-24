/*
 * RCC.c
 *
 *  Created on: Jan 10, 2026
 *      Author: Gohith
 */


#include <RCC.h>


/**********************	GLOBAL VARIABLE	*********************/
volatile RCC_reg_t *RCC = (volatile RCC_reg_t *)0x58024400U;

/************* GLOBAL FUNCTIONS DEFINITIONS	******************/

/**
 * @brief	Function to enable the GPIO
 * @param	GPIO
 * @return 	NONE
 */
void RCC_Enable_GPIOx(eGPIOx_t GPIOx){
	RCC->AHB4EN |= 1U << GPIOx;
}

/**
 * @brief	Function to disable the GPIO
 * @param	GPIO
 * @return 	NONE
 */
void RCC_Disable_GPIOx(eGPIOx_t GPIOx){
	RCC->AHB4EN &= ~(1U << GPIOx);
}

/**
 * @brief	Function to enable the TIMER
 * @param	TIMER
 * @return 	NONE
 */
void RCC_Enable_TIMx(eTIMx_t TIMx){
	switch(TIMx){
	case RCC_TIM1:	RCC->APB2ENR |= 1U << 0;
					break;
	case RCC_TIM2:	RCC->APB1LENR |= 1U << 0;
					break;
	case RCC_TIM3:	RCC->APB1LENR |= 1U << 1;
					break;
	case RCC_TIM4:	RCC->APB1LENR |= 1U << 2;
					break;
	case RCC_TIM5:	RCC->APB1LENR |= 1U << 3;
					break;
	case RCC_TIM6:	RCC->APB1LENR |= 1U << 4;
					break;
	case RCC_TIM7:	RCC->APB1LENR |= 1U << 5;
					break;
	case RCC_TIM8:	RCC->APB2ENR |= 1U << 1;
					break;
	case RCC_TIM12:	RCC->APB1LENR |= 1U << 6;
					break;
	case RCC_TIM13:	RCC->APB1LENR |= 1U << 7;
					break;
	case RCC_TIM14:	RCC->APB1LENR |= 1U << 8;
					break;
	case RCC_TIM15:	RCC->APB2ENR |= 1U << 16;
					break;
	case RCC_TIM16:	RCC->APB2ENR |= 1U << 17;
					break;
	case RCC_TIM17:	RCC->APB2ENR |= 1U << 18;
					break;
	default:
			break;
	}

}

/**
 * @brief	Function to disable the TIMER
 * @param	TIMER
 * @return 	NONE
 */
void RCC_Disable_TIMx(eTIMx_t TIMx){
	switch(TIMx){
	case RCC_TIM1:	RCC->APB2ENR &= ~(1U << 0);
					break;
	case RCC_TIM2:	RCC->APB1LENR &= ~(1U << 0);
					break;
	case RCC_TIM3:	RCC->APB1LENR &= ~(1U << 1);
					break;
	case RCC_TIM4:	RCC->APB1LENR &= ~(1U << 2);
					break;
	case RCC_TIM5:	RCC->APB1LENR &= ~(1U << 3);
					break;
	case RCC_TIM6:	RCC->APB1LENR &= ~(1U << 4);
					break;
	case RCC_TIM7:	RCC->APB1LENR &= ~(1U << 5);
					break;
	case RCC_TIM8:	RCC->APB2ENR &= ~(1U << 1);
					break;
	case RCC_TIM12:	RCC->APB1LENR &= ~(1U << 6);
					break;
	case RCC_TIM13:	RCC->APB1LENR &= ~(1U << 7);
					break;
	case RCC_TIM14:	RCC->APB1LENR &= ~(1U << 8);
					break;
	case RCC_TIM15:	RCC->APB2ENR &= ~(1U << 16);
					break;
	case RCC_TIM16:	RCC->APB2ENR &= ~(1U << 17);
					break;
	case RCC_TIM17:	RCC->APB2ENR &= ~(1U << 18);
					break;
	default:
			break;
	}
}

/**
 * @brief	Function to enable the USART
 * @param	USART/UART
 * @return 	NONE
 */
void RCC_Enable_USARTx(eUSARTx_t USARTx){
	switch(USARTx){
	case RCC_USART1: RCC->APB2ENR |= (1U << 4);
					 break;
	case RCC_USART2: RCC->APB1LENR |= (1U << 17);
					 break;
	case RCC_USART3: RCC->APB1LENR |= (1U << 18);
					 break;
	case RCC_UART4: RCC->APB1LENR |= (1U << 19);
					break;
	case RCC_UART5: RCC->APB1LENR |= (1U << 20);
					break;
	case RCC_USART6: RCC->APB2ENR |= (1U << 5);
					break;
	case RCC_UART7: RCC->APB1LENR |= (1U << 30);
				    break;
	case RCC_UART8: RCC->APB1LENR |= (1U << 31);
					break;
	default:
			break;
	}
}

/**
 * @brief	Function to disable the USART
 * @param	USART/UART
 * @return 	NONE
 */
void RCC_Disable_USARTx(eUSARTx_t USARTx){
	switch(USARTx){
	case RCC_USART1: RCC->APB2ENR &= ~(1U << 4);
					 break;
	case RCC_USART2: RCC->APB1LENR &= ~(1U << 17);
					 break;
	case RCC_USART3: RCC->APB1LENR &= ~(1U << 18);
					 break;
	case RCC_UART4: RCC->APB1LENR &= ~(1U << 19);
					break;
	case RCC_UART5: RCC->APB1LENR &= ~(1U << 20);
					break;
	case RCC_USART6: RCC->APB2ENR &= ~(1U << 5);
					break;
	case RCC_UART7: RCC->APB1LENR &= ~(1U << 30);
				    break;
	case RCC_UART8: RCC->APB1LENR &= ~(1U << 31);
					break;
	default:
			break;
	}
}
