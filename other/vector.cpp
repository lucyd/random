#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void print_vector(vector<int> my_vector)
{
	cout << "Elements of Vector are : ";
	for(vector<int>::iterator it = my_vector.begin(); it!=my_vector.end(); it++)
		cout << *it << " ";
	printf("\n");
}

int main()
{
	vector<int> my_vector;
	int i=0, element=0, elements=0;
	printf("Size of Vector : ");
	scanf("%d",&elements);
	for(i=0; i<elements; i++)
	{
		scanf("%d", &element);
		my_vector.push_back(element);
	}
	cout << "Size of Vector : " << my_vector.size() << endl;
	cout << "Capacity of Vector : " << my_vector.capacity() << endl;
	print_vector(my_vector);
	sort(my_vector.begin(), my_vector.end());
	cout << "------Vector sorted--------" << endl;
	print_vector(my_vector);
	cout << "Enter index of element to delete : ";
	cin >> element;
	my_vector.erase(my_vector.begin()+element);
	print_vector(my_vector);
	return 0;
}
