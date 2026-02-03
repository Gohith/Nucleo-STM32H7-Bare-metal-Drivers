/*
 * IWDG.h
 *
 *  Created on: Feb 3, 2026
 *      Author: Gohith
 */

#ifndef IWDG_H_
#define IWDG_H_

#include<stdint.h>

/******************************	IWDG REGISTER	**************************/

typedef struct{
	volatile uint32_t KR;
	volatile uint32_t PR;
	volatile uint32_t RLR;
	volatile uint32_t SR;
	volatile uint32_t WINR;
}IWDG_reg_t;

typedef struct{
	IWDG_reg_t *instance;
	uint16_t reload;
	uint8_t prescale:3;
	uint16_t window:12;
}IWDG_config_t;

typedef enum{
	DIVIDER_4 = 0,
	DIVIDER_8,
	DIVIDER_16,
	DIVIDER_32,
	DIVIDER_64,
	DIVIDER_128,
	DIVIDER_256,
	DIVIDER_256_,
}eLSI_prescaler;

/**************************	IWDG BASE ADDRESS	***************************/

#define IWDG1	((volatile IWDG_reg_t*)0x58004800U)
#define IWDG2	((volatile IWDG_reg_t*)0x58004C00U)
/***************************	GLOBAL FUNCTION	**************************/

void IWDG_init(IWDG_config_t*);
void IWDG_refresh(IWDG_config_t*);

#endif /* IWDG_H_ */
