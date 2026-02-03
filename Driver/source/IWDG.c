/*
 * IWDG.c
 *
 *  Created on: Feb 3, 2026
 *      Author: Gohith
 */

#include<IWDG.h>
#include<RCC.h>


#define IWDG_ENABLE_KEY		0xCCCCU
#define IWDG_WRITE_KEY		0x5555U
#define IWDG_RELOAD_KEY		0xAAAAU

#define CSI_ON				1U << 7
#define CSI_READY			1U << 8

/************************	GLOBAL FUNCTION DEFINITION	***********************/
/**
 * 	@brief	Function to init the independent watchdog
 * 	@param	config	configurtion of prescaler, window using key
 * 	@return	NONE
 */
void IWDG_init(IWDG_config_t* config){
	RCC->CR |= CSI_ON;
	while((RCC->CR & CSI_READY) == 0){
				// wait to initialize CSI (clock security Internal)
	}
	config->instance->KR |= IWDG_ENABLE_KEY;
	config->instance->KR |= IWDG_WRITE_KEY;

	config->instance->PR = config->prescale;
	config->instance->RLR = config->reload;
	while(config->instance->SR != 0){
		//wait till the flag is set to 0
	}
	config->instance->KR = IWDG_RELOAD_KEY;
}

/**
 * @brief	Function to refresh the Independent watchdog counter
 * @param	NONE
 * @retrun 	NONE
 */
void IWDG_refresh(IWDG_config_t *config){
	// writing the key to keyregister makes reload
	config->instance->KR = IWDG_RELOAD_KEY;
}
