/*
   Implementation of queues using dynamic arrays
   Author: Sreenatha Bhatlapenumarthi
   Date: Oct 26, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#ifdef _NO_DEFAULT_TYPEDEF
typedef int element_type;
#endif

// Structure definitions
typedef struct
{
	int front;
	int rear;
	int capacity;
	element_type* array;
} queue;

// Function prototypes
queue create_empty_queue(int capacity);
queue enqueue(queue q, element_type element);
queue dequeue(queue q);
queue resize(queue q);
element_type front(queue q);
int size(queue q);
int is_empty(queue q);
int is_full(queue q);
void free(queue q);

// Function definitions
// Creates an empty queue of given capacity
queue create_empty_queue(int capacity)
{
	queue q;
	q.front = 0;
	q.rear = 0;
	q.capacity = capacity;
	q.array = (element_type*)malloc(sizeof(element_type)*capacity);
	if(!q.array)
	{
		printf("Memory error: Cannot initialize queue\n");
	}
	return q;
}

// Inserts element at the rear end of queue
queue enqueue(queue q, element_type element)
{
	if(is_full(q))
	{
		#ifdef _RESIZE_DISABLED
			printf("Error: Queue is full\n");
			exit(1);
		#else
			q = resize(q);
		#endif
	}
	q.array[q.rear] = element;
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
	element_type* new_array = (element_type*) malloc(sizeof(element_type)*q.capacity*2);
	for(i=q.front; i<q.rear; i++)
		new_array[i-q.front] = q.array[i];
	q.array = new_array;
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
element_type front(queue q)
{
	return q.array[q.front];
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
void free(queue q)
{
	free(q.array);
}

