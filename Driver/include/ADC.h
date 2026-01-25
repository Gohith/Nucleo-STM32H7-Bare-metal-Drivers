/*
 * ADC.h
 *
 *  Created on: Jan 25, 2026
 *      Author: Gohith
 */

#ifndef ADC_H_
#define ADC_H_

#include<stdint.h>

/*********************** ADC REGISTERS	*****************/

typedef struct{
	volatile uint32_t ISR;				// 0x00
	volatile uint32_t IER;				// 0x04
	volatile uint32_t CR;				// 0x08
	volatile uint32_t CFGR;				// 0x0C
	volatile uint32_t CFGR2;			// 0x10
	volatile uint32_t SMPR1;			// 0x14
	volatile uint32_t SMPR2;			// 0x18
	volatile uint32_t RESERVED[5];		// RESERVED
	volatile uint32_t SQR1;				// 0x30
	volatile uint32_t SQR2;				// 0x34
	volatile uint32_t SQR3;				// 0x38
	volatile uint32_t SQR4;				// 0x3C
	volatile uint32_t DR;				// 0x40
}ADC_reg_t;

//ADC CONFIG
typedef struct{
	ADC_reg_t *instance;	// ADC 1-3
	uint8_t channel_length;
	uint8_t *channels;
	uint8_t *sample_times;
	uint32_t mode;
	uint32_t oversample;
}ADC_config_t;

//ADC MODES
typedef enum{
	OVERRUN_MODE	= (1U << 12),
	CONTINUOUS_MODE	= (1U << 13),
	DELAYED_CONVERSION_MODE	= (1U << 14),
	DISCONTNUOUS_MODE	= (1U << 16),
	JSQR_MODE	= (1U << 21),
}eADC_Mode_t;

//ADC OVERSAMPLE TYPE
typedef enum{
	ENABLE_REGULAR_OVERSAMPLE	= (1U << 0),
	ENABLE_INJECTED_OVERSAMPLE	= (1U << 1),
	REGULAR_OVERSAMPLE_RESUME_MODE	= (1U << 10),		// RESUME MODE FOR OVERSAMPLING, NOT CONTINUOUS
}eOverSample_t;

/*********************** ADC BASE ADDRESS	****************/

#define ADC1			((volatile ADC_reg_t*)0x40022000U)		//!> ADC1 BASE ADDRESS, MASTER coupled with ADC2
#define ADC2			((volatile ADC_reg_t*)0x40022100U)		//!> ADC2 BASE ADDRESS, SLAVE coupled with ADC1
#define ADC3			((volatile ADC_reg_t*)0x58026000U)		//!> ADC3 INDEPENDENT MASTER BASE ADDRESS

//TODO Yet to develop common registers
#define ADC12_COMMON 	((volatile ADC_reg_t*)0x40022300U)		//!> ADC1, ADC2 COMMON REGISTER BASE ADDRESS
#define ADC3_COMMON		((volatile ADC_reg_t*)0x58026300U)		//!> ADC3 COMMON REGISTER BASE ADDRESS


/********************** GLOBAL FUNCTIONS	**********************/

void ADC_init(ADC_config_t*);
void ADC_Start(ADC_config_t*);
uint16_t ADC_Read(ADC_config_t*);

#endif /* ADC_H_ */
