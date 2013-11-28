/*
   A program to count the number of 1's in binary representation of a number
Author : Sreenatha Bhatlapenumarthi
Date : Nov 28, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

// Returns the count of 1's in binary representation of input
int count_ones(int n)
{
	if( n == 0)
		return 0;
	int i=1, count = 0;
	while (i <= n)
	{
		if( i & n )
			count++;
		i = i << 1;
	}
	return count;
}

int main()
{
	int i=0;
	printf("Enter an integer : ");
	scanf("%d", &i);
	printf("Ones count of %d = %d\n", i, count_ones(i));
	return 0;
}
