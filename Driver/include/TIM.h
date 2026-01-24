/*
 * TIM.h
 *
 *  Created on: Jan 12, 2026
 *      Author: Gohith
 */

#ifndef TIM_H_
#define TIM_H_

#include<stdint.h>


/************************** TIMER REGISTERS	********************/
/**
 *  TIMERS register declaration, not all addresses are used in all TIMERS.
 *  only certain addresses are USED/RESERVED for certain TIMERS
 */
typedef struct{
	volatile uint32_t CR1;				//!> 0x00
	volatile uint32_t CR2;				//!> 0x04	Used in TIM 6/7/12/15, RESERVED in TIM 13/14
	volatile uint32_t SMCR;				//!> 0x08   Used in TIM 2/3/4/5/12/15, RESERVED in TIM 6/7/13/14/16/17
	volatile uint32_t DIER;				//!> 0x0C
	volatile uint32_t SR;				//!> 0x10
	volatile uint32_t EGR;				//!> 0x14
	volatile uint32_t CCMR1;			//!> 0x18	RESERVED in TIM 6/7
	volatile uint32_t CCMR2;			//!> 0x1C	Used in TIM 2/3/4/5, RESERVED in TIM 6/7/12/13/14/15/16/17
	volatile uint32_t CCER;				//!> 0x20   RESERVED in TIM 6/7
	volatile uint32_t CNT;				//!> 0x24
	volatile uint32_t PSC;				//!> 0x28
	volatile uint32_t ARR;				//!> 0x2C
	//BASIC TIMERS (6/7) END HERE
	volatile uint32_t RCR		;		//!> 0x30	Used in TIM 15/16/17, RESERVED in TIM 2/3/4/5/12/13/14
	volatile uint32_t CCR1;				//!> 0x34
	volatile uint32_t CCR2;				//!> 0x38	Used in TIM 2/3/4/5/12/15, RESERVED in TIM 13/14/16/17
	volatile uint32_t CCR3;				//!> 0x3C	Used in TIM 2/3/4/5, RESERVED in TIM 12/13/14/15/16/17
	volatile uint32_t CCR4;				//!> 0x40   Used in TIM 2/3/4/5, RESERVED in TIM 12/13/14/15/16/17
	volatile uint32_t BDTR;				//!> 0x44	Used in TIM 15/16/17, RESERVED in TIM 2/3/4/5/12/13/14
	volatile uint32_t DCR;				//!> 0x48   Used in TIM 15/16/17, RESERVED in TIM 12/13/14
	volatile uint32_t DMAR;				//!> 0x4C   Used in TIM 15/16/17, RESERVED in TIM 12/13/14
	uint32_t reserved_1;				//!> 0x50
	volatile uint32_t CCMR3;			//!> 0x54	Used in TIM 1/8
	volatile uint32_t CCR5;				//!> 0x58   Used in TIM 1/8
	volatile uint32_t CCR6;				//!> 0x5C   Used in TIM 1/8
	volatile uint32_t AF1;				//!> 0x60   Used in TIM 2/3/4/5/15/16/17, RESERVED in TIM 12/13/14
	volatile uint32_t AF2;				//!> 0x64   Used in TIM 1/8
	volatile uint32_t TISEL;			//!> 0x68
}timer_reg_t;

typedef struct{
	uint32_t prescaler;
	uint32_t reload;
}TIMx_handle_t;
/**********************	GLOBAL FUNCTIONS   ********************/

void TIM_delay(void);

#endif /* TIM_H_ */
