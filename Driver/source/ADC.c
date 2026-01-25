/*
 * ADC.c
 *
 *  Created on: Jan 25, 2026
 *      Author: Gohith
 */


#include<ADC.h>

/*************************	MACROS	**************************/
#define RESET	((uint32_t)0x00U)
#define SMPR1_LENGTH			9U
#define MAX_SEQUENCE_LENGTH		16U

#define SQR1_LIMIT				4U

#define SQR2_START				4U
#define SQR2_END				8U

#define SQR3_START				9U
#define SQR3_END				13U

#define SQR4_START				14U
#define SQR4_END				15U
/************************* USER FUNCTION PROTOTYPE	******************/

void ADC_Config_Channel(ADC_config_t*);
/************************* GLOBAL FUNCTION DEFINITION	******************/

/**
 * @brief	Function to initialize ADC
 * @param	handle	handle to ADC_config_t
 * @return 	NONE
 */
void ADC_init(ADC_config_t* handle){
	handle->instance->CR &= ~(1U << 0);
	handle->instance->CFGR = handle->mode;
	handle->instance->CFGR2 = handle->oversample;
	handle->instance->ISR = RESET;
	handle->instance->CR |= (1U << 0);

	ADC_Config_Channel(handle);
}

/**
 * @brief	Function to start the ADC
 * @param	handle	handle to ADC_config_t
 * @return 	NONE
 */
void ADC_Start(ADC_config_t* handle){
	// EOC CLEAR
	handle->instance->ISR |= (1U << 2);
	//ADC START
	handle->instance->CR |= (1U << 2);
}

/**
 * @brief	Function to read ADC
 * @param	handle	handle to ADC_config_t
 * @return 	uint16_t type data
 */
uint16_t ADC_Read(ADC_config_t* handle){
	while(!(handle->instance->ISR & (1U << 2))){
		// WAIT TILL EOC
	}
	return (((uint16_t)handle->instance->DR) & 0xFFFF);
}
/************************ USER FUNCTION DEFINITION	*********************/

/**
 * @brief	Function to configure the ADC channel, sequence length and sample rate
 * @param	handle	handle to ADC_config_t
 * @return 	NONE
 */
void ADC_Config_Channel(ADC_config_t* handle){
	if(handle->channel_length > MAX_SEQUENCE_LENGTH){
		handle->channel_length = MAX_SEQUENCE_LENGTH;
	}
	// SEQUENCE LENGTH
	handle->instance->SQR1 &= ~(0xFU << 0);
	handle->instance->SQR1 |= ((handle->channel_length) << 0);

	// CLEAR SQRx
	handle->instance->SQR1 &= ~((0x1FU << 6) | (0x1FU << 12) | (0x1FU << 18) | (0x1FU << 24));
	handle->instance->SQR2 &= ~((0x1FU << 0) | (0x1FU << 6) | (0x1FU << 12) | (0x1FU << 18));
	handle->instance->SQR3 &= ~((0x1FU << 0) | (0x1FU << 6) | (0x1FU << 12) | (0x1FU << 18));
	handle->instance->SQR4 &= ~((0x1FU << 0) | (0x1FU << 6));

	for(uint8_t ui8temp = 0U; ui8temp < handle->channel_length; ui8temp++){
		// CONFIGURE CHANNEL SEQUENCE
		if(ui8temp < SQR1_LIMIT){
			handle->instance->SQR1 |= (handle->channels[ui8temp] << ((ui8temp + 1U) * 6U));
		}
		else if(ui8temp >= SQR2_START && ui8temp <= SQR2_END){
			handle->instance->SQR2 |= (handle->channels[ui8temp] << ((ui8temp - 4U) * 6U));
		}
		else if(ui8temp >= SQR3_START && ui8temp <= SQR3_END){
			handle->instance->SQR3 |= (handle->channels[ui8temp] << ((ui8temp - 9U) * 6U));
		}
		else if(ui8temp >= SQR4_START && ui8temp <= SQR4_END){
			handle->instance->SQR3 |= (handle->channels[ui8temp] << ((ui8temp - 9U) * 6U));
		}

		// CONFIGURE SAMPLE TIME FOR CHANNEL
		if(handle->channels[ui8temp] < SMPR1_LENGTH){
			handle->instance->SMPR1 &= ~(0x7U << (ui8temp * 3U));
			handle->instance->SMPR1 |= (handle->sample_times[ui8temp] << (ui8temp * 3U));
		}
		else{
			handle->instance->SMPR2 &= ~(0x7U << (ui8temp * 3U));
			handle->instance->SMPR2 |= (handle->sample_times[ui8temp] << (ui8temp * 3U));
		}

	}
}



