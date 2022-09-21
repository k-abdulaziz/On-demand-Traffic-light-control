/**
    @file       button.c
    @brief      Implementation of Button Driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#include "button.h"

void BUTTON_init(uint8_t buttonPin, uint8_t buttonPort)
{
	DIO_init(buttonPin, buttonPort, IN); /* Make the direction of pin connected to button as an input pin */
}

void BUTTON_read(uint8_t buttonPin, uint8_t buttonPort, uint8_t *value)
{
	DIO_read(buttonPin, buttonPort, value); /* Check the state of the pin */
}