// Recursive C++ program to sort an array
// using selection sort
#include <iostream>
using namespace std;

// Return minimum index
int minIndex(int a[], int i, int j)
{
	if (i == j)
		return i;

	// Find minimum of remaining elements
	int k = minIndex(a, i + 1, j);

	// Return minimum of current and remaining.
	return (a[i] < a[k])? i : k;
}

// Recursive selection sort. n is size of a[] and index
// is index of starting element.
void recurSelectionSort(int a[], int n, int index = 0)
{
	// Return when starting and size are same
	if (index == n)
	return;

	// calling minimum index function for minimum index
	int k = minIndex(a, index, n-1);

	// Swapping when index and minimum index are not same
	if (k != index)
	swap(a[k], a[index]);

	// Recursively calling selection sort function
	recurSelectionSort(a, n, index + 1);
}

// Driver code
int main()
{
	int arr[] = {3, 1, 5, 2, 7, 0};
	int n = sizeof(arr)/sizeof(arr[0]);

	// Calling function
	recurSelectionSort(arr, n);

	//printing sorted array
	for (int i = 0; i<n ; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
