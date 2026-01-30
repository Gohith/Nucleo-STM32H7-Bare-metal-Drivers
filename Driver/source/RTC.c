/*
 * RTC.c
 *
 *  Created on: Jan 30, 2026
 *      Author: Gohith
 */


#include<RTC.h>
#include<PWR.h>
#include<RCC.h>
#include<stdlib.h>

/***********************	MACRO	******************************/

#define	PWR_CR1_DBP				(1U << 8)
#define RCC_BDCR_LSE_ON			(1U<< 0)
#define RCC_BDCR_LSE_BYPASS_ON	(1U << 2)
#define RCC_BDCR_LSE_BYPASS_OFF	~(1U << 2)
#define RCC_BDCR_LSE_READY		(1U << 1)
#define RCC_BDCR_RTCSEL			(3U << 9)
#define RCC_RTCSEL_LSE			(1U << 9)
#define RCC_BDCR_RTCEN			(1U << 16)

#define RTC_TR_ST	4U
#define RTC_TR_SU	0U
#define RTC_TR_MNT	12U
#define RTC_TR_MNU	8U
#define RTC_TR_HT	20U
#define RTC_TR_HU	16U

#define RTC_TR_HT_POS	(0x3U << RTC_TR_HT)
#define RTC_TR_HU_POS	(0xFU << RTC_TR_HU)
#define RTC_TR_MT_POS	(0x7U << RTC_TR_MNT)
#define RTC_TR_MU_POS	(0xFU << RTC_TR_MNU)
#define RTC_TR_ST_POS	(0x7U << RTC_TR_ST)
#define RTC_TR_SU_POS	(0xFU << RTC_TR_SU)

#define RTC_DR_YT	20U
#define RTC_DR_YU	16U
#define RTC_DR_MT	12U
#define RTC_DR_MU	8U
#define RTC_DR_DT	4U
#define RTC_DR_DU	0U

#define RTC_DR_YT_POS	(0xFU << RTC_DR_YT)
#define RTC_DR_YU_POS	(0xFUL << RTC_DR_YU)
#define RTC_DR_MT_POS	(0x1UL << RTC_DR_MT)
#define RTC_DR_MU_POS	(0xFUL << RTC_DR_MU)
#define RTC_DR_DT_POS	(0x3UL << RTC_DR_DT)
#define RTC_DR_DU_POS	(0xFUL << RTC_DR_DU)

#define RTC_DR_WDU	13U
#define RTC_DR_WDU_POS	(0x7UL << RTC_DR_WDU)

#define RTC_ISR_INIT	(1U << 7)
#define RTC_ISR_INITF	(1	<< 6)

/***********************	USER FUNCTION PROTOTYPE	***********************/

void RTC_Init_Mode(void);
void RTC_DeInit_Mode(void);
/***********************	GLOBAL FUNCTION DEFINITIONS	**********************/

/**
 * @brief	Function to set the RTC clock
 * @param	NONE
 * @return 	NONE
 */
void RTC_Init_LSE(void){
	//Enable Backup Domain,
	PWR->CR1 |= PWR_CR1_DBP;

	while((PWR->CR1 & PWR_CR1_DBP) == 0U){
		// wait to set the bit
	}
	//Disable LSE Bypass
	RCC->BDCR &= RCC_BDCR_LSE_BYPASS_OFF;
	// Enable LSE
	RCC->BDCR |= RCC_BDCR_LSE_ON;

	while((RCC->BDCR  & RCC_BDCR_LSE_READY) == 0U){
		// wait till LSE is ready
	}
	// Select the LSE clock
	RCC->BDCR &= ~RCC_BDCR_RTCSEL;
	RCC->BDCR |= RCC_RTCSEL_LSE;
	// Enable RTC clock
	RCC->BDCR |= RCC_BDCR_RTCEN;
}

/**
 * @brief	Function to set the time of RTC
 * @param	time	struct variable of type RTC_time_t
 * @return 	NONE
 */
void RTC_Set_Time(const RTC_time_t* time){
	if(time == NULL){
		return;
	}

	RTC_Init_Mode();
	uint8_t ui8HoursTens = time->hours/10U;
	uint8_t ui8HoursUnits = time->hours%10U;

	uint8_t ui8MinTens = time->minutes/10U;
	uint8_t ui8MinUnits = time->minutes%10U;

	uint8_t ui8SecondsTens = time->seconds/10U;
	uint8_t ui8SecondsUnits = time->seconds%10U;
	uint32_t ui32time = 0U;
	ui32time |= ((uint32_t)ui8HoursTens << RTC_TR_HT);
	ui32time |= ((uint32_t)ui8HoursUnits << RTC_TR_HU);
	ui32time |= ((uint32_t)ui8MinTens << RTC_TR_MNT);
	ui32time |= ((uint32_t)ui8MinUnits << RTC_TR_MNU);
	ui32time |= ((uint32_t)ui8SecondsTens << RTC_TR_ST);
	ui32time |= ((uint32_t)ui8SecondsUnits << RTC_TR_SU);

	RTC->TR |= ui32time;
	RTC_DeInit_Mode();
}

