/**
    @file       button_test.c
    @brief      Testing Module of Button Driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       15/9/2022
*/

#include "../LED/led.h"
#include "button.h"

/*
int main(void)
{*/
    /************************************************************************/
    /*                            Test Case 1                               */
    /************************************************************************/
/*
    LED_init(PIN4, PORT_C);
    BUTTON_init(PIN0, PORT_C);
    while(1)
    {
        uint8_t Button_State = LOW;
        BUTTON_read(PIN0, PORT_C, &Button_State);
        if (Button_State == HIGH)
        {
            LED_on(PIN4, PORT_C);
        }
        else if (Button_State == LOW)
        {
            LED_off(PIN4, PORT_C);
        }
        else
        {
            //do nothing
        }
    }*/
    
        /************************************************************************/
        /*                            Test Case 2                               */
        /************************************************************************/
/*
    LED_init(PIN5, PORT_B);
    BUTTON_init(PIN0, PORT_B);
    while(1)
    {
        uint8_t Button_State = LOW;
        BUTTON_read(PIN0, PORT_C, &Button_State);
        if (Button_State == HIGH)
        {
            LED_off(PIN5, PORT_B);
        }
        else if (Button_State == LOW)
        {
            LED_on(PIN5, PORT_B);
        }
        else
        {
            //do nothing
        }
    }
}*/