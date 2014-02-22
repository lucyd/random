/*
Author: Sreenatha B
Date : Feb 22, 2014
Generates all binary strings of given length
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#ifdef _BRUTE_FORCE

int next(char* my_string, int n)
{
	int i=0, j=0;
	for(i=n-1; i>=0; i--)
	{
		if(my_string[i] == '0')
		{
			for(j=i+1; j<n; j++)
				my_string[j] = '0';
			my_string[i] = '1';
			return 1;
		}
	}
	return 0;
}

void generate(int n)
{
	char* base_string = (char*) malloc(sizeof(char)*n);
	for(int i=0; i<n; i++)
		base_string[i] = '0';
	while(next(base_string, n))
		cout << base_string << endl;
	return;
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s string_length\n", argv[0]);
		exit(1);
	}
	generate(atoi(argv[1]));
	return 0;
}

#endif

void generate_binary(char* string, int str_len, int pos)
{
	if(pos == str_len)
		cout << string << endl;
	else
	{
		string[pos] = '0';
		generate_binary(string, str_len, pos+1);
		string[pos] = '1';
		generate_binary(string, str_len, pos+1);
	}
	return;
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s string_length\n", argv[0]);
		exit(1);
	}
	int i=0, n = atoi(argv[1]);
	char* base_string = (char*) malloc(sizeof(char)*n);
	for(i=0; i<n; i++)
		base_string[i] = '0';
	generate_binary(base_string, n, 0);
	return 0;
}






