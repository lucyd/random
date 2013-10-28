/*
   Implementation of doubly circularly linked lists
   Author : Sreenatha Bhatlapenumarthi
   Date : Oct 29, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

// Structure definitions
typedef struct
{
	int data;
	node* previous;
	node* next;
} node;

// Function prototypes
// Basic ADT operations
node* create_empty_list();
node* insert_at_begin(node* list, int element);
node* insert_at_end(node* list, int element);
node* delete_at_begin(node* list);
node* delete_at_end(node* list);
node* find(node* list, int element);
int size(node* list);
int size_recursive(node* list);
int size_iterative(node* list);
// Auxiliary operations
void print(node* list);
node* reverse(node* list);
node* find_median(node* list)

// Function definitions
// Returns empty list	
node* create_empty_list()
{
	return NULL;
}

// Inserts element at beginning of list
node* insert_at_begin(node* list, int element)
{
	node* new_node = (node*) malloc(sizeof(node));
	new_node->data = element;
	new_node->previous = NULL;
	new_node->next = list;
	if(list != NULL)
	{
		new_node->previous = list->previous;
		list->previous = new_node;
	}
	return new_node;
}

// Inserts element at end of list
node* insert_at_end(node* list, int element)
{
	node* new_node = (node*) malloc(sizeof(node));
	new_node->data = element;
	new_node->previous = new_node;
	new_node->next = new_node;
	if(list == NULL)
		return new_node;
	else
	{
		new_node->previous = list->previous;
		new_node->next = list;
		list->previous->next = new_node;
	}
	return list;
}

// Deletes element from beginning of list
node* delete_at_begin(node* list)
{
	list->next->previous = list->previous;
	list->previous->next = list->next;
	return list->next;
}

// Deletes element from end of list
node* delete_at_end(node* list)
{
	list->previous->previous->next = list;
	list->previous = list->previous->previous;
	return list;
}

// Returns pointer to an element in list (searches from both sides)
node* find(node* list, int element)
{
	if(list == NULL)
		return NULL;
	node* forward = list;
	node* backward = list->previous;
	node* found_node = NULL;
	while(1)
	{
		if(forward->data == element)
		{
			found_node = forward;
			break;
		}
		else if(backward->data == element)
		{
			found_node = backward;
			break;
		}
		else if(forward->next == backward || forward == backward)
			break;
		else
		{
			forward = forward->next;
			backward = backward->previous;
		}
	}
	return found_node
}

// Returns size of list
int size(node* list)
{
	return size_iterative(list);
}

// Returns size of the list (Uses iteration)
int size_iterative(node* list)
{
	if(list == NULL)
		return 0;
	node* forward = list;
	node* backward = list->previous;
	int count = 0;
	while(1)
	{
		if(forward->next == backward)
		{
			count += 2;
			break;
		}
		else if(forward == backward)
		{
			count+= 1;
			break;
		}
		else
		{
			count += 2;
			forward = forward->next;
			backward = backward->previous;
		}
	}
	return count;
}

// Returns size of list (Uses recursion)
int size_recursive(node* list)
{
	return 1+size_recursive(list->next);
}

// Prints the list linearly
void print(node* list)
{
	node* temp = list;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

// Returns the reverse of the list
node* reverse(node* list)
{
	if(list == NULL)
		return NULL;
	node* temp = list->previous, *temp2 = NULL;
	do
	{
		//Swap temp->previous and temp->next
		temp2 = temp->previous;
		temp->previous = temp->next;
		temp->next = temp2;
		temp = temp->next;
	}
	while(temp!= list->previous)
	return list->previous;	
}

//Finds median of the list
node* find_median(node* list)
{
	if(list == NULL)
		return NULL;
	node *once = list, *twice = list;
	while(1)
	{
		if(twice == list || twice->next == list)
			break;
		else
		{
			once = once->next;
			twice = twice->next->next;
		}
	}
	return once;
}

