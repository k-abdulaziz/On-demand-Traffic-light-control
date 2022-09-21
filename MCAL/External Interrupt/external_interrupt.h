/**
    @file       external_interrupt.h
    @brief      API's of External interrupt Driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

#include "../../Utilities/registers.h"

/************************************************************************/
/*                        INTERRUPTS VECTORS                            */
/************************************************************************/

/** External Interrupt Request 0 */
#define EXT_INT_0 __vector_1
/** External Interrupt Request 1 */
#define EXT_INT_1 __vector_2
/** External Interrupt Request 2 */
#define EXT_INT_2 __vector_3

/** Set Global Interrupts, Set the I-bit in status register to 1 */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/** Clear Global Interrupts, Set the I-bit in status register to 0 */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* ISR definition */
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


/************************************************************************/
/*                         Interrupt Function                           */
/************************************************************************/

/**
 * @brief  Initializes the External Interrupt Driver
 * @param  void
 * @return void
 */
void Ext_Interrupt_init(void);

#endif /* EXTERNAL_INTERRUPT_H_ */