/*
 * I2C.c
 *
 *  Created on: Feb 14, 2026
 *      Author: Gohith
 */

#include<I2C.h>

/*****************************************	MACRO	**************************************************/
#define I2C_ENABLE						1U << 0
#define I2C_ENABLE_ANALOG_FILTER		1U << 12
#define I2C_DIGITALFILTER_SHIFT			8U
#define I2C_CLEAR_DIGITAL_FILTER		~(0xF << I2C_DIGITALFILTER_SHIFT)
#define I2C_ENABLE_OWN_ADDRESS_BIT		1U << 15
#define I2C_ENABLE_OWN_ADDRESS_10BIT	1U << 10

#define I2C_10_BIT_ADDRESS_MASK			0x3FFU
#define I2C_7_BIT_MASK_ADDRESS_SHIFT	1U
#define I2C_START						1U << 13
#define	I2C_WRITE_BYTES_MASK			1U << 16
#define I2C_READ_DIRECTION				1U << 10
#define I2C_WRITE_DIRECTION				~(I2C_READ_DIRECTION)
#define I2C_NUMBER_OF_BYTES				1U << 16

#define I2C_TX_REGISTER_EMPTY			1U << 1
#define I2C_RX_REGISTER_EMPTY			1U << 2
/*****************************************	GLOBAL FUNCTION DEFINITION	**************************************/
/**
 * @brief	Function to initialize I2C peripheral
 * @param	I2C_config			I2C configuration pointer
 * @return 	NONE
 */
void I2C_Init(I2C_config_t *I2C_config){
	//Disable I2C peripheral
	I2C_config->instance->CR1 &= ~I2C_ENABLE;

	//Configure Filters, if enabled, else default filters will be used
	if(I2C_config->EnableAnalogFilter_bit){
		I2C_config->instance->CR1 |= I2C_ENABLE_ANALOG_FILTER;
		I2C_config->instance->CR1 &= I2C_CLEAR_DIGITAL_FILTER;
		I2C_config->instance->CR1 |= (I2C_config->ConfigureDigitalFilter << I2C_DIGITALFILTER_SHIFT);
	}

	//Configure Timing
	I2C_config->instance->TIMINGR |= I2C_config->Timing;

	//Configure Own Address
	if(I2C_config->OwnAddress){
		if(I2C_config->AddressSize_10_bit){
			I2C_config->instance->OAR1 |= ( I2C_ENABLE_OWN_ADDRESS_10BIT | I2C_ENABLE_OWN_ADDRESS_BIT| I2C_config->OwnAddress << 1);
		}
		else{
			I2C_config->instance->OAR1 |= ( I2C_ENABLE_OWN_ADDRESS_BIT| I2C_config->OwnAddress << 1);
		}
	}
	//Enable I2C peripheral
	I2C_config->instance->CR1 &= I2C_ENABLE;

	// Wait is necessary for 3 cycles atleast. No operation assembly instructions
	__asm volatile ("nop");
	__asm volatile ("nop");
	__asm volatile ("nop");
}

/**
 * @brief	Function to write a byte to given register at the SLAVE address
 * @param	I2C_config			I2C configuration pointer
 * @param	ui16SlaveAddress	Slave address
 * @param	ui8RegisterAddress	register address
 * @param	ui8databyte			Data of a Byte length
 * @return 	NONE
 */
void I2c_write(I2C_config_t *I2C_config, uint16_t ui16SlaveAddress, uint8_t ui8RegisterAddress, uint8_t ui8databyte){
	if(I2C_config->AddressSize_10_bit)
	{
		I2C_config->instance->CR2 |= ui16SlaveAddress & I2C_10_BIT_ADDRESS_MASK;
	}
	else{
		I2C_config->instance->CR2 |= ((uint8_t)ui16SlaveAddress << I2C_7_BIT_MASK_ADDRESS_SHIFT);
	}
	I2C_config->instance->CR2 |= I2C_WRITE_BYTES_MASK;
	I2C_config->instance->CR2 |= I2C_WRITE_DIRECTION;
	I2C_config->instance->CR2 |= I2C_NUMBER_OF_BYTES;
	I2C_config->instance->CR2 |= I2C_START;

	while(!(I2C_config->instance->ISR & I2C_TX_REGISTER_EMPTY)){
		// wait
	}
	// TX data register
	I2C_config->instance->TXDR |= ui8databyte;
}

/**
 * @brief	Function to read a byte from the given register at the SLAVE address
 * @param	I2C_config			I2C configuration pointer
 * @param	ui16SlaveAddress	Slave address
 * @param	ui8RegisterAddress	register address
 * @return 	NONE
 */
uint8_t I2C_read(I2C_config_t *I2C_config, uint16_t ui16SlaveAddress, uint8_t ui8RegisterAddress){
	if(I2C_config->AddressSize_10_bit)
	{
		I2C_config->instance->CR2 |= ui16SlaveAddress & I2C_10_BIT_ADDRESS_MASK;
	}
	else{
		I2C_config->instance->CR2 |= ((uint8_t)ui16SlaveAddress << I2C_7_BIT_MASK_ADDRESS_SHIFT);
	}
	I2C_config->instance->CR2 |= I2C_READ_DIRECTION;
	I2C_config->instance->CR2 |= I2C_NUMBER_OF_BYTES;
	I2C_config->instance->CR2 |= I2C_START;

	while(!(I2C_config->instance->ISR & I2C_RX_REGISTER_EMPTY)){
		// wait
	}
	// RX data register
	return I2C_config->instance->RXDR;
}
