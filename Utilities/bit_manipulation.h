/**
    @file       bit_manipulation.h
    @brief      Macros defines of bit manipulation
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

/**
 * \def SET_BIT(BYTE, BIT_NO)
 * Sets the BIT_NO of BYTE
 */
#define SET_BIT(BYTE, BIT_NO)   (BYTE |= (1 << BIT_NO))

/**
 * \def CLEAR_BIT(BYTE, BIT_NO)
 * Clears the BIT_NO of BYTE
 */
#define CLEAR_BIT(BYTE, BIT_NO) (BYTE &= (~(1 << BIT_NO)))

/**
 * \def TOGGLE_BIT(BYTE,BIT_NO)
 * Toggles the BIT_NO of BYTE
 */
#define TOGGLE_BIT(BYTE,BIT_NO) (BYTE ^= (1 << BIT_NO))

/**
 * \def READ_BIT(BYTE, BIT_NO)
 * Reads the BIT_NO of BYTE
 */
#define READ_BIT(BYTE, BIT_NO)  ((BYTE & (1 << BIT_NO)) >> BIT_NO)

#endif /* BIT_MANIPULATION_H_ */