/**
    @file       led.h
    @brief      API's of LED Driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#ifndef LED_H_
#define LED_H_


#include "../../MCAL/DIO/dio.h"

/** @name Cars LEDs
 *  Definitions of pins and it ports for LEDs. 
 */
///@{
#define CARS_GREEN_LED_PORT  PORT_A
#define CARS_GREEN_LED_PIN   PIN0
#define CARS_YELLOW_LED_PORT PORT_A
#define CARS_YELLOW_LED_PIN  PIN1
#define CARS_RED_LED_PORT    PORT_A
#define CARS_RED_LED_PIN     PIN2
///@}

/** @name Pedestrians LEDs
 *  Definitions of pins and it ports for LEDs. 
 */
///@{
#define PEDS_GREEN_LED_PORT  PORT_B
#define PEDS_GREEN_LED_PIN   PIN0
#define PEDS_YELLOW_LED_PORT PORT_B
#define PEDS_YELLOW_LED_PIN  PIN1
#define PEDS_RED_LED_PORT    PORT_B
#define PEDS_RED_LED_PIN     PIN2
///@}

/**
 * @brief  
 * @param  ledPin 
 * @param  ledPort 
 * @return void
 */
void LED_init(uint8_t ledPin, uint8_t ledPort);

/**
 * @brief  
 * @param  ledPin 
 * @param  ledPort 
 * @return void
 */
void LED_on(uint8_t ledPin, uint8_t ledPort);

/**
 * @brief  
 * @param  ledPin 
 * @param  ledPort 
 * @return void
 */
void LED_off(uint8_t ledPin, uint8_t ledPort);

/**
 * @brief  
 * @param  ledPin 
 * @param  ledPort 
 * @return void
 */
void LED_toggle(uint8_t ledPin, uint8_t ledPort);

#endif /* LED_H_ */