/*
 * SPI.h
 *
 *  Created on: Feb 11, 2026
 *      Author: Gohith
 */

#ifndef SPI_H_
#define SPI_H_

/****************************** HEADERS	**********************************************/
#include<stdint.h>
#include<stddef.h>

/********************************	SPI REGISTERS	***********************************/

typedef struct{
	volatile uint32_t	CR1;			//0x00, Control Register 1
	volatile uint32_t	CR2;			//0x04, Control Register 2
	volatile uint32_t	CFG1;			//0x08, Configuration Register 1
	volatile uint32_t	CFG2;			//0x0C, Configuration Register 2
	volatile uint32_t	IER;			//0x10, Interrupt Enable Register
	volatile uint32_t	SR;				//0x14, Status Register
	volatile uint32_t	IFCR;			//0x18, Interrupt/Status Clear Flag Register
	volatile uint32_t	RESERVED1;		//0x1C, RESERVED
	volatile uint32_t	TXDR;			//0x20, Transmit Data Register
	volatile uint32_t	RESERVED2[3];	//0x24, RESERVED
	volatile uint32_t	RXDR;			//0x30, Receive Data Register
	volatile uint32_t	RESERVED3[3];	//0x34, RESERVED
	volatile uint32_t	CRCPOLY;		//0x40, Polynomial Register
	volatile uint32_t	TXCRC;			//0x44, Transmitter CRC Register
	volatile uint32_t	RXCRC;			//0x48, Receiver CRC Register
	volatile uint32_t	UDRDR;			//0x4C, Underrun Data Register
	volatile uint32_t	SPI_I2SCFGR;	//0x50, SPI/I2S Configuration Register
}SPI_reg_t;

/********************************	SPI BASE ADDRESS	******************************/

#define SPI1	((volatile SPI_reg_t*)0x40013000U)	// I2S1
#define SPI2	((volatile SPI_reg_t*)0x40003800U)	// I2S2
#define SPI3	((volatile SPI_reg_t*)0x40003C00U)	// I2S3
#define SPI4	((volatile SPI_reg_t*)0x40013400U)
#define SPI5	((volatile SPI_reg_t*)0x40015000U)
#define SPI6	((volatile SPI_reg_t*)0x58001400U)

/*******************************	STRUCT AND ENUM		******************************/
typedef enum{
	MODE_0 = 0,	// CPOL = 0, CPHA = 0
	MODE_1,		// CPOL = 0, CPHA = 1
	MODE_2,		// CPOL = 1, CPHA = 0
	MODE_3		// CPOL = 1, CPHA = 1
}SPI_mode_t;

typedef enum{
	MSB_FIRST = 0,
	LSB_FIRST
}SPI_bit_order_t;

typedef struct{
	SPI_reg_t* instance;
	uint8_t Master_or_Slave:1;
	SPI_mode_t mode;
	SPI_bit_order_t bit_oder;
	uint8_t data_size;
	uint8_t baud_prescaler:3;
}SPI_config_t;

/*******************************	GLOBAL FUNCTIONS	******************************/

void SPI_Init(SPI_config_t*);
void SPI_Enable(SPI_reg_t*);
void SPI_Disable(SPI_reg_t*);
void SPI_Transfer(SPI_reg_t*, uint32_t*, uint32_t*, size_t);

#endif /* SPI_H_ */
