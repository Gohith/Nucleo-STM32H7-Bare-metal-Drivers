/**
 *  This file shows how to use the USART/UART peripheral driver library
 *  to send a string on Nucleo-board for every 1000 ms. 
 *  
 *  On STM32H7 Nucleo boards, USART3 at PD8 is default is linked with micro-USB port.
 */

#include<GPIO.h>
#include<RCC.h>
#include<systick.h>
#include<USART.h>

GPIO_Config_t GPIOx_USART = {
    .PORT = GPIOD,
    .PIN = 8U,
    .SPEED = VERY_HIGH_SPEED,
    .ALT_FUNCTION = 7U,
    .OTYPER = PUSH_PULL
};

usart_config_t usart3_handle={
	.TX_enable = 1,
    .RX_enable = 0,
	.instance = USART3,
	.baudrate = (uint32_t)(64000000 / 115200),          // System clock divide by baudrate 
	.stop_bits = 0,
	.parity_control= 0,
	.parity_selection= 0,
};

const uint8_t data[] = "Hello from STM32H7 !! \r\n";
uint8_t length = sizeof(data) - 1;

int main(){
    // Enable the GPIOD clock
    RCC_Enable_GPIOx(RCC_GPIOD); 
    // Init the GPIOD as Alternate Functionality
    GPIO_init(&GPIOx_USART, ALTERNATE_FUNCTION);
    // Init the USART
	USART_init(&usart3_handle);
       
    while(1){
        // Write to USART buffer and send
        USART_Write_Block(&usart3_handle, data, length);
        // Delay of 1000 ms
        systick_delay(1000);
    }
    return 0;
}