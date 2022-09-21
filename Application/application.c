/**
    @file       application.c
    @brief      Implementation of Apllication Layer
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#include "application.h"

/** Declaration of counter variable */
uint8_t i;

/** Initialization of Normal Mode as default Traffic Light Mode */
Traffic_Light_Mode TL_Current_Mode = Normal_Mode;

/** Declaration of Current Led state of Car */
Car_LED_State Car_Current_LED;

void APP_init(void)
{
	/* Initialization of Cars LEDs */
    LED_init(CARS_GREEN_LED_PIN, CARS_GREEN_LED_PORT);
	LED_init(CARS_YELLOW_LED_PIN, CARS_YELLOW_LED_PORT);
    LED_init(CARS_RED_LED_PIN, CARS_RED_LED_PORT);
    
    /* Initialization of Cars LEDs */
    LED_init(PEDS_GREEN_LED_PIN, PEDS_GREEN_LED_PORT);
    LED_init(PEDS_YELLOW_LED_PIN, PEDS_YELLOW_LED_PORT);
    LED_init(PEDS_RED_LED_PIN, PEDS_RED_LED_PORT);
    
    /* Initialization of Pedestrian's Button */
    BUTTON_init(EXT_INT_BUTTON_PIN, EXT_INT_BUTTON_PORT);
    
    /* Initialization of TIMER0 */
	TIMER0_init();
    
    /* Enabling Global Interrupts */
    sei();
    
    /* Initialization of EXTernal INTerrupt 0 */
    Ext_Interrupt_init();
    
}

void APP_start(void)
{
	while (1)
	{
        Traffic_Light_NM(); /* Start the Normal mode */
        /* Check if in Pedestrians mode and the cars led state is red */
        if ((TL_Current_Mode == Pedestrian_Mode) && Car_Current_LED == CAR_RED_LED)
        {
            Traffic_Light_PRM(); /* Start the Pedestrians Red mode */
        }
        /* Check if in Pedestrians mode and the cars led state is green or yellow */
        if ((TL_Current_Mode == Pedestrian_Mode) && (Car_Current_LED == CAR_GREEN_LED || Car_Current_LED == CAR_YELLOW_LED))
        {
            Traffic_Light_PGYM(); /* Start the Pedestrians Green Yellow mode */
        }
        
	}
}

void Traffic_Light_NM(void)
{
    /* Turn the Pedestrians Red Led on */
    LED_on(PEDS_RED_LED_PIN, PEDS_RED_LED_PORT);
    /* check if still in normal mode */
    if ((TL_Current_Mode == Normal_Mode))
    {
        Car_Current_LED = CAR_GREEN_LED; /* Make state of Cars Led as Green */
        /* Turn the Cars Green Led on */
        LED_on(CARS_GREEN_LED_PIN, CARS_GREEN_LED_PORT);
        TIMER0_delay(5000); /* Delay for 5 seconds */
        /* Turn the Cars Green Led off */
        LED_off(CARS_GREEN_LED_PIN, CARS_GREEN_LED_PORT);
    }
    /* check if still in normal mode */
    if ((TL_Current_Mode == Normal_Mode))
    {
        Car_Current_LED = CAR_YELLOW_LED; /* Change the state of Cars Led to Yellow */
        /* Toggle the led for 5 seconds 0.5 on and 0.5 off */
        for (i = 0; i < 5; i++)
        {
            /* Turn the Cars Yellow Led on */
            LED_on(CARS_YELLOW_LED_PIN, CARS_YELLOW_LED_PORT);
            TIMER0_delay(500); /* Delay for 0.5 second */
            /* Turn the Cars Yellow Led off */
            LED_off(CARS_YELLOW_LED_PIN, CARS_YELLOW_LED_PORT);
            TIMER0_delay(500); /* Delay for 0.5 second */
        }
    }
    /* check if still in normal mode */
    if ((TL_Current_Mode == Normal_Mode))
    {
        Car_Current_LED = CAR_RED_LED; /* Change the state of Cars Led to Red */
        /* Turn the Cars Red Led on */
        LED_on(CARS_RED_LED_PIN, CARS_RED_LED_PORT);
        /* Iterates for 100 iterations each one is 50ms */
        for (i = 0; i < 100; i++)
        {
            TIMER0_delay(50); /* Delay of 50 milliseconds */
            /* Check if there's an external interrupt end the loop */
            if((TL_Current_Mode == Pedestrian_Mode)) return;
        }
        //TIMER0_delay(5000);
        LED_off(CARS_RED_LED_PIN, CARS_RED_LED_PORT);
    }
    /* check if still in normal mode */
    if ((TL_Current_Mode == Normal_Mode))
    {
        Car_Current_LED = CAR_YELLOW_LED; /* Change the state of Cars Led to Yellow */
        /* Toggle the led for 5 seconds 0.5 on and 0.5 off */
        for (i = 0; i < 5; i++)
        {
            /* Turn the Cars Yellow Led on */
            LED_on(CARS_YELLOW_LED_PIN, CARS_YELLOW_LED_PORT);
            TIMER0_delay(500); /* Delay for 0.5 second */
            /* Turn the Cars Yellow Led off */
            LED_off(CARS_YELLOW_LED_PIN, CARS_YELLOW_LED_PORT);
            TIMER0_delay(500); /* Delay for 0.5 second */
        }
    }
}

