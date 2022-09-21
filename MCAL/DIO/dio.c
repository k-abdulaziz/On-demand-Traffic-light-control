/**
    @file       dio.c
    @brief      Implementation of DIO Driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#include "dio.h"

void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	switch (portNumber)
	{
		case PORT_A: /* Port A is chosen */
		{
			if (direction == IN) /* check if input direction */
			{
				CLEAR_BIT(DDRA, pinNumber); /* Clear the bit of DDRA register */
			}
			else if (direction == OUT) /* check if output direction */
			{
				SET_BIT(DDRA, pinNumber); /* Set the bit of DDRA register */
			}
			else
			{
				/* Error handling */
			}
			break;
		}
		case PORT_B: /* Port B is chosen */
		{
			if (direction == IN) /* check if input direction */
			{
				CLEAR_BIT(DDRB, pinNumber); /* Clear the bit of DDRB register */
			}
			else if (direction == OUT) /* check if output direction */
			{
				SET_BIT(DDRB, pinNumber); /* Set the bit of DDRB register */
			}
			else
			{
				/* Error handling */
			}
			break;		
		}
		case PORT_C: /* Port C is chosen */
		{
			if (direction == IN) /* check if input direction */
			{
				CLEAR_BIT(DDRC, pinNumber); /* Clear the bit of DDRC register */
			}
			else if (direction == OUT) /* check if output direction */
			{
				SET_BIT(DDRC, pinNumber); /* Set the bit of DDRC register */
			}
			else
			{
				/* Error handling */
			}
			break;
		}
		case PORT_D: /* Port D is chosen */
		{
			if (direction == IN) /* check if input direction */
			{
				CLEAR_BIT(DDRD, pinNumber); /* Clear the bit of DDRD register */
			}
			else if (direction == OUT) /* check if output direction */
			{
				SET_BIT(DDRD, pinNumber); /* Set the bit of DDRD register */
			}
			else
			{
				/* Error handling */
			}
			break;
		}
		default:
		{
			/* Error handling */
			break;
		}
	}
}

void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	switch (portNumber)
	{
		case PORT_A: /* Port A is chosen */
		{
			if (value == LOW) /* Check if low value */
			{
				CLEAR_BIT(PORTA, pinNumber); /* Clear the bit of PORTA register */
			}
			else if (value == HIGH) /* Check if high value */
			{
				SET_BIT(PORTA, pinNumber); /* Set the bit of PORTA register */
			}
			else
			{
				/* Error handling */
			}
			break;
		}
		case PORT_B: /* Port B is chosen */
		{
			if (value == LOW) /* Check if low value */
			{
				CLEAR_BIT(PORTB, pinNumber); /* Clear the bit of PORTB register */
			}
			else if (value == HIGH) /* Check if high value */
			{
				SET_BIT(PORTB, pinNumber); /* Set the bit of PORTB register */
			}
			else
			{
				/* Error handling */
			}
			break;
		}
		case PORT_C: /* Port C is chosen */
		{
			if (value == LOW) /* Check if low value */
			{
				CLEAR_BIT(PORTC, pinNumber); /* Clear the bit of PORTC register */
			}
			else if (value == HIGH) /* Check if high value */
			{
				SET_BIT(PORTC, pinNumber); /* Set the bit of PORTC register */
			}
			else
			{
				/* Error handling */
			}
			break;
		}
		case PORT_D: /* Port D is chosen */
		{
			if (value == LOW) /* Check if low value */
			{
				CLEAR_BIT(PORTD, pinNumber); /* Clear the bit of PORTD register */
			}
			else if (value == HIGH) /* Check if high value */
			{
				SET_BIT(PORTD, pinNumber); /* Set the bit of PORTD register */
			}
			else
			{
				/* Error handling */
			}
			break;
		}
		default:
		{
			/* Error handling */
			break;
		}
	}
}

void DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	switch (portNumber)
	{
		case PORT_A: /* Port A is chosen */
		{
			TOGGLE_BIT(PORTA, pinNumber); /* Toggle the bit of PORTA register */
			break;
		}
		case PORT_B: /* Port B is chosen */
		{
			TOGGLE_BIT(PORTB, pinNumber); /* Toggle the bit of PORTB register */
			break;
		}
		case PORT_C: /* Port C is chosen */
		{
			TOGGLE_BIT(PORTC, pinNumber); /* Toggle the bit of PORTC register */
			break;
		}
		case PORT_D: /* Port D is chosen */
		{
			TOGGLE_BIT(PORTD, pinNumber); /* Toggle the bit of PORTD register */
			break;
		}
		default:
		{
			/* Error handling */
			break;
		}
	}
}

void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
		switch (portNumber)
		{
			case PORT_A: /* Port A is chosen */
			{
				*value = READ_BIT(PINA, pinNumber); /* Check the bit and assign to value */
				break;
			}
			case PORT_B: /* Port B is chosen */
			{
				*value = READ_BIT(PINB, pinNumber); /* Check the bit and assign to value */
				break;
			}
			case PORT_C: /* Port C is chosen */
			{
				*value = READ_BIT(PINC, pinNumber); /* Check the bit and assign to value */
				break;
			}
			case PORT_D: /* Port D is chosen */
			{
				*value = READ_BIT(PIND, pinNumber); /* Check the bit and assign to value */
				break;
			}
			default:
			{
				/* Error handling */
				break;
			}
		}
}