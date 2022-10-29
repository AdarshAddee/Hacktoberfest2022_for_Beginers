#include<iostream>
using namespace std;
void swap(int *a, int *b) // Swapping two values.
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 
int CreatePartition(int a[], int low, int high) // Partitioning the array on the basis of values at high as pivot value.
{
	int pivot, index, i;
	index = low;
	pivot = high;
 
	for(i=low; i < high; i++) // Getting index of pivot.
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}
  
	swap(&a[pivot], &a[index]); // Swapping value at high and at the index obtained.
 
	return index;
}
 
int Partition(int a[], int low, int high, int k) // Implementing Partition.
{
	int pindex;
	if(low < high)
	{
		// Partitioning array using last element as a pivot.
		// Recursively implementing partitioning in the direction to place the pivot at (k-1)th pivot.
		pindex = CreatePartition(a, low, high);
		if(pindex == k-1)
			return k-1;
		else if(pindex > k-1)
			Partition(a, low, pindex-1, k);
		else
			Partition(a, pindex+1, high, k);
	}
}
 
int main()
{
	int n, i, k, kk;
	cout<<"\nEnter the number of data element: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	cout<<"\nEnter the k for the kth smallest element: ";
	cin>>k;
 
	kk = Partition(arr, 0, n-1, k); 
	cout<<"\nThe kth smallest element: "<<arr[kk]; // Printing the result.
	return 0;
}
