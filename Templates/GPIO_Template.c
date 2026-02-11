/**
 *  This file shows how to use the GPIO peripheral driver library
 *  to blink a LED at PB0 PORT B, PIN 0 on Nucleo-board for every 1000 ms
 */

#include<GPIO.h>
#include<RCC.h>
#include<systick.h>

GPIO_Config_t GPIOx = {
    .PORT = GPIOB,
    .PIN = 0U,
    .SPEED = LOW_SPEED,
    .PULL_UP_DOWN = NO_PULLUP_PULLDOWN,
    .OTYPER = PUSH_PULL
};

int main(){
        // Enable the clock to GPIOB
    	RCC_Enable_GPIOx(RCC_GPIOB); 
        // Init the GPIOB with handler as output mode               
        GPIO_init(&GPIOx, OUTPUT_MODE);
        while(1){
            // PB0 HIGH
            GPIO_Set_Output_High(GPIOx.PORT, GPIOx.PIN);
            // Delay of 1000 ms
            systick_delay(1000);
            // PB0 LOW
            GPIO_Set_Output_Low(GPIOx.PORT, GPIOx.PIN);
        }
        return 0;
}