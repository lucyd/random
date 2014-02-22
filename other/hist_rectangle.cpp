/*
   http://www.spoj.com/problems/HISTOGRA/
   Find the rectangle with maximum area in a histogram
   Author: Sreenatha Bhatlapenumarthi
   Date: Oct 23, 2013
*/

#include<iostream>
#include<limits.h>

using namespace std;

// Function prototypes
int my_max(int*, int);
int my_max(int, int);
int my_min(int*, int);
int my_min(int, int);
int max_rect(int*, int);
int max_area(int*, int);

// Function definitions
// Returns maximum element of an array
int my_max(int* array, int array_size)
{
	int max = INT_MIN, i =0;
	for(i=0; i<array_size; i++)
	{
		if(max < array[i])
			max = array[i];
	}
	return max;
}

// Returns maximum of two elements
int my_max(int a, int b)
{
	return (a>=b ? a : b);
}

// Returns minimum element of an array
int my_min(int* array, int array_size)
{
	int min = INT_MAX, i =0;
	for(i=0; i<array_size; i++)
	{
		if(min > array[i])
			min = array[i];
	}
	return min;
}

// Returns minimum of two elements
int my_min(int a, int b)
{
	return (a<=b ? a : b);
}

// Returns area of overall-rectangle(encompassing all the rectangles)
int max_rect(int* array, int array_size)
{
	return (my_min(array, array_size) * array_size);
}

// Returns max-area of rectangle in the histogram
int max_area(int* array, int array_size)
{
	int i=0, j=0;
	int current_max = my_max(array, array_size);
	for(i=0; i<array_size; i++)
	{
		for(j=i+1; j<array_size; j++)
		{
			current_max = my_max(current_max, max_rect(array+i, j-i));
		}
	}
	return current_max;
}

