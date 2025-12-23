/**
 ******************************************************************************
 * BASIC LED functionality testing on NUCLEO-STM32H7 dual core development board.
 * User LD1: a green user LED is connected to the STM32H7 I/O PB0 (SB65 OFF and SB54 ON) or PA5 (SB65 ON and SB54 OFF) corresponding to the ST Zio D13.
 * User LD2: a yellow user LED is connected to PE1.
 * User LD3: a red user LED is connected to PB14.
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/**
 * MACRO
 */

#define RCC_BASE	(0x58024400UL)
#define GPIOB_BASE	(0x58020400UL)
#define GPIOE_BASE 	(0x58021000UL)

#define GPIOX_MODER	(0x00UL)
#define GPIOX_OPR	(0x14UL)
#define RCC_AHB4EN	(0x0E0UL)

#define GPIOX_RCC_AHB4EN	(*(volatile unsigned int *)(RCC_BASE + RCC_AHB4EN))
#define GPIOB_MODER			(*(volatile unsigned int *)(GPIOB_BASE + GPIOX_MODER))
#define GPIOE_MODER			(*(volatile unsigned int *)(GPIOE_BASE + GPIOX_MODER))
#define GPIOB_OUTPUT_DATA	(*(volatile unsigned int *)(GPIOB_BASE + GPIOX_OPR))
#define GPIOE_OUTPUT_DATA	(*(volatile unsigned int *)(GPIOE_BASE + GPIOX_OPR))

/**
 * User functions
 */
void clock_gating_GPIO(void);
void vLD1_GPIOB_config(void);
void vLD2_GPIOE_config(void);
void vLD3_GPIOB_config(void);
void vPerform_LD_pattern_on(uint8_t ui8LD_pattern);
void vPeform_LD_pattern_off(void);
void vdelay(int);

int main(void)
{
	uint8_t ui8LD_pattern = 1U;
	clock_gating_GPIO();
	vLD1_GPIOB_config();
	vLD2_GPIOE_config();
	vLD3_GPIOB_config();
	while(1)
	{
		do
		{
			vPerform_LD_pattern_on(ui8LD_pattern);
			ui8LD_pattern++;
		}while(ui8LD_pattern < 4U);
		vdelay(5U);
		vPeform_LD_pattern_off();
		ui8LD_pattern = 1U;
	}
}

/**
 * @brief function to activate the clock to bus and specific GPIO port
 * @parameters NONE
 * @return NONE
 */
void clock_gating_GPIO(void)
{
	GPIOX_RCC_AHB4EN |= (1U << 1);	//GPIOB
	GPIOX_RCC_AHB4EN |= (1U << 4);	//GPIOE
}

/**
 * @brief function to configure the GPIO port B to simple output on pin PB0
 * @parameters NONE
 * @return NONE
 */
void vLD1_GPIOB_config(void)
{
	GPIOB_MODER &= ~(3U << 0);
	GPIOB_MODER |= (1U << 0);	//PB0
}

/**
 * @brief function to configure the GPIO port E to simple output on pin PE1
 * @parameters NONE
 * @return NONE
 */
void vLD2_GPIOE_config(void)
{
	GPIOE_MODER &= ~(3U << 2);
	GPIOE_MODER |= (1U << 2);	//PE1
}

/**
 * @brief function to configure the GPIO port B to simple output on pin PB14
 * @parameters NONE
 * @return NONE
 */
void vLD3_GPIOB_config(void)
{
	GPIOB_MODER &= ~(3U << 28);
	GPIOB_MODER |= (1U << 28);	//PB14
}

/**
 * @brief function to activate the LED in series
 * @parameters NONE
 * @return NONE
 */
void vPerform_LD_pattern_on(uint8_t ui8LD_pattern)
{
	switch(ui8LD_pattern)
	{
	case 1:	GPIOB_OUTPUT_DATA |= (1U << 0);
			break;
	case 2:	GPIOE_OUTPUT_DATA |= (1U << 1);
			break;
	case 3:	GPIOB_OUTPUT_DATA |= (1U << 14);
			break;
	}
}

/**
 * @brief function to deactivate the LED
 * @parameters NONE
 * @return NONE
 */
void vPeform_LD_pattern_off(void)
{
	GPIOB_OUTPUT_DATA &= ~(3U << 0);
	GPIOE_OUTPUT_DATA &= ~(3U << 2);
	GPIOB_OUTPUT_DATA &= ~(3U << 14);
}

/**
 * @brief function to perform delay functionality
 * @parameters NONE
 * @return NONE
 */
void vdelay(int delay)
{
	for(int i = 0; i < delay * 1000000; i++)
	{
		;	// do nothing
	}
}

