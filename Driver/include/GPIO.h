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
 * GPIO peripheral port base address
 */
#define	GPIOA	0x58020000UL
#define GPIOB	0x58020400UL
#define GPIOC	0x58020800UL
#define GPIOD	0x58020C00UL
#define GPIOE	0x58021000UL
#define GPIOF	0x58021400UL
#define GPIOG	0x58021800UL
#define GPIOH	0x58021C00UL
#define GPIOI	0x58022000UL
#define GPIOJ	0x58022400UL
#define GPIOK	0x58022800UL

/**
 * GPIO registers
 */
typedef struct{
	uint32_t	MODER;		//!> GPIO Mode register
	uint32_t	OTYPER;		//!> Output type register
	uint32_t	OSPEEDR;	//!> Output speed register
	uint32_t	PUPDR;		//!> Pull-up, pull-down register
	uint32_t	IDR;		//!> Input Data Register
	uint32_t	ODR;		//!> Output Data Register
	uint32_t	BSRR;		//!> Bit set/reset register
	uint32_t	LCKR;		//!> Configuration Lock register
	uint32_t	AFRL;		//!> Alternate function LOW register
	uint32_t	AFRH;		//!> Alternate function HIGH register
}GPIO_register_t;

typedef struct{
	GPIO_register_t* PORT;	//!> GPIO PORT
	uint8_t PIN;			//!> GPIO PORT Pin
	bool OTYPER;			//!> Output type, Push-pull or open-drain
	uint8_t SPEED;			//!> SPEED
	uint8_t PULL_UP_DOWN;	//!> PULL-UP/PULL-DOWN
	uint8_t ALT_FUNCTION;	//!>
}GPIO_Config_t;

typedef enum{
	INPUT_MODE,
	OUTPUT_MODE,
	ALTERNATE_FUNCTION,
	ANALOG_MODE
}eGPIO_Mode_t;
/************************** GLOBAL FUNCTIONS **********************/

void GPIO_init(GPIO_Config_t *handle, eGPIO_Mode_t);
void GPIO_Set_Output(GPIO_register_t*, uint8_t, bool);
bool GPIO_Get_Input(GPIO_register_t*, uint8_t);


#endif /* GPIO_H_ */
