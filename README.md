# On-demand-Traffic-light-control
This ATmega32-based system aims to provide traffic organization for both cars and pedestrians and the normal mode of the system is for cars unless a pedestrian push the button.

# System Description
This system aims to provide traffic organization for both cars and pedestrians and
the normal mode of the system is for cars unless a pedestrian push the button.

It consists of:
- Traffic light for cars
- Traffic light for pedestrians
- Push button for pedestrians

![Traffic](https://i.imgur.com/HNDNqk4.jpg)

It works in two main modes:
                
Normal Mode:
- Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
- The Yellow LED will blink for five seconds before moving to Green or Red
LEDs.
                
Pedestrian Mode:
- Change from normal mode to pedestrian mode when the pedestrian buttonis pressed.
- If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
- If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
- At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
- After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
- Traffic lights signals are going to the normal mode again.

# System Design
Hardware Requirements:
- AVR Atmega32 Microcontroller
- 2 green leds
- 2 yellow leds
- 2 red leds
- 6 resistors of 300 ohms
- 1 resistor of 10k ohms
- 1 bush button
                
System Schematic Circuit: 
As shown beyond:
- Push button is connected to INT0 pin for pedestrian
- LEDs for cars - Green, Yellow, and Red, connected on port A, pins 0, 1, and 2
- LEDs for pedestrians - Green, Yellow, and Red, connected on port B, pins 0, 1, and 2
                
![Schematic](https://i.imgur.com/qbm1jSb.png)
                
Static architecture:
The system is divided in 4 main layers:
- Microcontroller (MCU) Layer
- Microcontroller Abstraction Layer (MCAL)
- Electronic Unit Abstraction Layer (ECUAL)
- Application Layer
                
The system is divided into 5 drivers:
- DIO driver
- External interrupt driver
- Timer driver
- LED driver
- Button driver
          
![Layers1](https://i.imgur.com/2WB8oRm.png)
![Layers2](https://i.imgur.com/oKfNoOw.png)

# System State Machine
![stm](https://i.imgur.com/Sh68bSO.png)
                
# System Constraints
No system constraints were set.

