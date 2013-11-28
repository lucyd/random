/*
A program to reverse the binary representation of a number
Author : Sreenatha Bhatlapenumarthi
Date : Nov 28, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Returns the reverse(bit-flip) of a number
int binary_reverse(int n)
{
	if(n == 0)
		return 1;
	int i = 1, reversed_n = n;
	while(i <= n)
	{
		reversed_n = reversed_n ^ i;
		i = i << 1;
	}
	return reversed_n;
}

int main()
{
	int i=0;
	printf("Enter an integer : ");
	scanf("%d", &i);
	printf("Binary reverse of %d = %d\n", i, binary_reverse(i));
	return 0;
}
