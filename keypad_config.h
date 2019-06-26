/*********************************************************
 *
 * File Name: keypad_config.h
 *
 * Author: Omar Emad
 *
 * Date Created: 15/9/2018
 *
 * Description : Configuration file for the keypad driver
 *
 *********************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define N_col 4       /* number of columns in the keypad */
#define N_row 4       /* number of rows in the keypad */

/* hardware pins */
#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_DIR DDRA
#define KEYPAD_PORT_IN PINA

#endif /* KEYPAD_CONFIG_H_ */
