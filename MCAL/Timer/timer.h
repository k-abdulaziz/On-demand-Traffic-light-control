/**
    @file       timer.h
    @brief      API's of timer driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#ifndef TIMER_H_
#define TIMER_H_

#include "../../ECUAL/LED/led.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

/**
 * \def CPU_Freq
 * Represents the Frequency of the CPU in Hz
 */
#define CPU_Freq 1000000

/**
 * \def Prescaler
 * Represents the Prescaler of the timer
 */
#define Prescaler 64

/**
 * @brief  Initializes the timer
 * @return void
 */
void TIMER0_init();

/**
 * @brief  Generates a delay in milliseconds
 * @param  delay_time_ms the time of delay
 * @return void
 */
void TIMER0_delay(uint32_t delay_time_ms);

/**
 * @brief  Stops the timer
 * @return void
 */
void TIMER0_stop();

#endif /* TIMER_H_ */