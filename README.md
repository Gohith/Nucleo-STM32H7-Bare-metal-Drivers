# STM32H755ZI Bare‑Metal Drivers

A lightweight collection of **bare‑metal, register‑level drivers** for STM32H7 Nucleo boards or MCU using STM32H755ZIT6.  
This project avoids HAL/LL entirely and focuses on clarity, performance, and learning the hardware at its lowest level.
The drivers can be included in the project application.

> **Project Status:** Work in progress — currently includes ADC, GPIO, PWR, RCC, RTC, SYSTICK, TIM, USART, IWDG, NVIC , SPI drivers.  
> More peripheral drivers will be added as development continues.

---

## Overview

This repository contains minimal, clean, and well‑structured drivers written using fully bare-metal and direct register access.  
The goal is to build a complete set of reusable STM32H7 drivers while keeping the code transparent and easy to understand.

---

## Implemented Drivers

### **GPIO**
- Configure pins as input, output, alternate function, or analog  
- Push‑pull / open‑drain modes 
- Pull‑up / pull‑down configuration  
- Read/Write operations  

### **SysTick**
- System tick timer initialization  
- Millisecond delay functionality  
- Core clock‑based timing  
- Useful for simple scheduling and delay (When using RTOS, use delay logic from TIM. Since the default RTOS is heavily depend on ticks from cortex-M default counter)

### **TIM**
- Complete TIM available in STM32H7
- TIM2 is used for delay (fixed to ms)

### **RCC**
- Enabling/Disabling the CLK for GPIO, TIM, USART/UART, 

### **USART/UART**
- Configuration of USART/UART
- USART Write/Block write

### **ADC**
-  ADC init/Configure/Start/Read
-  Multiple channel ADC configuration (16 channels can be configured)

### **RTC**
- Set/Get RTC time and date
> **RTC Alarm is for future scope**

### **IWDG**
- Independent Watch Dog Tiner Init/Refresh
- on latest STM32H7 models CSI(Clock Security Internal) is used instead of LSI. Though manual need to be synced.
> **CSI is used instead of LSI on STM32H755ZI model. Using IWDG cannot be terminated like WWDG(windowed watchdog) since it uses independent clock source, user should be cautious. Use IWDG for Production, WWDG for Design and Development**

### **NVIC**
- Set/Clear/Read Internal Interrupts
> **Interrupts priority is for future scope**

### **SPI**
- INIT/Tx/Rx SPI peripheral
> - **GPIO peripherals should be configured before initializing SPI |** 
> - **SPI(1, 2, 3) can also be used for I2S(1, 2, 3) left for future scope.**
  
---

## Project Structure
```
Drivers/
│
├── src/
│   ├── GPIO.c
│   ├── systick.c
│   ├── RCC.c
|   ├── USART.c
|   ├── TIM.c
|   ├── ADC.c
|   ├── PWR.c
|   ├── RTC.c
|   ├── IWDG.c
|   ├── NVIC.c
|   ├── SPI.c
│
├── inc/
│   ├── GPIO.h
│   ├── systick.h
│   ├── RCC.h
|   ├── USART.h
|   ├── TIM.h
|   ├── ADC.h
|   ├── PWR.h
|   ├── RTC.h
|   ├── IWDG.h
|   ├── NVIC.h
|   ├── SPI.h
|
└── README.md
```

---

## Development Setup

- **Board:** Nucleo‑H755ZI-Q (or similar STM32H7 Nucleo boards)  
- **Toolchain:** STM32CubeIDE / arm‑none‑eabi‑gcc  
- **Dependencies:** MCU startup file, linker files 
- **Debugger:** ST‑Link   

---

## Work in Progress

Planned upcoming drivers: 
- I2C
- CAN/CANFD
- DMA    
- Extended Interrupts (EXTI)
- Dual‑core CM7/CM4   

Development will continue as new modules are implemented and tested.

---

## Contributions

Contributions, suggestions, and improvements are welcome.  
Feel free to open issues or submit pull requests.


