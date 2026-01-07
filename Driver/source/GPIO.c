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

/**
*	@brief Function to init the GPIO pin 
*	@param handle	pointer for type GPIO_Config_t, GPIO handle
*	@param mode		pin mode
	@return NONE
*/
void GPIO_init(GPIO_Config_t *handle, eGPIO_Mode_t mode){
	GPIO_Set_Mode(handle->PORT, handle->PIN, mode);
}

/**************** LOCAL FUNCTIONS *****************/

/**
*	@brief Function to set the mode of GPIO pin 
*	@param GPIOx	Pointer to GPIO port base address
*	@param pin 		pin number between 0 to 15
*	@param mode		pin mode
	@return NONE
*/
void GPIO_Set_Mode(GPIO_register_t *GPIOx, uint8_t pin, eGPIO_Mode_t mode){
	GPIOx->MODER &= ~(0x3U << (2 * pin));
	GPIOx->MODER |= (uint32_t)mode << (2 * pin);
}

/**************** GLOBAL FUNCTIONS ************************/

/**
*	@brief Function to set the GPIO pin state
*	@param GPIOx	Pointer to GPIO port base address
*	@param pin 		pin number between 0 to 15
*	@param output	pin output, either High or Low
	@return NONE
*/
void GPIO_Set_Output(GPIO_register_t* GPIOx, uint8_t pin,  bool output){
	GPIOx->ODR &= ~(0x3U << pin);
	GPIOx->ODR |= (uint16_t)output << pin;
}

/**
*	@brief Function to get the GPIO pin state
*	@param GPIOx	Pointer to GPIO port base address
*	@param pin 		pin number between 0 to 15
	@return boolean, HIGH-pin is high, LOW-pin is low
*/
bool GPIO_Get_Input(GPIO_register_t* GPIOx, uint8_t pin){
	return (GPIOx->IDR & ((uint16_t)1U << pin)) != 0U;
}

/**
*	@brief Function to set the GPIO pin to alternate functionality
*	@param GPIOx	Pointer to GPIO port base address
*	@param pin 		pin number between 0 to 15
*	@param value	Alternate function value
	@return NONE
*/
void GPIO_Set_AFR(GPIO_register_t* GPIOx, uint8_t pin, uint8_t value){
	if (pin < GPIO_AFRH_PIN){
		GPIOx->AFRH &= ~(0xFU << (pin * 4));
		GPIOx->AFRH |= (uint32_t)value << (pin * 4);
	}else{
		GPIOx->AFRL &= ~(0xFU << (pin * 4));
		GPIOx->AFRL |= (uint32_t)value << (pin * 4);
	}
}
