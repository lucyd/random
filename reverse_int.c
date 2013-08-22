/*
   A program to reverse an input integer
   Author: Sreenatha Bhatlapenumarthi
   Date: Aug 16, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int reversed(int);
int digit_count(int);

int main()
{
	char input[11];
	printf("Enter input integer: ");
	scanf("%s", input);
	printf("Reversed input: %d\n", reversed(atoi(input)));
	return 0;
}

// Finds the number of digits of a positive int
int digit_count(int number)
{
	int digits=1, i=0;
	for(i=0; i<10; i++)
	{
		if(number >= pow(10,i))
			digits = i+1;
		else
			break;
	}
	return digits;
}

// Reverses an input int
int reversed(int number)
{
	int i=0, reversed_number=0, next_digit=0, digits=0, negative=0;
	if(number < 0)
	{
		negative = 1;
		number = abs(number);
	}
	digits = digit_count(number);
	for(i=1; i<=digits; i++)
	{
		reversed_number *= 10;
		next_digit = ((number%(int)pow(10, i))/pow(10,i-1));
		if(reversed_number >= (2147483647 - next_digit))
		{
			printf("Error: Reversed input is not an int\n");
			exit(1);
		}
		reversed_number += next_digit;
	}
	if( negative == 1)
		return -1*reversed_number;
	else
		return reversed_number;
}
