/**
    @file       external_interrupt_test.c
    @brief      Testing Module of External Interrupt Driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       15/9/2022
*/

#include "external_interrupt.h"
#include "../../ECUAL/LED/led.h"
#include "../../ECUAL/Button/button.h"

/*
#define NUMBER_of_LEDS 3

uint8_t led_number = 0;

int main(void)
{
    / * 1.Set direction of button as input * /
    BUTTON_init(EXT_INT_BUTTON_PIN, EXT_INT_BUTTON_PORT);

    / * 2.Set direction of button as input * /
    LED_init(PIN0,PORT_A);
    LED_init(PIN1,PORT_A);
    LED_init(PIN2,PORT_A);
    
    / * 3.Enable global interrupts * /
    sei();
    
    / * 4.Select the external interrupt sense As rising Edge and enable external interrupt * /
    Ext_Interrupt_init();
    
    while (1)
    {
        switch(led_number)
        {
            case 0:
            LED_off(PIN0, PORT_A);
            LED_off(PIN1, PORT_A);
            LED_off(PIN2, PORT_A);
            break;
            case 1:
            LED_on(PIN0, PORT_A);
            break;
            case 2:
            LED_on(PIN1, PORT_A);
            break;
            case 3:
            LED_on(PIN2, PORT_A);
            break;
            default:
            //do nothing
            break;
        }
    }
}*/

/*
ISR(EXT_INT_0)
{
    if(led_number < NUMBER_of_LEDS)
    {
        led_number++;
    }
    else
    {
        led_number = 0;
    }
}*/