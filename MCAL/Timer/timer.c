/**
    @file       timer.c
    @brief      Timer Driver implementation
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#include "timer.h"


void TIMER0_init()
{
	/* select timer mode */
	TCCR0 = 0x00; /* Normal Mode */
}


void TIMER0_delay(uint32_t delay_time_ms)
{
    /* Timer Calculations */
	uint32_t Total_Timer_Ticks     = (CPU_Freq / (Prescaler * (1/(delay_time_ms/1000))));
	uint32_t Overflow_Count        = delay_time_ms / ((Prescaler * 256000) / CPU_Freq);
	uint8_t  Remainder_Timer_Ticks = Total_Timer_Ticks - (Overflow_Count * 256);
	uint8_t  Timer_Initial_Value   = 256 - Remainder_Timer_Ticks;
	uint32_t overflowcounter = 0;
	
	/* set timer initial value */
	TCNT0 = Timer_Initial_Value;
	
	/*  Selecting the prescaler */
	if (Prescaler == 1)
	{
		TCCR0 = 0x01; // 1 prescaler
	}
	else if (Prescaler == 8)
	{
		TCCR0 = 0x02; // 8 prescaler
	}
	else if (Prescaler == 64)
	{
		TCCR0 = 0x03; // 64 prescaler
	}
	else if (Prescaler == 256)
	{
		TCCR0 = 0x04; // 256 prescaler
	}
	else if (Prescaler == 1024)
	{
		TCCR0 = 0x05; // 1024 prescaler
	}
	
	while (overflowcounter <= Overflow_Count)
		{
			/* will be repeated for Overflow_Count times
			   wait till overflow flag is set to 1 */
			while ((TIFR &(1<<0)) == 0);
			TIFR |= (1<<0); /* Clear the overflow flag */
			overflowcounter++;
		}
	
	overflowcounter = 0; /* Reset the counter */
    TIMER0_stop(); /* Stop the timer */
}

void TIMER0_stop()
{
	TCCR0 = 0x00; /* Clear all bits of register */
}