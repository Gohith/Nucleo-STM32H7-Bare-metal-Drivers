/*
 * GPIO.h, consist of peripheral base and respective registers.
 *
 *  Created on: Dec 26, 2025
 *      Author: Gohith
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stdint.h"
#include "stdbool.h"



/**
 * GPIO registers
 */
typedef struct{
	volatile uint32_t	MODER;		//!> GPIO Mode register
	volatile uint32_t	OTYPER;		//!> Output type register
	volatile uint32_t	OSPEEDR;	//!> Output speed register
	volatile uint32_t	PUPDR;		//!> Pull-up, pull-down register
	volatile uint32_t	IDR;		//!> Input Data Register
	volatile uint32_t	ODR;		//!> Output Data Register
	volatile uint32_t	BSRR;		//!> Bit set/reset register
	volatile uint32_t	LCKR;		//!> Configuration Lock register
	volatile uint32_t	AFRL;		//!> Alternate function LOW register
	volatile uint32_t	AFRH;		//!> Alternate function HIGH register
}GPIO_register_t;

/**
 * GPIO peripheral port base address
 */
#define	GPIOA	((GPIO_register_t*)0x58020000UL)
#define GPIOB	((GPIO_register_t*)0x58020400UL)
#define GPIOC	((GPIO_register_t*)0x58020800UL)
#define GPIOD	((GPIO_register_t*)0x58020C00UL)
#define GPIOE	((GPIO_register_t*)0x58021000UL)
#define GPIOF	((GPIO_register_t*)0x58021400UL)
#define GPIOG	((GPIO_register_t*)0x58021800UL)
#define GPIOH	((GPIO_register_t*)0x58021C00UL)
#define GPIOI	((GPIO_register_t*)0x58022000UL)
#define GPIOJ	((GPIO_register_t*)0x58022400UL)
#define GPIOK	((GPIO_register_t*)0x58022800UL)

typedef struct{
	GPIO_register_t* PORT;	//!> GPIO PORT
	uint8_t PIN;			//!> GPIO PORT Pin
	uint8_t SPEED;			//!> SPEED
	uint8_t PULL_UP_DOWN:2;	//!> PULL-UP/PULL-DOWN
	uint8_t ALT_FUNCTION;	//!> AF Number (0 to 15)
	uint8_t OTYPER:1;		//!> Output type, 0:Push-Pull/1:Open-drain
}GPIO_Config_t;

typedef enum{
	INPUT_MODE,
	OUTPUT_MODE,
	ALTERNATE_FUNCTION,
	ANALOG_MODE
}eGPIO_Mode_t;

typedef enum{
	LOW_SPEED,
	MEDIUM_SPEED,
	HIGH_SPEED,
	VERY_HIGH_SPEED
}eGPIO_Speed_t;

typedef enum{
	PUSH_PULL,
	OPEN_DRAIN
}eGPIOx_OPType_t;

/************************** GLOBAL FUNCTIONS **********************/

void GPIO_init(GPIO_Config_t *handle, eGPIO_Mode_t);
void GPIO_Set_Output_High(GPIO_register_t*, uint8_t);
void GPIO_Set_Output_Low(GPIO_register_t*, uint8_t);
bool GPIO_Get_Input(GPIO_register_t*, uint8_t);
void GPIO_Set_AFR(GPIO_register_t*, uint8_t, uint8_t);


#endif /* GPIO_H_ */
