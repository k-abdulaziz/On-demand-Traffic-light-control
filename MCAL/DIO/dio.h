/**
    @file       dio.h
    @brief      API's of DIO Driver
    @author     Khaled Abdulaziz
    @version    1.00
    @date       14/9/2022
*/

#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

/** @name PINs
 *  Definitions of pins. 
 */
///@{
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
///@}


/** @name PORTs
 *  Definitions of ports. 
 */
///@{
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
///@}

/** @name Direction
 *  Definitions of direction as 0 for input and 1 for output. 
 */
///@{
#define IN  0
#define OUT 1
///@}

/** @name Value
 *  Definitions of value as 0 for low and 1 for high. 
 */
///@{
#define LOW  0
#define HIGH 1
///@}

/**
 * @brief  Initializes the direction of the pin
 * @param  pinNumber The number of pin
 * @param  portNumber The number of port
 * @param  direction The direction of the pin
 * @return void
 */
void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);

/**
 * @brief  Writes a value to  the pin
 * @param  pinNumber The number of pin
 * @param  portNumber The number of port
 * @param  value The value to write to the pin
 * @return void
 */
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);

/**
 * @brief  Toggles the pin value if 1 or 0
 * @param  pinNumber The number of pin
 * @param  portNumber The number of port
 * @return void 
 */
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber);

/**
 * @brief  Reads the value in the pin
 * @param  pinNumber The number of pin
 * @param  portNumber The number of port
 * @param  value Returns the value as a pointer
 * @return void
 */
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

#endif /* DIO_H_ */