/*
   A program to calculate the determinant of a square matrix
Author: Sreenatha Bhatlapenumarthi
Date: Aug 22, 2013
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int determinant(int**, int);
int sub_determinant(int**, int, int);
void print_matrix(int**, int, int);

int main()
{
	int i=0, j=0, rows=0, **matrix;
	printf("Rows: ");
	scanf("%d", &rows);
	matrix = (int**) malloc(sizeof(int*)*rows);
	for(i=0; i<rows; i++)
	{
		matrix[i] = (int*) malloc(sizeof(int)*rows);
		for(j=0; j<rows; j++)
			scanf("%d", &matrix[i][j]);
	}
	printf("Determinant = %d\n", determinant(matrix, rows));
	return 0;
}

// Returns the determinant of the matrix
int determinant(int** matrix, int rows)
{
	if(rows < 1)
		return 0;
	else if(rows == 1)
		return matrix[0][0];
	int i=0, det=0;
	for(i=0; i<rows; i++)
	{
		det += (pow(-1,i)*matrix[0][i]*sub_determinant(matrix, rows, i));
	}
	return det;
}

// Returns the determinant of the sub-matrix excluding a row and a column
int sub_determinant(int** matrix, int rows, int row)
{
	if(rows == 2)
	{
		if(row == 0)
			return matrix[1][1];
		else if(row == 1)
			return matrix[1][0];
	}
	int i=0, j=0;
	int** sub_matrix = (int**)malloc(sizeof(int*)*(rows-1));
	for(i=0; i<rows; i++)
	{
		sub_matrix[i] = (int*)malloc(sizeof(int)*(rows-1));
		for(j=0; j<rows; j++)
		{
			if(i!=row && j!=row)
				sub_matrix[i][j] = matrix[i][j];
		}
	}
	return determinant(sub_matrix, rows-1);
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
