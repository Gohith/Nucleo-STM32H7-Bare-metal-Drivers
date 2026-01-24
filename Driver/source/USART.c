/*
 * USART.c
 *
 *  Created on: Jan 18, 2026
 *      Author: Gohith
 */

#include<USART.h>


/********************	MACROS	******************************/

#define USART_TX_COMPLETE_Bit			(1U << 6)
#define USART_TX_FIFO_NOT_FULL_Bit		(1U << 7)

/*********************	GLOBAL FUNCTIONS DEFINITION	********************/

/**
 * @brief	Function to initialize the USART/UART
 * @param	usart_config	pointer to user configuration structure
 * @return 	NONE
 */
void USART_init(usart_config_t *usart_config){
	usart_config->instance->CR1 &= ~(1U << 0);

	usart_config->instance->CR1 |= (usart_config->Word_Length & 0x1) << 12;

	usart_config->instance->CR1 |= ((usart_config->Word_Length >> 1) & 0x1) << 28;

	usart_config->instance->CR1 |= (usart_config->parity_control << 10);

	usart_config->instance->CR1 |= (usart_config->parity_selection << 9);

	usart_config->instance->CR2 |= (usart_config->stop_bits << 13);

	usart_config->instance->BRR = usart_config->baudrate;

	usart_config->instance->CR1 |= (usart_config->TX_enable << 3);

	usart_config->instance->CR1 |= (usart_config->RX_enable << 2);

	usart_config->instance->CR1 |= (1U << 0);
}

/**
 * @brief	Function to write one byte
 * @param	usart_config	pointer to user configuration structure
 * æparam	ui8data			one byte of data
 * @return 	NONE
 */
void USART_Write(usart_config_t *usart_config, uint8_t ui8data){
	while(!(usart_config->instance->ISR & USART_TX_FIFO_NOT_FULL_Bit)){

	}
	usart_config->instance->TDR = ui8data;
}

/**
 * @brief	Function to write block of data
 * @param	usart_config	pointer to user configuration structure
 * @param	ui8data			pointer to block of data
 * @param	ui8length		length of data
 * @return 	NONE
 */
void USART_Write_Block(usart_config_t *usart_config, const uint8_t *pui8data, uint8_t ui8length){
	for(uint8_t ui8size = 0; ui8size < ui8length; ui8size++){
		while(!(usart_config->instance->ISR & USART_TX_FIFO_NOT_FULL_Bit)){

		}
		usart_config->instance->TDR = pui8data[ui8size];
	}
}
