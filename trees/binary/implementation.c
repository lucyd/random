/*
   Implementation of binary trees
   Author : Sreenatha Bhatlapenumarthi
   Date : Oct 30, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "../../queues/array_implementation.c"

// Structure declarations
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node node;

// Function prototypes
// ADT operations
node* create_empty_tree();
node* insert(node* parent, int element, char* child);
node* delete(node* parent, char* child);
node* find(node* root, int key);
// Auxiliary functions
void preorder(node* root);
void postorder(node* root);
void inorder(node* root);
void level_order(node* root);

// Function definitions
// Returns an empty tree
node* create_empty_tree()
{
	return NULL;
}

// Inserts the node as child to given parent
node* insert(node* parent, int element, char* child)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = element;
	new_node->left = NULL;
	new_node->right = NULL;
	if(parent == NULL)
		return new_node;
	if(strcmp(child,"left") == 0)
		parent->left = new_node;
	else if(strcmp(child,"right") == 0)
		parent->right = new_node;
	else
	{
		printf("Error: Unknown child identifier %s\n", child);
		exit(1);
	}
	return parent;
}

// Delete child of node
node* delete(node* parent, char* child)
{
	if(parent == NULL)
		return NULL;
	if(strcmp(child,"left") == 0)
		parent->left = NULL;
	else if(strcmp(child,"right") == 0)
		parent->right = NULL;
	else
	{
		printf("Error: Unknown child identifier %s\n", child);
		exit(1);
	}
	return parent;
}

// Returns pointer to node with given key
node* find(node* root, int key)
{
	if(root == NULL)
		return NULL;
	else if(root->data == key)
		return root;
	else if(root->left == NULL && root->right == NULL)
		return NULL;
	node* left_find = find(root->left, key);
	node* right_find = find(root->right, key);
	return (left_find ? left_find : right_find);
}

// Prints the preorder(DLR) traversal of tree
void preorder(node* root)
{
	if(root == NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

// Prints the postorder(LRD) traversal of tree
void postorder(node* root)
{
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

// Prints the inorder(LDR) traversal of tree
void inorder(node* root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

// Prints the level-order traversal of tree
void level_order(node* root)
{
	if(root == NULL)
		return;
	node* temp = NULL;
	queue q = create_empty_queue(20, sizeof(node));
	q = enqueue(q, (void*)root);
	while(!is_empty(q))
	{
		temp = (node*)front(q);
		printf("%d ",temp->data);
		q = dequeue(q);
		if(temp->left)
			q = enqueue(q, (void*)temp->left);
		if(temp->right)
			q = enqueue(q, (void*)temp->right);
	}
	free_queue(q);
}
