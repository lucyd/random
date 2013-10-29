/*
   Linked list implementation of stacks
   Author: Sreenatha Bhatlapenumarthi
   Date: Oct 24, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "../linked_list/singly_linked/implementation.c"

typedef node* stack;

// Function declarations
stack push(stack, int);
stack pop(stack);
int top(stack);
int size(stack);
int is_empty(stack);
int is_full(stack);

// Function definitions
// Pushes element onto stack
stack push(stack s, int element)
{
	return (stack)insert_at_begin(s, element);
}

// Pops top element from stack
stack pop(stack s)
{
	return (stack)delete_at_begin(s);
}

// Returns the top element of stack
int top(stack s)
{
	return s->data;
}

// Returns size of stack
int size(stack s)
{
	return length(s);
}

// Returns 1 if stack is empty, 0 otherwise
int is_empty(stack s)
{
	if(s == NULL)
		return 1;
	else
		return 0;
}

// Returns 1 if stack is full, 0 otherwise
int is_full(stack s)
{
	return 0;
}

// Below code implements functionality to enable stack-capacity
#ifdef _ENABLE_CAPACITY
typdef struct stack
{
	node* list;
	int current_size;
	int capacity;
} stack;

void set_capacity(stack, int);

stack push(stack s, int element)
{
	if(s.current_size == s.capacity)
	{
		printf("Error: Stackoverflow attempt\n");
		exit(1);
	}
	else
	{
		s.list = insert_at_begin(s.list, element);
		s.current_size++;
	}
	return s;
}

stack pop(stack s)
{
	if(s.current_size == 0)
	{
		printf("Error: Stackunderflow attempt\n");
		exit(1);
	}
	else
	{
		s.list = delete_at_begin(s.list);
		s.current_size--;
	}
	return s;
}

int top(stack s)
{
	if(s.current_size == 0)
	{
		printf("Error: Stack is empty\n");
		return INT_MIN;
	}
	else
		return s.list->data;
}

int size(stack s)
{
	return s.current_size;
}

int is_empty(stack s)
{
	return (s.current_size == 0);
}

int is_full(stack s)
{
	return (s.current_size == s.capacity);
}

void set_capacity(stack s, int capacity)
{
	s.capacity = capacity;
	return;
}
#endif

