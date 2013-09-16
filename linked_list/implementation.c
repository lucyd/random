/*
Implementation of linked lists
Author: Sreenatha Bhatlapenumarthi
Date: 16th Sept, 2013
*/

#include<stdio.h>
#include<stdlib.h>

// Declaration of a node in linked list
struct node
{
	int data;
	struct node* next;
};

typedef struct node node;

// Function declarations
int length(node* list);
node* insert_at_end(node* original, int element);
node* insert_at_begin(node* original, int element);
node* delete_at_end(node* original);
node* delete_at_begin(node* original);
node* append(node* list1, node* list2);
node* find(node* haystack, int needle);
node* reverse(node* list);
void bubble_sort(node* list);

// Function definitions

// Returns the length of list
int length(node* list)
{
	int count = 0;
	while(list != NULL)
	{
		count++;
		list = list->next;
	}
	return count;
}

// Inserts a new node at the end of list
node* insert_at_end(node* original, int element)
{
	node* new = (node*)malloc(sizeof(node));
	new->data = element;
	new->next = NULL;
	if(original == NULL)
	{
		return new;
	}
	node* temp = original;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return original;
}

// Inserts a new node at the beginning of list
node* insert_at_begin(node* original, int element)
{
	node* new = (node*)malloc(sizeof(node));
	new->data = element;
	new->next = original;
	return new;
}

// Deletes the node at the end of list
node* delete_at_end(node* original)
{
	if(original == NULL || original->next == NULL)
		return NULL;
	node* temp = original;
	while(temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	return original;
}

// Deletes the node at the beginning of list
node* delete_at_begin(node* original)
{
	if(original == NULL || original->next == NULL)
		return NULL;
	node* new = original->next;
	free(original);
	return new;
}

// Appends a list to another list
node* append(node* list1, node* list2)
{
	if(list1 == NULL)
		return list2;
	if(list2 == NULL)
		return list1;
	node* temp = list1;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = list2;
	return list1;
}

// Finds needle(element) in haystack(list)
node* find(node* haystack, int needle)
{
	if(haystack == NULL)
		return NULL;
	node *found = NULL, *temp = haystack;
	while(temp != NULL)
	{
		if(temp->data == needle)
		{
			found = temp;
			break;
		}
		temp = temp->next;
	}
	return found;
}

// Reverses a list
node* reverse(node* list)
{
	if(list == NULL || list->next == NULL)
		return list;
	node *previous = list, *current = NULL, *next = NULL;
	current = previous->next;
	previous->next = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	return previous;
}

// Sorts(bubble) a list
void bubble_sort(node* list)
{
	if (list == NULL || list->next == NULL)
		return;
	node* list_copy = NULL;
	int temp = 0;
	while(list->next != NULL)
	{
		list_copy = list->next;
		while(list_copy != NULL)
		{
			if(list_copy->data < list->data)
			{
				// Switch list->data and list_copy->data
				temp = list->data;
				list->data = list_copy->data;
				list_copy->data = temp;
			}
			list_copy = list_copy->next;
		}
		list = list->next;
	}
}
