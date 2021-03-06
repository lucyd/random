/*
   Implementation of queues using dynamic arrays
   Author: Sreenatha Bhatlapenumarthi
   Date: Oct 26, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

// Structure definitions
typedef struct
{
	int front;
	int rear;
	int capacity;
	int element_size;
	void* array;
} queue;

// Function prototypes
queue create_empty_queue(int capacity, int element_size);
queue enqueue(queue q, void* element);
queue dequeue(queue q);
queue resize(queue q);
int size(queue q);
int is_empty(queue q);
int is_full(queue q);
void* front(queue q);
void free_queue(queue q);

// Function definitions
// Creates an empty queue of given capacity
queue create_empty_queue(int capacity, int element_size)
{
	queue q;
	q.front = 0;
	q.rear = 0;
	q.capacity = capacity;
	q.element_size = element_size;
	q.array = (void*)malloc(element_size*capacity);
	if(!q.array)
	{
		printf("Memory error: Cannot initialize queue\n");
	}
	return q;
}

// Inserts element at the rear end of queue
// (element should point to a void* typecasted address containing the element data)
queue enqueue(queue q, void* element)
{
	if(is_full(q))
	{
		#ifdef _AUTO_RESIZE_DISABLED
			printf("Error: Queue is full\n");
			exit(1);
		#else
			q = resize(q);
		#endif
	}
	memcpy(q.array + q.rear*q.element_size, element, q.element_size);
	q.rear = (q.rear + 1)%q.capacity;
	return q;
}

// Removes front element from queue
queue dequeue(queue q)
{
	q.front = (q.front + 1)%q.capacity;
	return q;
}

// Returns queue with capacity doubled and order maintained
queue resize(queue q)
{
	int i=0;
	void* new_array = (void*) malloc(q.element_size*q.capacity*2);
	for(i=q.front; i<q.rear; i++)
		memcpy(new_array+(i-q.front)*q.element_size, q.array+i*q.element_size, q.element_size);
	q.array = new_array;
	q.capacity *= 2;
	return q;
}

// Returns size of the queue
int size(queue q)
{
	if(q.rear >= q.front)
		return (q.rear-q.front);
	else
		return q.capacity-(q.front-q.rear)+1;
}

// Returns front element of queue
void* front(queue q)
{
	return q.array+(q.front*q.element_size);
}

// Returns 1 if queue is empty, 0 otherwise
int is_empty(queue q)
{
	if(q.front == q.rear)
		return 1;
	else
		return 0;
}

// Returns 1 if queue is full, 0 otherwise
int is_full(queue q)
{
	if(((q.rear+1)%q.capacity) == (q.front%q.capacity))
		return 1;
	else
		return 0;
}

// Frees the queue structure
void free_queue(queue q)
{
	free(q.array);
}