void Traffic_Light_PRM(void)
{
    /* Turn the Pedestrians Red Led off */
    LED_off(PEDS_RED_LED_PIN, PEDS_RED_LED_PORT);
    /* Turn the Pedestrians Green Led off */
    LED_on(PEDS_GREEN_LED_PIN, PEDS_GREEN_LED_PORT);
    /* Turn the Cars Red Led on */
    LED_on(CARS_RED_LED_PIN, CARS_RED_LED_PORT);
    TIMER0_delay(5000); /* Delay for 5 seconds */
    /* Return back to Normal mode */
    Transition_from_PM_to_NM();
}

void Traffic_Light_PGYM(void)
{
    /* Turn the Pedestrians Red Led on */
    LED_on(PEDS_RED_LED_PIN, PEDS_RED_LED_PORT);
    /* Both Yellow Leds blinking for 5 seconds */
    for (i = 0; i < 5; i++)
    {
       /* Turn the Cars Yellow Led on */
       LED_on(CARS_YELLOW_LED_PIN, CARS_YELLOW_LED_PORT);
       /* Turn the Pedestrians Yellow Led on */
       LED_on(PEDS_YELLOW_LED_PIN, PEDS_YELLOW_LED_PORT);
       TIMER0_delay(500); /* Delay for 0.5 second */
       /* Turn the Cars Yellow Led off */
       LED_off(CARS_YELLOW_LED_PIN, CARS_YELLOW_LED_PORT);
       /* Turn the Pedestrians Yellow Led off */
       LED_off(PEDS_YELLOW_LED_PIN, PEDS_YELLOW_LED_PORT);
       TIMER0_delay(500); /* Delay for 0.5 second */
    }
    /* Turn the Pedestrians Red Led off */
    LED_off(PEDS_RED_LED_PIN, PEDS_RED_LED_PORT);
    /* Turn the Cars Red Led off */
    LED_on(CARS_RED_LED_PIN, CARS_RED_LED_PORT);
    /* Turn the Pedestrians Green Led off */
    LED_on(PEDS_GREEN_LED_PIN, PEDS_GREEN_LED_PORT);
    TIMER0_delay(5000); /* Delay for 5 seconds */
    /* Return back to Normal mode */
    Transition_from_PM_to_NM();
}

void Transition_from_PM_to_NM(void)
{
    /* Turn the Pedestrians Red Led off */
    LED_off(CARS_RED_LED_PIN, CARS_RED_LED_PORT);
    /* Both Yellow Leds blinking for 5 seconds */
    for (i = 0; i < 5; i++)
    {
       /* Turn the Cars Yellow Led on */
       LED_on(CARS_YELLOW_LED_PIN, CARS_YELLOW_LED_PORT);
       /* Turn the Pedestrians Yellow Led on */
       LED_on(PEDS_YELLOW_LED_PIN, PEDS_YELLOW_LED_PORT);
       TIMER0_delay(500); /* Delay for 0.5 second */
       /* Turn the Cars Yellow Led off */
       LED_off(CARS_YELLOW_LED_PIN, CARS_YELLOW_LED_PORT);
       /* Turn the Pedestrians Yellow Led off */
       LED_off(PEDS_YELLOW_LED_PIN, PEDS_YELLOW_LED_PORT);
       TIMER0_delay(500); /* Delay for 0.5 second */
    }
    /* Turn the Pedestrians Green Led off */
    LED_off(PEDS_GREEN_LED_PIN, PEDS_GREEN_LED_PORT);
    /* Turn the Pedestrians Red Led on */
    LED_on(PEDS_RED_LED_PIN, PEDS_RED_LED_PORT);
    /* Change the mode to be Normal mode */
    TL_Current_Mode = Normal_Mode;
}

ISR(EXT_INT_0)
{
    /* Change the mode to be Pedestrian mode */
    TL_Current_Mode = Pedestrian_Mode;
}