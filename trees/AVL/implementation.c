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
	int height;
	struct node* left;
	struct node* right;
};

typedef struct node node;

// Function prototypes
// ADT operations
node* create_empty_AVL_tree();
node* insert(node* root, int element);
node* delete(node* root, int element);
node* find(node* root, int element);
// Auxiliary functions
node* single_rotate_left(node* root);
node* single_rotate_right(node* root);
node* double_rotate_left(node* root);
node* double_rotate_right(node* root)
node* balance(node* root, int element);
int get_min(node* root);
int max(int A, int B);
int height(node* root);
void free_tree(node* root);

// Function definitions
// Returns an empty AVL tree
node* create_empty_AVL_tree()
{
	return NULL;
}

// Inserts an element into AVL tree
node* insert(node* root, int element)
{
	if(root == NULL)
	{
		node* new_node = (node*)malloc(sizeof(node));
		if(!new_node)
		{
			printf("Error: Cannot allocate memory for new node %d\n", element);
			exit(1);
		}
		new_node->data = element;
		new_node->height = 0;
		new_node->left = NULL;
		new_node->right = NULL;
		return new_node;
	}
	else if(root->data >= element)
		root->left = insert(root->left, element);
	else if(root->data < element)
		root->right = insert(root->right, element);
	root = balance(root, element);
	return root;
}

// Deletes a node with given key from AVL tree
node* delete(node* root, int element)
{
	if(root == NULL)
		return NULL;
	else if(root->data > element)
		root->left = delete(root->left, element);
	else if(root->data < element)
		root->right = delete(root->right, element);
	else if(root->data == element)
	{
		if(root->left == NULL)
			root = root->right;
		else if(root->right == NULL)
			root = root->left;
		else
		{
			root->data = get_min(root->left);
			root->left = delete(root->left, root->data);
		}
	}
	root = balance(root, element);
	return root;
}

// Returns pointer to a node with given key
node* find(node* root, int element)
{
	if(root == NULL)
		return NULL;
	else if(root->data == element)
		return root;
	else if(root->data < element)
		return find(root->right, element);
	else if(root->data > element)
		return find(root->left, element);
}

// Performs a single rotation with left
node* single_rotate_left(node* root)
{
	if(root == NULL || root->right == NULL)
		return root;
	node* right = NULL;
	right = root->right;
	root->right = right->left;
	right->left = root;
	root->height = 1 + max(height(root->left), height(root->right));
	right->height = 1 + max(height(right->left), height(right->right));
	return right;
}

// Performs a single rotation with right
node* single_rotate_right(node* root)
{
	if(root == NULL || root->left == NULL)
		return root;
	node* left = NULL;
	left = root->left;
	root->left = left->right;
	left->right = root;
	root->height = 1 + max(height(root->left), height(root->right));
	left->height = 1 + max(height(left->left), height(left->right));
	return left;
}

// Performs a double rotation with left
node* double_rotate_left(node* root)
{
	if(root == NULL || root->left == NULL || root->left->right == NULL)
		return root;
	node* left = NULL, left_right = NULL;
	left = root->left;
	left_right = left->right;
	root->left = left_right->right;
	left->right = left_right->left;
	left_right->left = left;
	left_right->right = root;
	root->height = 1 + max(height(root->left), height(root->right));
	left->height = 1 + max(height(left->left), height(left->right));
	left_right->height = 1 + max(height(left_right->left), height(left_right->right));
	return left_right;
}

// Performs a double rotation with right
node* double_rotate_right(node* root)
{
	if(root == NULL || root->right == NULL || root->right->left == NULL)
		return root;
	node* right = NULL, right_left = NULL;
	right = root->right;
	right_left = right->left;
	root->right = right_left->left;
	right->left = right_left->right;
	right_left->right = right;
	right_left->left = root;
	root->height = 1 + max(height(root->left), height(root->right));
	right->height = 1 + max(height(right->left), height(right->right));
	right_left->height = 1 + max(height(right_left->left), height(right_left->right));
	return right_left;
}

// Returns the balanced AVL tree after appropriate rotation(s)
// (To be called after insertion of element into AVL tree)
node* balance(node* root, int element)
{
	if(root == NULL)
		return root;
	int left_height = 0, right_height = 0;
	left_height = height(root->left);
	right_height = height(root->right);
	if(left_height - right_height >= 2)
	{
		if(root->left->data > element)
			root = single_rotate_left(root);
		else
			root = double_rotate_left(root);
	}
	else if(right_height - left_height >= 2)
	{
		if(root->right->data < element)
			root = single_rotate_right(root);
		else
			root = double_rotate_right(root);
	}
	return root;
}

// Returns the minimum element of the AVL tree
int get_min(node* root)
{
	if(root == NULL)
		return INT_MAX;
	else if(root->left == NULL)
		return root->data;
	else
		return get_min(root->left);
}

// Returns the maximum of two integers
int max(int A, int B)
{
	return (A>=B ? A : B);
}

// Returns height of the AVL tree
int height(node* root)
{
	if(root == NULL)
		return 0;
	return root->height;
}

// Frees the memory occupied by tree
void free_tree(node* root)
{
	if(root == NULL)
		return;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
	return;
}

