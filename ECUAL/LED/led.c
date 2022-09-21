/**
    @file       led.c
    @brief      Implementation of LED Driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#include "led.h"

void LED_init(uint8_t ledPin, uint8_t ledPort)
{
	DIO_init(ledPin, ledPort, OUT); /* Make the direction of pin connected to led as an output pin */
}
void LED_on(uint8_t ledPin, uint8_t ledPort)
{
	DIO_write(ledPin, ledPort, HIGH); /* Write high to the pin connected to led */
}
void LED_off(uint8_t ledPin, uint8_t ledPort)
{
	DIO_write(ledPin, ledPort, LOW); /* Write low to the pin connected to led */
}
void LED_toggle(uint8_t ledPin, uint8_t ledPort)
{
	DIO_toggle(ledPin, ledPort); /* Toggle the pin connected to the led */
}