/*
 * PWR.h
 *
 *  Created on: Jan 30, 2026
 *      Author: Gohith
 */

#ifndef PWR_H_
#define PWR_H_

#include<stdint.h>


/************************	PWR REGISTERS	********************/

typedef struct{
	volatile uint32_t CR1;			//0x00
	volatile uint32_t CSR1;			//0x04
	volatile uint32_t CR2;			//0x08
	volatile uint32_t CR3;			//0x0C
	volatile uint32_t CPU1CR;		//0x10
	volatile uint32_t CPU2CR;		//0x14
	volatile uint32_t D3CR;			//0x18
	volatile uint32_t Reserved;		//RESERVED
	volatile uint32_t WKUPCR;		//0x20
	volatile uint32_t WKUPFR;		//0x24
	volatile uint32_t WKUPEPR;		//0x28
}PWR_reg_t;

/************************	PWR BASE ADDRESS	****************/

#define PWR	((volatile PWR_reg_t*)0x58024800U)

#endif /* PWR_H_ */
