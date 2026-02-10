/*
 * NVIC.c
 *
 *  Created on: Feb 10, 2026
 *      Author: Gohith
 */

#include<NVIC.h>

/*******************************	INTERRUPT IRQ / NVIC POSITION	***********************/

#define IRQ31	31U
#define IRQ32	32U
#define IRQ64	64U
#define IRQ96	96U
#define IRQ128	128U
#define IRQ160	160U
#define IRQ192	192U
#define IRQ224	224U
#define IRQ256	256U
/*******************************	GLOBAL FUNCTION DEFINITIONS	***************************/
/**
 * @brief	Function to set the interrupt enable
 * @param 	ui8IRQ	type uint8_t 	Interrupt number
 * @return	NONE
 */
void NVIC_Set_Interrupt_Enable(uint8_t ui8IRQ){
	if(ui8IRQ <= IRQ31){
		NVIC_ISER->ISER0 |= 1U << ui8IRQ;
	}
	else if((ui8IRQ >= IRQ32) && (ui8IRQ < IRQ64)){
		NVIC_ISER->ISER1 |= 1U << (ui8IRQ - IRQ32);
	}
	else if((ui8IRQ >= IRQ64) && (ui8IRQ < IRQ96)){
		NVIC_ISER->ISER2 |= 1U << (ui8IRQ - 64);
	}
	else if((ui8IRQ >= IRQ96) && (ui8IRQ < IRQ128)){
		NVIC_ISER->ISER3 |= 1U << (ui8IRQ - IRQ64);
	}
	else if((ui8IRQ >= IRQ128) && (ui8IRQ < IRQ160)){
		NVIC_ISER->ISER4 |= 1U << (ui8IRQ - IRQ128);
	}
	else if((ui8IRQ >= IRQ160) && (ui8IRQ < IRQ192)){
		NVIC_ISER->ISER5 |= 1U << (ui8IRQ - IRQ160);
	}
	else if((ui8IRQ >= IRQ192) && (ui8IRQ < IRQ224)){
		NVIC_ISER->ISER6 |= 1U << (ui8IRQ - IRQ192);
	}
	else if((ui8IRQ >= IRQ224) && (ui8IRQ < IRQ256)){
		NVIC_ISER->ISER7 |= 1U << (ui8IRQ - IRQ224);
	}
}

/**
 * @brief	Function to clear the interrupt enable
 * @param 	ui8IRQ	type uint8_t 	Interrupt number
 * @return	NONE
 */
void NVIC_Clear_Interrupt_Enable(uint8_t ui8IRQ){
	if(ui8IRQ <= IRQ31){
		NVIC_ICER->ICER0 &= ~(1U << ui8IRQ);
	}
	else if((ui8IRQ >= IRQ32) && (ui8IRQ < IRQ64)){
		NVIC_ICER->ICER1 &= ~(1U << (ui8IRQ - IRQ32));
	}
	else if((ui8IRQ >= IRQ64) && (ui8IRQ < IRQ96)){
		NVIC_ICER->ICER2 &= ~(1U << (ui8IRQ - IRQ64));
	}
	else if((ui8IRQ >= IRQ96) && (ui8IRQ < IRQ128)){
		NVIC_ICER->ICER3 &= ~(1U << (ui8IRQ - IRQ96));
	}
	else if((ui8IRQ >= IRQ128) && (ui8IRQ < IRQ160)){
		NVIC_ICER->ICER4 &= ~(1U << (ui8IRQ - IRQ128));
	}
	else if((ui8IRQ >= IRQ160) && (ui8IRQ < IRQ192)){
		NVIC_ICER->ICER5 &= ~(1U << (ui8IRQ - IRQ160));
	}
	else if((ui8IRQ >= IRQ192) && (ui8IRQ < IRQ224)){
		NVIC_ICER->ICER6 &= ~(1U << (ui8IRQ - IRQ192));
	}
	else if((ui8IRQ >= IRQ224) && (ui8IRQ < IRQ256)){
		NVIC_ICER->ICER7 &= ~(1U << (ui8IRQ - IRQ224));
	}
}

/**
 * @brief	Function to set the interrupt pending
 * @param 	ui8IRQ	type uint8_t 	Interrupt number
 * @return	NONE
 */
