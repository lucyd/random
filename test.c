#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char* x = (char*) malloc(sizeof(char)*10);
	printf("x=%s\n",x);
	x[0]='A';
	x[1]='A';
	x[2]='A';
	x[3]='A';
	x[4]='A';
	x[5]='A';
	x[6]='A';
	x[7]='A';
	x[8]='A';
	x[9]='A';
	printf("x=%s\n",x);
	printf("%c\n",(char)12/8+48);
	printf("%c\n",(char)64/8+48);
	return 0;
}
