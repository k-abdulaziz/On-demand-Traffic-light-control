/**
    @file       external_interrupt.c
    @brief      Implementation of External Interrupt Driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#include "external_interrupt.h"

void Ext_Interrupt_init(void)
{
    MCUCR |= (1<<0) | (1<<1); /* Select External Interrupt sense on rising edge */ 
    GICR  |= (1<<6); /* Enable External Interrupt 0 - INT0 */
}