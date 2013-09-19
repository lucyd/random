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


