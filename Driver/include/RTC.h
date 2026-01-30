/*
 * RTC.h
 *
 *  Created on: Jan 30, 2026
 *      Author: Gohith
 */

#ifndef RTC_H_
#define RTC_H_

#include<stdint.h>

/******************************	RTC REGISTERS	*************************/

typedef struct{
	uint32_t volatile TR;			//0x00, TIME REGISTER
	uint32_t volatile DR;			//0x04,	DATE REGISTER
	uint32_t volatile CR;			//0x08, CONTROL REGISTER
	uint32_t volatile ISR;			//0x0C, STATUS TRGISTER
	uint32_t volatile PRER;			//0x10, PRESCALE REGISTER
	uint32_t volatile WUTR;			//0x14, WAKE-UP TIME REGISTER
	uint32_t volatile ALRMAR;		//0x1C, ALARM A REGISTER
	uint32_t volatile ALRMBR;		//0x20, ALARM B REGISTER
	uint32_t volatile WPR;			//0x24, WRITE PROTECTION REGISTER
	uint32_t volatile SSR;			//0x28, SUB SECOND REGISTER
	uint32_t volatile SHIFTR;		//0x2C, SHIFT CONTROL REGISTER
	uint32_t volatile TSTR;			//0x30, TIMESTAMP-TIME REGISTER
	uint32_t volatile TSDR;			//0x34, TIMESTAMP-DATE REGISTER
	uint32_t volatile TSSSR;		//0x38, TIMESTAMP-SUB SECOND REGISTER
	uint32_t volatile CALR;			//0x3C, CALIBRATION REGISTER
	uint32_t volatile TAMPCR;		//0x40, TAMPER CONFIGURATION REGISTER
	uint32_t volatile ALRMASSR;		//0x44, ALARM A SUB SECOND REGISTER
	uint32_t volatile ALRMBSSR;		//0x48, ALARM B SUB SECOND REGISTER
	uint32_t volatile OR;			//0x4C, OPTION REGISTER
	uint32_t volatile BKPxR[32];	//0x50 - 0xCC, BACKUP REGISTERS
}RTC_reg_t;

/****************************** DATE AND TIME STRUCT	***********************/

typedef struct{
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint8_t weekday;
}RTC_date_t;

typedef struct{
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
}RTC_time_t;

/*****************************	RTC BASE ADDRESS	********************************/

#define RTC	((volatile RTC_reg_t*)0x58004000U)

/*****************************	GLOBAL FUNCTIONS	*****************************/

void RTC_Init_LSE(void);
void RTC_Set_Time(const RTC_time_t*);
void RTC_Get_Time(RTC_time_t*);
void RTC_Set_Date(const RTC_date_t*);
void RTC_Get_Date(RTC_date_t*);


#endif /* RTC_H_ */
