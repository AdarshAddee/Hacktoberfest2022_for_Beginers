# Name: Hashir Bin Masood
# Date: 10/29/2022
#

#include <iostream>
using namespace std;

void insertionSort(int arr[], int sizeOfArray)
{
	int i, key, j;
	for (i = 1; i < sizeOfArray; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void Display(int arr[], int sizeOfArray)
{
	int i;
	for (i = 0; i < sizeOfArray; i++)
		cout << arr[i] << " ";
}

int main()
{
	int size = 0;
	cout<<"Enter the size of the array : ";
	cin>>size;
	int arr[size];
	cout<<"Enter the elements of the array : "<<endl;
	for(int i=0; i<size; i++){
		cin>>arr[i];
	}
	cout<<"Array before sorting is: [ ";
	Display(arr, size);
	cout<<" ]\n";
	
	insertionSort(arr, size);
	cout<<"Array after sorting is: [ ";
	Display(arr, size);
	cout<<" ]\n";

	return 0;
}
