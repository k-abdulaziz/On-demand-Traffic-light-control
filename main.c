/**
    @file       main.c
    @brief      Main file of the project
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022

    @mainpage   On-demand Traffic light control
    @author     Khaled Abdulaziz
    \section    Section1 1.Introduction
                This document is intended to provide information about on-demand traffic light
                control system including its description, design, state machine and constraints.
    
    \section    Section2 2.System Description
                This system aims to provide traffic organization for both cars and pedestrians and
                the normal mode of the system is for cars unless a pedestrian push the button.
                
                It consists of:
                1. Traffic light for cars
                2. Traffic light for pedestrians
                3. Push button for pedestrians
                
                ![Traffic_Light](https://i.imgur.com/HNDNqk4.jpg)
                
                It works in two main modes:
                
                Normal Mode:
                1. Cars' LEDs will be changed every five seconds starting from Green then yellow
                then red then yellow then Green.
                2. The Yellow LED will blink for five seconds before moving to Green or Red
                LEDs.
                
                Pedestrian Mode:
                1. Change from normal mode to pedestrian mode when the pedestrian button
                is pressed.
                2. If pressed when the cars' Red LED is on, the pedestrian's Green LED and the
                cars' Red LEDs will be on for five seconds, this means that pedestrians can
                cross the street while the pedestrian's Green LED is on.
                3. If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking,
                the pedestrian Red LED will be on then both Yellow LEDs start to blink for five
                seconds, then the cars' Red LED and pedestrian Green LEDs are on for five
                seconds, this means that pedestrian must wait until the Green LED is on.
                4. At the end of the two states, the cars' Red LED will be off and both Yellow
                LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
                5. After the five seconds the pedestrian Green LED will be off and both the
                pedestrian Red LED and the cars' Green LED will be on.
                6. Traffic lights signals are going to the normal mode again.
                
    \section    Section3 3.System Design
    \subsection sub1 3.1 Hardware Requirements:
                1. AVR Atmega32 Microcontroller
                2. 2 green leds
                3. 2 yellow leds
                4. 2 red leds
                5. 6 resistors of 300 ohms
                6. 1 resistor of 10k ohms
                7. 1 bush button
                
    \subsection sub2 3.2 System Schematic Circuit: 
                As shown beyond:
                -Push button is connected to INT0 pin for pedestrian
                -LEDs for cars - Green, Yellow, and Red, connected on port A, pins 0, 1, and 2
                -LEDs for pedestrians - Green, Yellow, and Red, connected on port B, pins 0, 1, and 2
                
                ![Schematic](https://i.imgur.com/qbm1jSb.png)
                
    \subsection sub3 3.3 Static architecture:
                The system is divided in 4 main layers:
                1. Microcontroller (MCU) Layer
                2. Microcontroller Abstraction Layer (MCAL)
                3. Electronic Unit Abstraction Layer (ECUAL)
                4. Application Layer
                
                The system is divided into 5 drivers:
                1. DIO driver
                2. External interrupt driver
                3. Timer driver
                4. LED driver
                5. Button driver
          
                ![Layers1](https://i.imgur.com/2WB8oRm.png)
                ![Layers2](https://i.imgur.com/oKfNoOw.png)
                
    \section Section4 4.System State Machine
                ![stm](https://i.imgur.com/Sh68bSO.png)
                
    \section Section5 5.System Constraints
                No system constraints were set.

*/

#include "Application/application.h"

int main(void)
{
	APP_init();
	APP_start();
}