void NVIC_Set_Interrupt_Pending(uint8_t ui8IRQ){
	if(ui8IRQ <= IRQ31){
		NVIC_ISPR->ISPR0 |= 1U << ui8IRQ;
	}
	else if((ui8IRQ >= IRQ32) && (ui8IRQ < IRQ64)){
		NVIC_ISPR->ISPR1 |= 1U << (ui8IRQ - IRQ32);
	}
	else if((ui8IRQ >= IRQ64) && (ui8IRQ < IRQ96)){
		NVIC_ISPR->ISPR2 |= 1U << (ui8IRQ - IRQ64);
	}
	else if((ui8IRQ >= IRQ96) && (ui8IRQ < IRQ128)){
		NVIC_ISPR->ISPR3 |= 1U << (ui8IRQ - IRQ96);
	}
	else if((ui8IRQ >= IRQ128) && (ui8IRQ < IRQ160)){
		NVIC_ISPR->ISPR4 |= 1U << (ui8IRQ - IRQ128);
	}
	else if((ui8IRQ >= IRQ160) && (ui8IRQ < IRQ192)){
		NVIC_ISPR->ISPR5 |= 1U << (ui8IRQ - IRQ160);
	}
	else if((ui8IRQ >= IRQ192) && (ui8IRQ < IRQ224)){
		NVIC_ISPR->ISPR6 |= 1U << (ui8IRQ - IRQ192);
	}
	else if((ui8IRQ >= IRQ224) && (ui8IRQ < IRQ256)){
		NVIC_ISPR->ISPR7 |= 1U << (ui8IRQ - IRQ224);
	}
}

/**
 * @brief	Function to clear the interrupt pending
 * @param 	ui8IRQ	type uint8_t 	Interrupt number
 * @return	NONE
 */
void NVIC_Clear_Interrupt_Pending(uint8_t ui8IRQ){
	if(ui8IRQ <= IRQ31){
		NVIC_ISPR->ISPR0 &= ~(1U << ui8IRQ);
	}
	else if((ui8IRQ >= IRQ32) && (ui8IRQ < IRQ64)){
		NVIC_ISPR->ISPR1 &= ~(1U << (ui8IRQ - IRQ32));
	}
	else if((ui8IRQ >= IRQ64) && (ui8IRQ < IRQ96)){
		NVIC_ISPR->ISPR2 &= ~(1U << (ui8IRQ - IRQ64));
	}
	else if((ui8IRQ >= IRQ96) && (ui8IRQ < IRQ128)){
		NVIC_ISPR->ISPR3 &= ~(1U << (ui8IRQ - IRQ96));
	}
	else if((ui8IRQ >= IRQ128) && (ui8IRQ < IRQ160)){
		NVIC_ISPR->ISPR4 &= ~(1U << (ui8IRQ - IRQ128));
	}
	else if((ui8IRQ >= IRQ160) && (ui8IRQ < IRQ192)){
		NVIC_ISPR->ISPR5 &= ~(1U << (ui8IRQ - IRQ160));
	}
	else if((ui8IRQ >= IRQ192) && (ui8IRQ < IRQ224)){
		NVIC_ISPR->ISPR6 &= ~(1U << (ui8IRQ - IRQ192));
	}
	else if((ui8IRQ >= IRQ224) && (ui8IRQ < IRQ256)){
		NVIC_ISPR->ISPR7 &= ~(1U << (ui8IRQ - IRQ224));
	}
}

/**
 * @brief	Function to read active interrupts
 * @param 	ui8IRQ	type uint8_t 	Interrupt number
 * @return	NONE
 */
uint8_t NVIC_Read_Active_Bit(uint8_t ui8IRQ){
	if(ui8IRQ <= IRQ31){
		return (NVIC_IABR->IABR0 & (1U << ui8IRQ));
	}
	else if((ui8IRQ >= IRQ32) && (ui8IRQ < IRQ64)){
		return (NVIC_IABR->IABR1 & (1U << (ui8IRQ - IRQ32)));
	}
	else if((ui8IRQ >= IRQ64) && (ui8IRQ < IRQ96)){
		return (NVIC_IABR->IABR2 & (1U << (ui8IRQ - IRQ64)));
	}
	else if((ui8IRQ >= IRQ96) && (ui8IRQ < IRQ128)){
		return (NVIC_IABR->IABR3 & (1U << (ui8IRQ - IRQ96)));
	}
	else if((ui8IRQ >= IRQ128) && (ui8IRQ < IRQ160)){
		return (NVIC_IABR->IABR4 & (1U << (ui8IRQ - IRQ128)));
	}
	else if((ui8IRQ >= IRQ160) && (ui8IRQ < IRQ192)){
		return (NVIC_IABR->IABR5 & (1U << (ui8IRQ - IRQ160)));
	}
	else if((ui8IRQ >= IRQ192) && (ui8IRQ < IRQ224)){
		return (NVIC_IABR->IABR6 & (1U << (ui8IRQ - IRQ192)));
	}
	else if((ui8IRQ >= IRQ224) && (ui8IRQ < IRQ256)){
		return (NVIC_IABR->IABR7 & (1U << (ui8IRQ - IRQ224)));
	}
	return 0;
}

/**
 * @brief	Function to set software interrupts
 * @param 	ui8IRQ	type uint8_t 	Interrupt number, should be only 9 bit value (0 to 239)
 * @return	NONE
 */
void NVIC_Software_Trigger_Interrupt(uint8_t ui8IRQ){
	NVIC_SWTIR |= ui8IRQ;
}

