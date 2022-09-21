/**
    @file       dio_test.c
    @brief      Testing Module of DIO Driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       15/9/2022
*/

#include "dio.h"

/*
int main(void)
{*/
    /************************************************************************/
    /*                            Test Case 1                               */
    /************************************************************************/
/*
    DIO_init(PIN4,PORT_A,OUT);
    DIO_init(PIN0,PORT_C,OUT);
    DIO_init(PIN7,PORT_D,IN);
    DIO_init(PIN2,PORT_B,IN);
    while(1)
    {
            DIO_write(PIN4,PORT_A,LOW);
            DIO_write(PIN0,PORT_C,HIGH);
            DIO_write(PIN7,PORT_D,LOW);
            DIO_write(PIN2,PORT_B,HIGH);
            DIO_toggle(PIN4,PORT_A);
    }*/
    
    /************************************************************************/
    /*                            Test Case 2                               */
    /************************************************************************/
/*
    DIO_init(PIN0,PORT_B,OUT);
    DIO_init(PIN1,PORT_B,OUT);
    DIO_init(PIN2,PORT_B,IN);
    DIO_init(PIN3,PORT_B,IN);
    while(1)
    {
            DIO_write(PIN0,PORT_B,HIGH);
            DIO_write(PIN1,PORT_B,HIGH);
            DIO_write(PIN2,PORT_B,LOW);
            DIO_write(PIN3,PORT_B,LOW);
            DIO_toggle(PIN4,PORT_B);
    }
}*/
