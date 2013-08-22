/*
   A program to find the base equivalent of a number
   Author: Sreenatha Bhatlapenumarthi
   Date: Aug 18, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char* base_equivalent(int, int);

int main()
{
	int number=0, base=0;
	printf("Enter number: ");
	scanf("%d", &number);
	printf("Enter base: ");
	scanf("%d", &base);
	printf("Equivalent: %s\n", base_equivalent(number,base));
	return 0;
}

// Returns base equivalent in string representation
char* base_equivalent(int number, int base)
{
	char* equivalent_value;
	int i=0, highest_base=0, digit=0, remaining=number;
	
	while(pow(base,highest_base) <= number){
		highest_base++;
	}

	equivalent_value = (char*) malloc(sizeof(char)*highest_base);
	
	for(i=highest_base-1; i>=0; i--)
	{
		digit = remaining/pow(base,i);
		equivalent_value[highest_base-1-i] = digit + 48;
		remaining -= (pow(base,i) * digit);
	}
	return equivalent_value;
}
