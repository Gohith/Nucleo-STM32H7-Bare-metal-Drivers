/*
 * USART.c
 *
 *  Created on: Jan 18, 2026
 *      Author: Gohith
 */

#include<USART.h>
#include<stddef.h>


/********************	MACROS	******************************/

#define USART_TX_FIFO_NOT_FULL_BIT		(1U << 7)
#define USART_RX_FIFO_NOT_EMPTY_BIT		(1U << 5)

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
	while(!(usart_config->instance->ISR & USART_TX_FIFO_NOT_FULL_BIT)){
		// TX FIFO
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
		while(!(usart_config->instance->ISR & USART_TX_FIFO_NOT_FULL_BIT)){

		}
		usart_config->instance->TDR = pui8data[ui8size];
	}
}

/**
 * @brief	Function to read one byte
 * @param	usart_config_t	USART Config pointer
 * @return	uint8_t 	one byte of data
 */
uint8_t USART_Read(usart_config_t *usart_config){
	while(!(usart_config->instance->ISR & USART_RX_FIFO_NOT_EMPTY_BIT)){
			// Data Not Received
		}
	uint8_t ui8data = usart_config->instance->RDR;
	return ui8data;
}

/**
 * @brief	Function to read block of data
 * @param	usart_config_t	USART Config pointer
 * @return	uint8_t* 		Block of data
 */
uint8_t* USART_Read_Block(usart_config_t *usart_config, uint8_t length){
	uint8_t *pui8data = NULL;
	while(!(usart_config->instance->ISR & USART_RX_FIFO_NOT_EMPTY_BIT)){
			// Data Not Received
		}
	for(uint8_t ui8size = 0; ui8size < length; length++){
		pui8data[ui8size] = usart_config->instance->RDR;
	}
	return pui8data;
}
