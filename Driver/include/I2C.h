/*
 * I2C.h
 *
 *  Created on: Feb 14, 2026
 *      Author: Gohith
 */

#ifndef I2C_H_
#define I2C_H_

#include<stdint.h>

/*********************************	I2C REGISTER	*************************************/

typedef struct{
	volatile uint32_t CR1;			//0x00, Control Register 1
	volatile uint32_t CR2;			//0x04, Control Register 2
	volatile uint32_t OAR1;			//0x08, Own Address Register 1
	volatile uint32_t OAR2;			//0x0C, Own Address Register 2
	volatile uint32_t TIMINGR;		//0x10, Timing Register
	volatile uint32_t TIMEOUTR;		//0x14, Timeout Register
	volatile uint32_t ISR;			//0x18, Interrupt and Status Register
	volatile uint32_t ICR;			//0x1C, Interrupt Clear Register
	volatile uint32_t PECR;			//0x20, PEC Register
	volatile uint32_t RXDR;			//0x24, Receive Data Register
	volatile uint32_t TXDR;			//0x28, Transmit Data Register
}I2C_reg_t;

/*********************************	STRUCT AND ENUM	*************************************/

typedef struct{
	I2C_reg_t *instance;
	uint8_t AddressSize_10_bit:1;
	uint8_t OwnAddress;
	uint8_t EnableAnalogFilter_bit:1;
	uint8_t ConfigureDigitalFilter;
	uint32_t Timing;
}I2C_config_t;

/**********************************	I2C BASE ADDRESS	*********************************/

#define I2C1	((volatile I2C_reg_t*)0x40005400U)
#define I2C2	((volatile I2C_reg_t*)0x40005800U)
#define I2C3	((volatile I2C_reg_t*)0x40005C00U)
#define I2C4	((volatile I2C_reg_t*)0x58001C00U)

/*********************************	GLOBAL FUNCTIONS	*********************************/

void I2C_Init(I2C_config_t*);
void I2C_write(I2C_config_t*, uint16_t, uint8_t, uint8_t);
uint8_t I2C_read(I2C_config_t*, uint16_t, uint8_t);


#endif /* I2C_H_ */
