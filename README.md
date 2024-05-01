# ATmega32 HAL and MCAL Drivers

Welcome to the Atmega32 Hardware Abstraction Layer (HAL) and Microcontroller Abstraction Layer (MCAL) Drivers repository! This repository provides comprehensive hardware abstraction and microcontroller abstraction layers for the Atmega32 microcontroller, along with drivers for various peripherals.

## Overview

The Atmega32 HAL and MCAL Drivers repository aim to simplify development for Atmega32 microcontroller-based projects by providing reusable and modular code for handling hardware interfaces and low-level microcontroller operations. Whether you're a beginner or an experienced embedded systems developer, these layers and drivers can help you save time and effort in your projects.

## Features

- **HAL (Hardware Abstraction Layer)**: Abstracts hardware interfaces such as LCD, KEYPAD, LM35, MOTOR, etc., providing a consistent API for interacting with these peripherals.
- **MCAL (Microcontroller Abstraction Layer)**: Pre-implemented drivers for various peripherals commonly found in Atmega32-based systems, such as UART, SPI, ADC, Timer, etc.
- **Modular and Reusable Code**: Designed for easy integration into projects, with modular code structure facilitating code reuse and scalability.
- **Well-documented**: Extensive documentation and comments are provided throughout the codebase to aid understanding and usage.

## Repository Structure

The repository is structured as follows:

```
atmega32_HAL_MCAL_Drivers/
│
├── HAL/                 # Hardware Abstraction Layer
│   ├── 7 Segment/           
│   ├── BUZZER/          
│   ├── EXTERNAL EEPROM/           
│   ├── KEYPAD/             
│   ├── LCD/          
│   ├── LM35/         
│   ├── MOTOR/           
│   ├── ULTRASONIC_SENSOR/
│   ├── SOIL_SENSOR/
│   ├── WATER_PUMP/          
│
├── MCAL/                # Microcontroller Abstraction Layer
│   ├── ADC/
│   ├── EXTERNAL_INTERRUPT/     
│   ├── GPIO/       
│   ├── ICU/
│   ├── SPI/          
│   ├── TIMER0/         
│   ├── TIMER1/         
│   ├── TWI/         
│   ├── UART/         
└── README.md            # Repository README file
```

Happy coding with Atmega32 HAL and MCAL Drivers!
