/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Omar
 */

#include "lcd.h"
#include "keypad.h"
#include "Helper_Function.h"
#include "std_types.h"


uint32 calculate (const char * p_str);


int main (void)
{
	uint8 keyValue;
	char userInputStr [16], buffer [16];  /* user can enter max 16 char */
	uint8 i;
	bool resultOnScreen=FALSE;

	LCD_init ();
	LCD_moveCursor(1,0);
	LCD_cursorBlinkOn();

	while (1)
	{

		keyValue = KEYPAD_getPressedKey();
		LCD_cursorBlinkOn();

		if (keyValue==13)
		{
			LCD_clear();
			LCD_moveCursor(1,0);
			i=0;
			resultOnScreen=FALSE;
		}
		else if(i==16)  /* reached max */
		{
			LCD_displayAtPosition(3,0,"ERROR max digits");
		}
		else if(keyValue=='=')
		{
			if( ! resultOnScreen)
			{
				LCD_cursorBlinkOff();
				userInputStr[i]='\0';
				LCD_displayAtPosition(2,0,(itos(calculate(userInputStr),buffer)));
				i=0;
				resultOnScreen=TRUE;
			}
		}
		else
		{
			if(i==0)
			{
				LCD_clear();
				LCD_moveCursor(1,0);
				resultOnScreen=FALSE;
			}
			LCD_displayChar(keyValue);
			userInputStr[i]=keyValue;
			i++;
		}

	}
}


uint32 calculate (const char * p_str)
{
	uint8 firstOperantLength=0, secOperantLength=0;
	uint32 firstOperant=0, secOperant=0;
	char operator;
	uint8 i=0;

	while((*p_str)!='+' && (*p_str)!='-' && (*p_str)!='*' && (*p_str)!='/')
	{
		firstOperantLength++;
		p_str++;
	}
	operator = *p_str;
	p_str++;
	while((*p_str) != '\0')
	{
		secOperantLength++;
		p_str++;
	}
	p_str--;

	for(i=0;i<secOperantLength;i++)
	{
		secOperant+= asciiToInt(*p_str)*pow(10,i);
		p_str--;
	}
	p_str--;
	for(i=0;i<firstOperantLength;i++)
	{
		firstOperant+= asciiToInt(*p_str)*pow(10,i);
		p_str--;
	}

	switch(operator)
	{
		case '+': return firstOperant+secOperant;
		case '*': return firstOperant*secOperant;
		case '/': return firstOperant/secOperant;
		case '-': return firstOperant-secOperant;
	}
}




