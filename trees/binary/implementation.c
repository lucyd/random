/*
   Implementation of binary trees
   Author : Sreenatha Bhatlapenumarthi
   Date : Oct 30, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "../../queues/"

// Structure declarations
struct
{
	int data;
	struct node* left;
	struct node* right;
}node;

typedef struct node node;

// Function prototypes
// ADT operations
node* create_empty_tree();
node* insert(node* parent, int element, char* child);
node* delete(node* parent, char* child);
node* find(node* root, int key);
void preorder(node* root);
void postorder(node* root);
void inorder(node* root);
void level_order(node* root);
//Auxiliary functions
void bfs(node* root);
void dfs(node* root);
void extended_bfs(node* root, (void)*func(node*));
void extended_dfs(node* root, (void)*func(node*));


