/*
Implementation of Binary Search Trees
Author: Sreenatha Bhatlapenumarthi
Date: Sept 19, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// Structure definitions
typdef struct node
{
	int data;
	int count;
	struct node* left;
	struct node* right;
} bst;

// Function declarations
int max(int a, int b);
void print_sorted(bst* tree);
int is_leaf(bst* node);
int max_depth(bst* tree);
bst* create_new_node(int element);
bst* insert(bst* original, int element);
void insert_recursive(bst* original, int element);
void delete(bst* tree, int element);
bst* find(bst* tree, int element);
void level_order_traversal(bst* tree);
bst* mirror(bst* tree);
bst* get_lca(bst* tree, int A, int B);

// Function definitions

// Returns the maximum of two elements
int max(int a, int b)
{
	if(a >= b)
		return a;
	else
		return b;
}

// Prints the elements of binary search tree in a sorted order 
void print_sorted(bst* tree)
{
	if(tree == NULL)
		return;
	print_sorted(tree->left);
	printf("%d ", tree->data);
	print_sorted(tree->right);
}

// Returns 1 if node is a leaf, 0 otherwise
int is_leaf(bst* node)
{
	if(node->left == NULL && node->right == NULL)
		return 1;
	else
		return 0;
}

// Returns the maximum depth of the binary search tree
int max_depth(bst* tree)
{
	if(tree == NULL)
		return 0;
	else
		return 1 + max(max_depth(tree->left), max_depth(tree->right));
}

// Creates new node in the binary search tree
bst* create_new_node(int element)
{
	bst* new_node = (bst*)malloc(sizeof(bst));
	new_node->data = element;
	new_node->count = 1;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

// Non-recursive insertion into binary search tree
bst* insert(bst* original, int element)
{
	bst* new = create_new_node(element);
	if(original == NULL)
		return new;
	bst* temp = original;
	while(temp != NULL)
	{
		if(element > temp->data)
		{
			if(temp->right == NULL)
			{
				temp->right = new;
				break;
			}
			temp = temp->right;
		}
		else if(element < temp->data)
		{
			if(temp->left == NULL)
			{
				temp->left = new;
				break;
			}
			temp = temp->left;
		}
		else
		{
			temp->count ++;
			break;
		}
	}
	return original;
}

// Recursive insertion into binary search tree
void insert_recursive(bst* original, int element)
{
	if(original == NULL)
	{
		bst* new_node = create_new_node(element);
		original = new_node;
		return;
	}
	else
	{
		if(original->data == element)
		{
			original->count ++;
			return;
		}
		else if(original->data > element)
		{
			if(original->left == NULL)
			{
				bst* new_node = create_new_node(element);
				original->left = new_node;
				return;
			}
			insert_recursive(original->left, element);
		}
		else if(original->data < element)
		{
			if(original->right == NULL)
			{
				bst* new_node = create_new_node(element);
				original->right = new_node;
				return;
			}
			insert_recursive(original->right, element);
		}
	}
	return;
}

// Recursively finds an element in the binary search tree
bst* find(bst* tree, int element)
{
	if(tree == NULL)
		return NULL;
	else if(tree->data == element)
		return tree;
	else if(tree->data < element)
		return find(tree->right, element);
	else if(tree->data > element)
		return find(tree->left, element);
}

// Returns the mirror representation of a binary search tree
bst* mirror(bst* tree)
{
	if(tree == NULL)
		return tree;
	bst* mirror_node = create_new_node(tree->data);
	mirror_node->left = mirror(tree->right);
	mirror_node->right = mirror(tree->left);
	return mirror_node;
}
