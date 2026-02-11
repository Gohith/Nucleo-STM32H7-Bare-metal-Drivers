/*
 * SPI.c
 *
 *  Created on: Feb 11, 2026
 *      Author: Gohith
 */

#include<SPI.h>

/*****************************	MACROS	***********************************************/

#define CLEAR		0x00000000UL
#define CLEAR_IFCR	0xFFFFFFFFUL
#define SPI_ENABLE	1U

#define SPI_MASTER_SLAVE_BIT	22U
#define SPI_SSM					0U
#define SPI_SSOE				1U << 29		// No Multi-Master

#define SPI_MODE_CPOL				1U << 25	// SCLK is at HIGH at IDLE
#define SPI_MODE_CPHA				1U << 24	// Data is shifted out on the leading edge

#define SPI_BIT_ORDER_LSB_FIRST		1U << 23
#define SPI_MBR						30U
#define SPI_DATA_SIZE_BIT			4U

#define SPI_TSIZE					0xFFFFUL
#define SPI_EOT						1U << 3
#define SPI_OVRC					1U << 6

#define SPI_SR_TXP					1U << 1		// Tx buffer flag
#define SPI_SR_RXP					1U << 0		// RX available flag
#define SPI_SR_EOT					1U << 3

/*****************************	USER FUNCTION PROTOTYPE		****************************/
void SPI_Set_Mode(SPI_reg_t*, SPI_mode_t );
void clear_config_registers(SPI_reg_t*);
void SPI_Config(SPI_config_t*);

/*****************************	GLOBAL FUNCTION DEFINITION	*****************************/
/**
 * @brief	Function to Init the SPI
 * @param	SPIx_config	Configuration data structure
 * @return 	NONE
 */
void SPI_Init(SPI_config_t *SPIx_config){
	// Enable clock for SPI
	// Config GPIO for SPI
	SPI_Disable(SPIx_config->instance);
	clear_config_registers(SPIx_config->instance);
	SPI_Config(SPIx_config);
}

/**
 * @brief	Function to enable the SPI
 * @param	SPIx	SPI peripheral
 * @return 	NONE
 */
void SPI_Enable(SPI_reg_t *SPIx){
	SPIx->CR1 |= SPI_ENABLE;
}

/**
 * @brief	Function to disable the SPI
 * @param	SPIx	SPI peripheral
 * @return 	NONE
 */
void SPI_Disable(SPI_reg_t *SPIx){
	SPIx->CR1 &= ~SPI_ENABLE;
}

/**
 * @brief	Function to Transfer and Read the buffer
 * @param	SPIx		SPI peripheral
 * @param	Tx_buffer	Data to be transferred
 * @param	Rx_buffer	Data to be read back
 * @param	length		Length of data to be transferred
 * @return 	NONE
 */
void SPI_Transfer(SPI_reg_t *SPIx, uint32_t *Tx_buffer, uint32_t *Rx_buffer, size_t  length){
	if(length == 0){
		return;
	}
	// Config TSIZE
	SPIx->CR2 |= ((uint32_t)length & SPI_TSIZE);
	// Clear Flags
	SPIx->IFCR = (SPI_EOT|SPI_OVRC);
	SPI_Enable(SPIx);

	for(size_t data_byte = 0; data_byte < length; data_byte++){
		while((SPIx->SR & SPI_SR_TXP) == 0U){
			// Space not available, wait till available
		}
		SPIx->TXDR = (uint32_t)Tx_buffer[data_byte];
		while((SPIx->SR & SPI_SR_RXP) == 0U){
			// Wait till Rx is available
		}
		Rx_buffer[data_byte] = SPIx->RXDR;
	}
	while((SPIx->IFCR & SPI_SR_EOT) == 0U){
		// wait till transfr is complete
	}
	SPIx->IFCR = SPI_EOT;
}

/******************************	USER FUNCTIONS DEFINITION	************************************/

/**
 * @brief	Function to clear configurtion registers of the SPI
 * @param	SPIx	SPI peripheral
 * @return 	NONE
 */
void clear_config_registers(SPI_reg_t *SPIx){
	SPIx->CFG1 = CLEAR;
	SPIx->CFG2 = CLEAR;
	SPIx->CR1 = CLEAR;
	SPIx->CR2 = CLEAR;
	SPIx->IER = CLEAR;
	SPIx->IFCR = CLEAR_IFCR;
}

/**
 * @brief	Function to config the registers of the SPI
 * @param	SPIx_config	Configuration data structure
 * @return 	NONE
 */
void SPI_Config(SPI_config_t *SPIx_config){
	// Master or Slave
	SPIx_config->instance->CFG2 |= (SPIx_config->Master_or_Slave << SPI_MASTER_SLAVE_BIT);
	// No Multimaster and use SS as bit
	SPIx_config->instance->CFG2 |= (SPI_SSOE);
	// SPI Mode
	SPI_Set_Mode(SPIx_config->instance, SPIx_config->mode);
	// Config Bit order
	if(SPIx_config->bit_oder == LSB_FIRST){
		SPIx_config->instance->CFG2 |= SPI_BIT_ORDER_LSB_FIRST;
	}
	else{
		SPIx_config->instance->CFG2 &= ~SPI_BIT_ORDER_LSB_FIRST;
	}
	// Config Baud-Prescaler
	SPIx_config->instance->CFG1 |= (SPIx_config->baud_prescaler << SPI_MBR);
	// Config Data Size
	SPIx_config->instance->CFG1 |= (SPIx_config->data_size << SPI_DATA_SIZE_BIT);
}

/**
 * @brief	Function to config the registers of the SPI
 * @param	SPIx		SPI peripheral
 * @param	SPIx_mode	SPI mode
 * @return 	NONE
 */
void SPI_Set_Mode(SPI_reg_t *SPIx, SPI_mode_t SPIx_mode){
	switch(SPIx_mode){
		case MODE_0:
					// CPHA = CPOL = 0
					break;
		case MODE_1:
					SPIx->CFG2 |= SPI_MODE_CPHA;
					break;
		case MODE_2:
					SPIx->CFG2 |= SPI_MODE_CPOL;
					break;
		case MODE_3:
					SPIx->CFG2 |= SPI_MODE_CPOL | SPI_MODE_CPHA;
					break;
	}
}
