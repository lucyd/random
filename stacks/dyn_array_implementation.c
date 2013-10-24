/*
   Dynamic array implementation of stack ADT
   (Amortized push : O(n))
   Author: Sreenatha Bhatlapenumarthi
   Date: Oct 24, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Structure declarations
typedef struct
{
	int* array;
	int current_size;
	int capacity;
} stack;

// Function prototypes
stack create_empty_stack();
stack push(stack, int);
stack pop(stack);
int top(stack);
int size(stack);
int is_empty(stack);
int is_full(stack);
stack resize(stack);

//Function definitions
//Returns an empty stack
stack create_empty_stack()
{
	stack s;
	s.current_size = 0;
	s.capacity = 1;
	s.array = (int*) malloc(sizeof(int)*1);
	return s;
}

// Pushes element onto stack
stack push(stack s, int element)
{
	if(is_full(s))
	{
		s = resize(s);
	}
	s.array[s.current_size] = element;
	s.current_size++;
	return s;
}

// Pops top element from stack
stack pop(stack s)
{
	if(is_empty(s))
	{
		printf("Error: Stack underflow\n");
		exit(1);
	}
	s.current_size--;
	return s;
}

// Returns top element of stack
int top(stack s)
{
	if(is_empty(s))
	{
		printf("Stack is empty\n");
		return INT_MIN;
	}
	return s.array[s.current_size - 1];
}

// Returns size of stack
int size(stack s)
{
	return s.current_size;
}

// Returns 1 if stack is empty, 0 otherwise
int is_empty(stack s)
{
	return (s.current_size == 0);
}

// Returns 1 if stack is full, 0 otherwise
int is_full(stack s)
{
	return (s.current_size == s.capacity);
}

// Resizes the current stack to accommodate more elements
stack resize(stack s)
{
	// Declare the new stack array of double capacity
	int *temp, *new_array = (int*)malloc(sizeof(int) * 2 * s.capacity);
	int i=0;
	// Move current stack elements to the new array
	for(i=0; i<s.capacity; i++)
	{
		new_array[i] = s.array[i];
	}
	// Free previous stack-array memory
	temp = s.array;
	free(temp);
	s.array = new_array;
	s.capacity *= 2;
	return s;
}

int main()
{
	stack s = create_empty_stack();
	s = push(s, 10);
	s = push(s, 20);
	s = push(s, 30);
	s = push(s, 40);
	s = push(s, 50);
	s = pop(s);
	printf("Size of stack is %d\n",size(s));
	printf("Capacity of stack is %d\n",s.capacity);
	printf("Top of stack is %d\n",top(s));
	return 0;
}
