/*
   A program to find the transpose of a matrix
Author: Sreenatha Bhatlapenumarthi
Date: Aug 22, 2013
*/

#include<stdio.h>
#include<stdlib.h>

int** transpose(int**, int, int);
void print_matrix(int**, int, int);

int main()
{
	int rows=0, cols=0, i=0, j=0, **matrix, **transpose_matrix;
	printf("Rows: ");
	scanf("%d", &rows);
	printf("Columns: ");
	scanf("%d", &cols);
	matrix = (int**) malloc(sizeof(int*)*rows);
	for(i=0; i<rows; i++)
	{
		matrix[i] = (int*) malloc(sizeof(int)*cols);
		for(j=0; j<cols; j++)
			scanf("%d", &matrix[i][j]);
	}
	transpose_matrix = transpose(matrix, rows, cols);
	print_matrix(transpose_matrix, cols, rows);
	return 0;
}

// Returns the transpose matrix
int** transpose(int** matrix, int rows, int cols)
{
	int i=0, j=0, **transpose_matrix;
	transpose_matrix = (int**) malloc(sizeof(int*)*cols);
	for(i=0; i<cols; i++)
	{
		transpose_matrix[i] = (int*) malloc(sizeof(int)*rows);
		for(j=0; j<rows; j++)
			transpose_matrix[i][j] = matrix[j][i];
	}
	return transpose_matrix;
}

// Prints the matrix
void print_matrix(int** matrix, int rows, int cols)
{
	int i=0, j=0;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}
