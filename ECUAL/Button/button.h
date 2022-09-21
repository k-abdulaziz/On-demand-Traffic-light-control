/**
    @file       button.h
    @brief      API's of Button Driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"

/** @name Button Port and Pin
 *  Definitions of the pin and port of the button. 
 */
///@{
#define EXT_INT_BUTTON_PORT PORT_D
#define EXT_INT_BUTTON_PIN  PIN2
///@}
    
/** @name Button States
 *  Definitions of states of button 0 for low and 1 for high. 
 */
///@{
#define BUTTON_STATE_LOW  0
#define BUTTON_STATE_HIGH 1
///@}

/**
 * @brief  Initializes the direction of the button pin
 * @param  buttonPin The pin of the button
 * @param  buttonPort The port of the button pin
 * @return void
 */
void BUTTON_init(uint8_t buttonPin, uint8_t buttonPort);

/**
 * @brief  Reads the value of the button pin
 * @param  buttonPin The pin of the button
 * @param  buttonPort The port of the button pin
 * @param  value The value of the pin whether low or high
 * @return void
 */
void BUTTON_read(uint8_t buttonPin, uint8_t buttonPort, uint8_t *value);

#endif /* BUTTON_H_ */