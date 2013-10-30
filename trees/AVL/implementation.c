/*
   Implementation of AVL trees
   Author : Sreenatha Bhatlapenumarthi
   Date : Oct 30, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

// Structure declarations
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node node;

// Function prototypes
node* create_empty_AVL_tree();
node* insert(node* tree, int element);
node* delete(node* tree, int element);
node* find(node* tree, int element);