/**
 * @brief	Function to get the time of RTC
 * @param	date	struct variable of type RTC_time_t
 * @return 	NONE
 */
void RTC_Get_Time(RTC_time_t* time){
	if(time == NULL){
		return;
	}
	uint32_t ui32time = RTC->TR;
	uint8_t ui8hoursTens = (uint8_t)((ui32time & RTC_TR_HT) >> RTC_TR_HT);
	uint8_t ui8hoursUnits = (uint8_t)((ui32time & RTC_TR_HU) >> RTC_TR_HU);
	uint8_t ui8MinTens = (uint8_t)((ui32time & RTC_TR_MNT) >> RTC_TR_MNT);
	uint8_t ui8MinUnits = (uint8_t)((ui32time & RTC_TR_MNU) >> RTC_TR_MNU);
	uint8_t ui8SecondsTens = (uint8_t)((ui32time & RTC_TR_ST) >> RTC_TR_ST);
	uint8_t ui8SecondsUnits = (uint8_t)((ui32time & RTC_TR_SU) >> RTC_TR_SU);

	time->hours = (uint8_t)(ui8hoursTens * 10U + ui8hoursUnits);
	time->minutes = (uint8_t)(ui8MinTens * 10U + ui8MinUnits);
	time->seconds = (uint8_t)(ui8SecondsTens * 10U + ui8SecondsUnits);
}

/**
 * @brief	Function to set the date of RTC
 * @param	date	struct variable of type RTC_date_t
 * @return 	NONE
 */
void RTC_Set_Date(const RTC_date_t* date){
	if(date == NULL){
		return;
	}
	RTC_Init_Mode();


	uint8_t ui8YearTens = date->year / 10U;
	uint8_t ui8YearUnits = date->year % 10U;
	uint8_t ui8MonthTens = date->month / 10U;
	uint8_t ui8MonthUnits = date->month % 10U;
	uint8_t ui8DayTens = date->day / 10U;
	uint8_t ui8DayUnits = date->day % 10U;

	uint32_t ui32Date = 0U;
	ui32Date |= ((uint32_t)ui8YearTens << RTC_DR_YT);
	ui32Date |= ((uint32_t)ui8YearUnits << RTC_DR_YU);
	ui32Date |= ((uint32_t)ui8MonthTens << RTC_DR_MT);
	ui32Date |= ((uint32_t)ui8MonthUnits << RTC_DR_MU);
	ui32Date |= ((uint32_t)ui8DayTens << RTC_DR_DT);
	ui32Date |= ((uint32_t)ui8DayUnits << RTC_DR_DU);
	ui32Date |= ((uint32_t)(date->weekday & 0x07U) << RTC_DR_WDU);

	RTC->DR = ui32Date;
	RTC_DeInit_Mode();
}

/**
 * @brief	Function to get the date
 * @param	date	struct variable of type RTC_date_t
 * @return 	NONE
 */
void RTC_Get_Date(RTC_date_t* date){
	if (date == NULL){
		return;
	}

	uint32_t ui32Date = RTC->DR;
	uint8_t ui8YearTens = (uint8_t)((ui32Date & RTC_DR_YT_POS) >> RTC_DR_YT);
	uint8_t ui8YearUnits = (uint8_t)((ui32Date) & RTC_DR_YU_POS>> RTC_DR_YU);
	uint8_t ui8MonthTens = (uint8_t)((ui32Date & RTC_DR_MT_POS) >> RTC_DR_MT);
	uint8_t ui8MonthUnits = (uint8_t)((ui32Date & RTC_DR_MU_POS) >> RTC_DR_MU);
	uint8_t ui8DayTens = (uint8_t)((ui32Date & RTC_DR_DT_POS) >> RTC_DR_DT);
	uint8_t ui8DayUnits = (uint8_t)((ui32Date & RTC_DR_DU_POS) >> RTC_DR_DU);

	date->year = (uint8_t)(ui8YearTens * 10U + ui8YearUnits);
	date->month = (uint8_t)(ui8MonthTens * 10U + ui8MonthUnits);
	date->day = (uint8_t)(ui8DayTens * 10U + ui8DayUnits);
	date->weekday = (uint8_t)((ui32Date & RTC_DR_WDU_POS) >> RTC_DR_WDU);
}

/*****************************	USER FUNCTION DEFINITIONS	*********************/

/**
 * @brief	Function to initialize the RTC
 * @param	NONE
 * @return 	NONE
 */
void RTC_Init_Mode(void){
	// RTC write protection key
	RTC->WPR = 0xCA;
	RTC->WPR = 0x53;

	RTC->ISR |= RTC_ISR_INIT;
	while(!(RTC->ISR & RTC_ISR_INITF)){
		//wait for the INIT flag
	}
}

/**
 * @brief	Function to deinitialize the RTC
 * @param	NONE
 * @return 	NONE
 */
void RTC_DeInit_Mode(void){
	RTC->ISR &= ~RTC_ISR_INIT;

	// RTC lock write protection
	RTC->WPR = 0xFFU;
}
