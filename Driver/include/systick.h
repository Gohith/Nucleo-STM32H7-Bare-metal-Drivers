/*
 * systick.h
 *
 *  Created on: Jan 7, 2026
 *      Author: Gohith
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

/********************** INCLUDE *************************/
#include <stdint.h>

/********************** REGISTERS ************************/
typedef struct{
	volatile uint32_t CSR;		//!> Control Register
	volatile uint32_t RVR;		//!> Reload Value Register
	volatile uint32_t CVR;		//!> Current value Register
	volatile uint32_t CALIB;	//!> Calibration Register
}systick_register_t;

/************************* GLOBAL FUNCTIONS *********************/
void systick_delay(uint32_t);

#endif 	/* SYSTICK.H*/


