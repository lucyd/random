/*
Author : lucyd
Date : Feb 22, 2014
Recursive solution to the The Towers of Hanoi problem
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Move the N bricks from tower A to B, using C as auxiliary tower
void towers_of_hanoi(int N, char* A, char* B, char* C)
{
	if(N == 0) return;
	else if(N == 1)	printf("1 : %s -> %s\n", A, B);
	else
	{
		// Move N-1 bricks from A to C
		towers_of_hanoi(N-1, A, C, B);
		// Move Nth brick from A to B
		printf("%d : %s -> %s\n", N, A, B);
		// Move N-1 bricks from C to B
		towers_of_hanoi(N-1, C, B, A);
	}
	return;
}

int main(int argc, char* argv[])
{
	if(argc != 5)
	{
		printf("Usage: %s Bricks TowerA TowerB TowerC\n(Moves Bricks from TowerA to TowerB with auxiliary TowerC)\n", argv[0]);
		exit(1);
	}
	towers_of_hanoi(atoi(argv[1]), argv[2], argv[3], argv[4]);
	return 0;
}
