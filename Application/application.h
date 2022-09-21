/**
    @file       application.h
    @brief      API's of Application Layer
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/LED/led.h"
#include "../ECUAL/Button/button.h"
#include "../MCAL/Timer/timer.h"
#include "../MCAL/External Interrupt/external_interrupt.h"

/** 
 * The enumeration of Traffic Light Mode
 */
typedef enum {
    Normal_Mode,    /**< First Mode  */
    Pedestrian_Mode /**< Second Mode */
}Traffic_Light_Mode;

/** 
 * The enumeration of state of cars LED
 */
typedef enum {
    CAR_GREEN_LED,  /**< First State  */
    CAR_YELLOW_LED, /**< Second State */
    CAR_RED_LED     /**< Third state  */
}Car_LED_State;

/**
 * @brief  Initializes the application
 */
void APP_init(void);

/**
 * @brief  Starts the application
 */
void APP_start(void);

/**
 * @brief  Runs the Normal Mode of the Traffic Light
 */
void Traffic_Light_NM(void);

/**
 * @brief  Runs the Pedestrian Red Mode of the Traffic Light
 */
void Traffic_Light_PRM(void);

/**
 * @brief  Runs the Pedestrian Green Yellow Mode of the Traffic Light
 */
void Traffic_Light_PGYM(void);

/**
 * @brief  Moves from Pedestrian Mode to Normal Mode
 */
void Transition_from_PM_to_NM(void);

#endif /* APPLICATION_H_ */