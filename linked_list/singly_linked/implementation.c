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
node* insert_at_end(node* original, int element);
node* insert_at_begin(node* original, int element);
node* delete_at_end(node* original);
node* delete_at_begin(node* original);
node* append(node* list1, node* list2);
node* find(node* haystack, int needle);
node* reverse(node* list);
node* reverse_recursive(node* list);
node* reverse_iterative(node* list);
node* find_median(node* list);
node* nthfromlast(node* list, int n);
node* split_half(node* list);
node* merge(node* list1, node* list2);
node* merge_sort(node* list);
void selection_sort(node* list);
void print_list(node* list);
void delete_node(node* delete_node);
int check_loop(node* list);
int length(node* list);

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
node* reverse_recursive(node* list)
{
	if(list == NULL || list->next == NULL)
		return list;
	node *temp = NULL, *remaining = NULL;
	temp = list->next;
	remaining = reverse_recursive(temp);
	temp->next = list;
	list->next = NULL;
	return remaining;
}

// Reverses a list
node* reverse_iterative(node* list)
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

// Reverses a list
node* reverse(node* list)
{
	return reverse_iterative(list);
}

// Splits the list into 2 half-lists(same-sized if possible)
node* split_half(node* list)
{
	if(list == NULL || list->next == NULL)
		return list;
	node* temp = NULL, *once = NULL, *twice = NULL;
	once = list;
	twice = list;
	while(twice != NULL && twice->next != NULL)
	{
		once = once->next;
		twice = twice->next->next;
	}
	temp = once->next;
	once->next = NULL;
	return temp;
}

node* merge(node* list1, node* list2)
{
	if(list1 == NULL)
		return list2;
	else if(list2 == NULL)
		return list1;
	else
	{
		int swap_temp = 0;
		node *pointer1 = NULL, *pointer2 = NULL, *temp = NULL;
		pointer1 = list1;
		pointer2 = list2;
		while(pointer1 != NULL)
		{
			if(pointer1->data <= pointer2->data)
				pointer1 = pointer1->next;
			else
			{
				// Swap pointer1->data and pointer2->data
				swap_temp = pointer2->data;
				pointer2->data = pointer1->data;
				pointer1->data = swap_temp;

				// Make pointer2->next point to pointer1->next
				temp = pointer2->next;
				pointer2->next = pointer1->next;

				// Update pointer1->next, pointer2
				pointer1->next = pointer2;
				pointer2 = temp;
				pointer1 = pointer1->next;

			}
		}
		if(pointer2 != NULL)
			pointer1 = pointer2;
		return list1;
	}
}

// Sorts(using Merge sort) a list
node* merge_sort(node* list)
{
	if(list == NULL || list->next == NULL)
		return list;
	node* split = split_half(list);
	return merge(list, split);
}

// Sorts(using Selection sort) a list
void selection_sort(node* list)
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

// Returns 1 if there is a loop in the list, 0 otherwise
int check_loop(node* list)
{
	if(list == NULL || list->next == NULL)
		return 0;
	node *slowPtr, *fastPtr;
	slowPtr = fastPtr = list;
	while(fastPtr != NULL && fastPtr->next != NULL)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr == fastPtr)
			return 1;
	}
	return 0;
}

// Returns pointer to median of the list
node* find_median(node* list)
{
	if(list == NULL || list->next == NULL)
		return list;
	node *slowPtr, *fastPtr;
	slowPtr = fastPtr = list;
	while(fastPtr != NULL && fastPtr->next != NULL)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	return slowPtr;
}

// Returns the nth node from the last of the list
node* nthfromlast(node* list, int n)
{
	//Recursive implementation
	if(list == NULL || n<0)
		return NULL;
	else if(n == 1)
	{
		// Return pointer to last node
		node* last = list;
		while(last->next != NULL)
			last = last->next;
		return last;
	}
	else
	{
		// Return (n-1)th node from last of list->next
		return nthfromlast(list->next, n-1);
	}

#ifdef _USE_ITERATIVE_
	if(list == NULL || n<0)	
		return NULL;
	node *nth-node, *last;
	int count = 0;
	nth-node = last = list;
	while(count < n)
	{
		last = last->next;
		count++;
		if(last == NULL)
			return NULL;
	}
	while(last != NULL)
	{
		nth-node = nth-node->next;
		last = last->next;
	}
	return nth-node;
#endif

}

// Prints the list
void print_list(node* list)
{
	if(list == NULL)
	{
		printf("\n");
		return;
	}
	printf("%d ", list->data);
	print_list(list->next);
}

// Deletes the node at the pointer
void delete_node(node* delete_node)
{
	if(delete_node == NULL)
		return;
	else if(delete_node->next == NULL)
	{
		free(delete_node);
		return;
	}
	else
	{
		node* next_node = delete_node->next;
		delete_node->data = next_node->data;
		delete_node->next = next_node->next;
		free(next_node);
		return;
	}
}



