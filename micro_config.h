 /******************************************************************************
 *
 * File Name: Micro_Config.h
 *
 * Author: Omar Emad
 *
 * Date Created: 14/9/2018
 *
 * Description: File include all Microcontroller libraries
 *
 *******************************************************************************/

#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif  

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#endif /* MICRO_CONFIG_H_ */
