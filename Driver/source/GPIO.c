/*
 * GPIO.c
 *
 *  Created on: Dec 26, 2025
 *      Author: Gohith
 */


#include "GPIO.h"

/**************** USER MACRO *******************/
#define	GPIO_AFRH_PIN	8U
/**************** LOCAL FUNCTION DECLARAION ****************/

void GPIO_Set_Mode(GPIO_register_t*, uint8_t, eGPIO_Mode_t);

/**************** GLOBAL FUNCTIONS *****************/

void GPIO_init(GPIO_Config_t *handle, eGPIO_Mode_t mode){
	GPIO_Set_Mode(handle->PORT, handle->PIN, mode);
}

/**************** LOCAL FUNCTIONS *****************/

void GPIO_Set_Mode(GPIO_register_t *GPIOx, uint8_t pin, eGPIO_Mode_t mode){
	GPIOx->MODER &= ~(0x3U << (2 * pin));
	GPIOx->MODER |= (uint32_t)mode << (2 * pin);
}

/**************** GLOBAL FUNCTIONS ************************/
void GPIO_Set_Output(GPIO_register_t* GPIOx, uint8_t pin,  bool output){
	GPIOx->ODR &= ~(0x3U << pin);
	GPIOx->ODR |= (uint16_t)output << pin;
}

bool GPIO_Get_Input(GPIO_register_t* GPIOx, uint8_t pin){
	return (GPIOx->IDR & ((uint16_t)1U << pin)) != 0U;
}

void GPIO_Set_AFR(GPIO_register_t* GPIOx, uint8_t pin, uint8_t value){
	if (pin < GPIO_AFRH_PIN){
		GPIOx->AFRH &= ~(0xFU << (pin * 4));
		GPIOx->AFRH |= (uint32_t)value << (pin * 4);
	}else{
		GPIOx->AFRL &= ~(0xFU << (pin * 4));
		GPIOx->AFRL |= (uint32_t)value << (pin * 4);
	}
}
