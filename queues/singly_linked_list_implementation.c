/*
   Linked list(singly) implementation of Queue ADT
   Author : Sreenatha Bhatlapenumarthi
   Date : 27th Oct, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "../linked_list/singly_linked/implementation.c"

typedef struct
{
	int size;
	node* list;
} queue;

// Function prototypes
queue create_empty_queue();
queue enqueue(queue q, int element);
queue deque(queue q);
int size(queue q);
int is_full(queue q);
int is_empty(queue q);

// Function definitions
queue create_empty_queue()
{
	queue q;
	q.size = 0;
	q.list = NULL;
	return q;
}

queue enqueue(queue q, int element)
{
	q.size++;
	q.list = insert_at_begin(q.list, element);
	return q;
}

queue dequeue(queue q)
{
	q.size--;
	q.list = delete_at_end(q.list);
	return q;
}

int size(queue q)
{
	return q.size;
}

int is_full(queue q)
{
	return 0;
}

int is_empty(queue q)
{
	return !q.size;
}

