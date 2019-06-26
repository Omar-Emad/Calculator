
/*
 * main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: Omar
 */
 
 
#include "Helper_Function.h"

uint8 asciiToInt(uint8 x)
{
	return x-48;
}


char* itos (sint32 data,char* const p_result)
{
	int temp_int;
	char * ptr1 = p_result, * ptr2=p_result , temp_char;
	do
	{
		temp_int=data;
		data/=10;
		*ptr2 = "9876543210123456789" [9 + (temp_int - data * 10)];
		ptr2++;
	} while (data);

	if(temp_int<0)  /* for the sign */
	{
		*ptr2+='-';
		ptr2++;
	}
	*ptr2 = '\0';
	ptr2--;

	while(ptr1<ptr2)
	{
		temp_char = *ptr2;
		*ptr2=*ptr1;
		*ptr1=temp_char;
		ptr1++;
		ptr2--;
	}
	return p_result;
}


uint32 pow (uint32 x, uint32 y)
{
	uint32 result=1;
	if(y==0)
		return 1;

	for(y;y>0;y--)
	{
		result*=x;
	}
	return result;
}