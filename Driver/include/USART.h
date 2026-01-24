/*
 * USART.h
 *
 *  Created on: Jan 18, 2026
 *      Author: Gohith
 */

#ifndef USART_H_
#define USART_H_

#include<stdint.h>
#include<stdbool.h>
#include<GPIO.h>

typedef struct{
	volatile uint32_t CR1;		//!> 0x00, control register 1
	volatile uint32_t CR2;		//!> 0x04, control register 2
	volatile uint32_t CR3;		//!> 0x08, control register 3
	volatile uint32_t BRR;		//!> 0x0C, baudrate register
	volatile uint32_t GTPR;		//!> 0x10, guard time and prescaler register
	volatile uint32_t RTOR;		//!> 0x14, receiver timeout register
	volatile uint32_t RQR;		//!> 0x18, request register
	volatile uint32_t ISR;		//!> 0x1C, interrupt and status register
	volatile uint32_t ICR;		//!> 0x20, interrupt flag clear register
	volatile uint32_t RDR;		//!> 0x24, receive data register
	volatile uint32_t TDR;		//!> 0x28, transmit data register
	volatile uint32_t PRESC;	//!> 0x2C, prescaler register
}usart_reg_t;

typedef struct{
	usart_reg_t	*instance;		//!> USART/UART  peripheral
	uint8_t Word_Length:2;		//!> Data length
	uint32_t baudrate;			//!> Baudrate
	uint8_t stop_bits:2;		//!> Number of stop bits
	uint8_t TX_enable:1;		//!> Transmission Flag
	uint8_t RX_enable:1;		//!> Receive Flag
	uint8_t parity_control:1;	//!> parity enable/disable
	uint8_t parity_selection:1;	//!> ODD or EVEN parity
}usart_config_t;

typedef enum{
	ONE_STOP,
	HALF_STOP,
	TWO_STOP,
	ONE_HALF_STOP
}eUSARTx_Stop_t;

typedef enum{
	PARITY_DISABLE,
	PARITY_ENABLE,
	EVEN_PARITY = 0,
	ODD_PARITY
}eUSARTx_Parity_t;
/******************* MACROS	******************/

#define USART1	((usart_reg_t*)0x40011000U)
#define USART2	((usart_reg_t*)0x40004400U)
#define USART3	((usart_reg_t*)0x40004800U)		// Default COM for ST Nucleo board
#define USART6	((usart_reg_t*)0x40011400U)
#define UART4	((usart_reg_t*)0x40004C00U)
#define UART5	((usart_reg_t*)0x40005000U)
#define UART7	((usart_reg_t*)0x40007800U)
#define UART8	((usart_reg_t*)0x40007C00U)

/*****************	GLOBAL FUNCTIONS	***************/

void USART_init(usart_config_t*);
void USART_Write_Block(usart_config_t*, const uint8_t*, uint8_t);
void USART_Write(usart_config_t*, uint8_t);

#endif /* USART_H_ */
