/*********************************************************
 *
 * File Name: keypad.h
 *
 * Author: Omar Emad
 *
 * Date Created: 14/9/2018
 *
 * Description : header file for the keypad driver
 *
 *********************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
#include "keypad_config.h"


/*****************************************************************
 *			         Functions Prototypes                        *
 *****************************************************************/

uint8 KEYPAD_getPressedKey (void);


#endif /* KEYPAD_H_ */
