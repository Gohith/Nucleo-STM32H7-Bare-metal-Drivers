/*
 * GPIO.c
 *
 *  Created on: Dec 26, 2025
 *      Author: Gohith
 */


#include "GPIO.h"

/**************** USER MACRO *******************/

/**************** LOCAL FUNCTION DECLARAION ****************/

void GPIO_Set_Mode(GPIO_register_t*, uint8_t, eGPIO_Mode_t);

/**************** GLOBAL FUNCTIONS *****************/

void GPIO_init(GPIO_Config_t *handle, eGPIO_Mode_t mode){
	GPIO_Set_Mode(handle->PORT, handle->PIN, mode);
}

/**************** LOCAL FUNCTIONS *****************/

void GPIO_Set_Mode(GPIO_register_t *GPIOx, uint8_t pin, eGPIO_Mode_t mode){
	GPIOx->MODER = (uint32_t)mode << (2 * pin);
}

void GPIO_Set_Output(GPIO_register_t* GPIOx, uint8_t pin,  bool output){
	GPIOx->ODR = (uint16_t)output << pin;
}

bool GPIO_Get_Input(GPIO_register_t* GPIOx, uint8_t pin){
	return (GPIOx->IDR & ((uint16_t)1U << pin));
}
