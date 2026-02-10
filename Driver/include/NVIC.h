/*
 * NVIC.h
 *
 *  Created on: Feb 10, 2026
 *      Author: Gohith
 */

#ifndef NVIC_H_
#define NVIC_H_

#include<stdint.h>

/****************************	NVIC REGISTER	***************************/

// INTERRUPT SET ENABLE REGISTERS
typedef struct{
	volatile uint32_t ISER0;			//0xE000E100
	volatile uint32_t ISER1;		 	//0xE000E104
	volatile uint32_t ISER2;			//0xE000E108
	volatile uint32_t ISER3;			//0xE000E10C
	volatile uint32_t ISER4;			//0xE000E110
	volatile uint32_t ISER5;			//0xE000E114
	volatile uint32_t ISER6;			//0xE000E118
	volatile uint32_t ISER7;			//0xE000E11C
}NVIC_ISER_reg_t;

// INTERRUPT CLEAR ENABLE REGISTERS
typedef struct{
	volatile uint32_t ICER0;			//0XE000E180
	volatile uint32_t ICER1;		 	//0XE000E184
	volatile uint32_t ICER2;			//0XE000E188
	volatile uint32_t ICER3;			//0XE000E18C
	volatile uint32_t ICER4;			//0XE000E190
	volatile uint32_t ICER5;			//0XE000E194
	volatile uint32_t ICER6;			//0XE000E198
	volatile uint32_t ICER7;			//0XE000E19C
}NVIC_ICER_reg_t;

// INTERRUPT SET PENDING REGISTERS
typedef struct{
	volatile uint32_t ISPR0;			//0XE000E200
	volatile uint32_t ISPR1;		 	//0XE000E204
	volatile uint32_t ISPR2;			//0XE000E208
	volatile uint32_t ISPR3;			//0XE000E20C
	volatile uint32_t ISPR4;			//0XE000E210
	volatile uint32_t ISPR5;			//0XE000E214
	volatile uint32_t ISPR6;			//0XE000E218
	volatile uint32_t ISPR7;			//0XE000E21C
}NVIC_ISPR_reg_t;

// INTERRUPT CLEAR PENDING REGISTERS
typedef struct{
	volatile uint32_t ICPR0;			//0XE000E280
	volatile uint32_t ICPR1;		 	//0XE000E284
	volatile uint32_t ICPR2;			//0XE000E288
	volatile uint32_t ICPR3;			//0XE000E28C
	volatile uint32_t ICPR4;			//0XE000E290
	volatile uint32_t ICPR5;			//0XE000E294
	volatile uint32_t ICPR6;			//0XE000E298
	volatile uint32_t ICPR7;			//0XE000E29C
}NVIC_ICPR_reg_t;

// INTERRUPT ACTIVE BIT REGISTERS
typedef struct{
	volatile uint32_t IABR0;			//0xE000E300
	volatile uint32_t IABR1;		 	//0xE000E304
	volatile uint32_t IABR2;			//0xE000E308
	volatile uint32_t IABR3;			//0xE000E30C
	volatile uint32_t IABR4;			//0xE000E310
	volatile uint32_t IABR5;			//0xE000E314
	volatile uint32_t IABR6;			//0xE000E318
	volatile uint32_t IABR7;			//0xE000E31C
}NVIC_IABR_reg_t;

/**
 * INTERRUPT PRIORITY SET REGISTERS EXCLUDED FOR FUTURE SCOPE,
 * INTERRUPT PRIORITY REGISTERS
typedef struct{
	volatile uint32_t ICPR0;
	volatile uint32_t ICPR1;
	volatile uint32_t ICPR2;
	volatile uint32_t ICPR3;
	volatile uint32_t ICPR4;
	volatile uint32_t ICPR5;
	volatile uint32_t ICPR6;
	volatile uint32_t ICPR7;
	.
	.
	.
	.
	UPTO 59
}NVIC_reg_t;
*/

/**********************	NVIC BASE ADDRESS	****************************/

#define NVIC_ISER	((volatile NVIC_ISER_reg_t*)0xE000E100U)		//INTERRUPT SET ENABLE
#define NVIC_ICER	((volatile NVIC_ICER_reg_t*)0XE000E180U)		//INTERRUPT CLEAR ENABLE
#define NVIC_ISPR	((volatile NVIC_ISPR_reg_t*)0XE000E200U)		//INTERRUPT SET PENDING
#define NVIC_ICPR	((volatile NVIC_ICPR_reg_t*)0XE000E280U)		//INTERRUPT CLEAR PENDING
#define NVIC_IABR	((volatile NVIC_IABR_reg_t*)0xE000E300U)		//INTERRUPT ACTIVE BIT
#define NVIC_IPR	((volatile NVIC_IPR_reg_t*)0xE000E400U)			//INTERRUPT PRIORITY
#define NVIC_SWTIR	*((volatile uint32_t*)0xE000EF00U)				//INTERRUPT SOFTWARE TRIGGER

/********************** GOBAL FUNCTIONS		*****************************/

void NVIC_Set_Interrupt_Enable(uint8_t);			//set interrupt
void NVIC_Clear_Interrupt_Enable(uint8_t);			// clear interrupt
void NVIC_Set_Interrupt_Pending(uint8_t);			// set pending interrupt
void NVIC_Clear_Interrupt_Pending(uint8_t);			// clear pending interrupt
uint8_t  NVIC_Read_Active_Bit(uint8_t);				// Read interrupt
void NVIC_Software_Trigger_Interrupt(uint8_t);		// set software interrupt


#endif /* NVIC_H_ */
