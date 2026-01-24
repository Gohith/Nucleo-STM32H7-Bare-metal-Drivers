/*
 * GPIO.c
 *
 *  Created on: Dec 26, 2025
 *      Author: Gohith
 */


#include "GPIO.h"

/**************** USER MACRO *******************/
#define	GPIO_AFRH_PIN	8U
#define HIGH			1U
#define LOW				0U
/**************** USER FUNCTION DECLARAION ****************/

void GPIO_Set_Mode(GPIO_register_t*, uint8_t, eGPIO_Mode_t);
void GPIO_Set_Speed(GPIO_register_t*, uint8_t, uint8_t);
void GPIO_Set_PullUpDown(GPIO_register_t*, uint8_t, uint8_t);
void GPIO_Set_Output_Type(GPIO_register_t*, uint8_t, uint8_t);
void GPIO_Set_AFR(GPIO_register_t*, uint8_t, uint8_t);

/**************** USER FUNCTIONS DEFINITIONS *****************/

/**
*	@brief Function to set the mode of GPIO pin
*	@param GPIOx	Pointer to GPIO port base address
*	@param ui8pin 	pin number between 0 to 15
*	@param mode		pin mode
*	@return NONE
*/
void GPIO_Set_Mode(GPIO_register_t *GPIOx, uint8_t ui8pin, eGPIO_Mode_t mode){
	GPIOx->MODER &= ~(0x3U << (2 * ui8pin));
	GPIOx->MODER |= (uint32_t)mode << (2 * ui8pin);
}

/**
 * @brief	Function to set the GPIO pin speed
 * @param GPIOx		Pointer to GPIO port base address
 * @param ui8pin	pin number betweeb 0 to 15
 * @param ui8speed	GPIO pin speed
 * @return NONE
 */
void GPIO_Set_Speed(GPIO_register_t* GPIOx, uint8_t ui8pin, uint8_t ui8speed){
	GPIOx->OSPEEDR &= ~(0x3U << (ui8pin * 2));
	GPIOx->OSPEEDR |= (ui8speed << (ui8pin * 2));
}

/**
 * @brief	Function to set the PULL-UP and PULL-DOWN of GPIO pin
 * @param GPIOx			Pointer to GPIO port base address
 * @param ui8pin		pin number betweeb 0 to 15
 * @param ui8PullUpDown	GPIO state
 * @return NONE
 */
void GPIO_Set_PullUpDown(GPIO_register_t* GPIOx, uint8_t pin, uint8_t ui8PullUpDown){
	GPIOx->PUPDR &= ~ (0x3U << (pin * 2));
	GPIOx->PUPDR |=  ((uint32_t)ui8PullUpDown << (pin * 2));
}

/**
 * @brief	Function to set the Output-type of GPIO pin
 * @param GPIOx			Pointer to GPIO port base address
 * @param ui8pin		pin number betweeb 0 to 15
 * @param ui8type		GPIO pin output type
 * @return NONE
 */
void GPIO_Set_Output_Type(GPIO_register_t* GPIOx, uint8_t ui8pin, uint8_t ui8type){
	if(ui8type){
		GPIOx->OTYPER |= (1U << ui8pin);
	}
	else{
		GPIOx->OTYPER &= ~(1U << ui8pin);
	}
}

/**
*	@brief Function to set the GPIO pin to alternate functionality
*	@param GPIOx	Pointer to GPIO port base address
*	@param pin 		pin number between 0 to 15
*	@param value	Alternate function value
	@return NONE
*/
void GPIO_Set_AFR(GPIO_register_t* GPIOx, uint8_t ui8pin, uint8_t ui8value){
	if (ui8pin < GPIO_AFRH_PIN){
		GPIOx->AFRL &= ~(0xFU << (ui8pin * 4));
		GPIOx->AFRL |= (uint32_t)ui8value << (ui8pin * 4);
	}else{
		GPIOx->AFRH &= ~(0xFU << ((ui8pin - 8) * 4));
		GPIOx->AFRH |= (uint32_t)ui8value << ((ui8pin - 8) * 4);
	}
}
/**************** GLOBAL FUNCTIONS DEFINITIONS	************************/
/**
*	@brief Function to init the GPIO pin
*	@param handle	pointer for type GPIO_Config_t, GPIO handle
*	@param mode		pin mode
*	@return NONE
*/
void GPIO_init(GPIO_Config_t *handle, eGPIO_Mode_t mode){
	GPIO_Set_Mode(handle->PORT, handle->PIN, mode);
	GPIO_Set_Speed(handle->PORT, handle->PIN, handle->SPEED);
	GPIO_Set_PullUpDown(handle->PORT, handle->PIN, handle->PULL_UP_DOWN);
	if(mode == ALTERNATE_FUNCTION || mode == OUTPUT_MODE){
		GPIO_Set_Output_Type(handle->PORT, handle->PIN, handle->OTYPER);
	}
	if(mode == ALTERNATE_FUNCTION){
		GPIO_Set_AFR(handle->PORT, handle->PIN, handle->ALT_FUNCTION);
	}
}

/**
*	@brief Function to set the GPIO pin state High
*	@param GPIOx	Pointer to GPIO port base address
*	@param ui8pin 	pin number between 0 to 15
*	@return NONE
*/
void GPIO_Set_Output_High(GPIO_register_t* GPIOx, uint8_t ui8pin){
	GPIOx->ODR &= ~(0x1U << ui8pin);
	GPIOx->ODR |= (uint16_t)HIGH << ui8pin;
}

/**
*	@brief Function to set the GPIO pin state Low
*	@param GPIOx	Pointer to GPIO port base address
*	@param ui8pin 	pin number between 0 to 15
*	@return NONE
*/
void GPIO_Set_Output_Low(GPIO_register_t* GPIOx, uint8_t ui8pin){
	GPIOx->ODR &= ~(0x1U << ui8pin);
}

/**
*	@brief Function to get the GPIO pin state
*	@param GPIOx	Pointer to GPIO port base address
*	@param ui8pin 	pin number between 0 to 15
*	@return boolean, HIGH-pin is high, LOW-pin is low
*/
bool GPIO_Get_Input(GPIO_register_t* GPIOx, uint8_t ui8pin){
	return ((GPIOx->IDR) & ((uint16_t)1U << ui8pin));
}
