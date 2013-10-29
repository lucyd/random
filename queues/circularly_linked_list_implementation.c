/*
   Circularly linked list implementation of Queue ADT
   Author : Sreenatha Bhatlapenumarthi
   Date : Oct 30, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "../linked_list/circularly_linked/implementation.c"

// Structure declarations
typedef struct
{
	int size;
	node* list;
} queue;

// Function prototypes
// ADT operations
queue create_empty_queue();
queue enqueue(queue q, int element);
queue deque(queue q);
int queue_size(queue q);
int front(queue q);
int is_full(queue q);
int is_empty(queue q);
//Auxiliary operations
void print_queue(queue q);

// Function definitions
// Creates an empty queue of given capacity
queue create_empty_queue()
{
	queue q;
	q.size = 0;
	q.list = create_empty_list();
	return q;
}

// Inserts element at the rear end of queue
queue enqueue(queue q, int element)
{
	q.size++;
	q.list = insert_at_end(q.list, element);
	return q;
}

// Removes front element from queue
queue deque(queue q)
{
	q.size--;
	q.list = delete_at_begin(q.list);
	return q;
}

// Returns size of the queue
int queue_size(queue q)
{
	return q.size;
}

// Returns front element of queue
int front(queue q)
{
	if(q.size == 0)
		return INT_MIN;
	else
		return q.list->data;
}

// Returns 1 if queue is full, 0 otherwise
int is_full(queue q)
{
	return 0;
}

// Returns 1 if queue is empty, 0 otherwise
int is_empty(queue q)
{
	return !q.size;
}

// Prints the queue from front to rear
void print_queue(queue q)
{
	print_list(q.list);
}


