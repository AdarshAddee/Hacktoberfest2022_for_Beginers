// Github Username- Anupeshverma
// Date- 05/09/2022
/*
Bucket Sort Algorithm
--> Create n empty buckets (Or lists).
--> Do following for every array element arr[i].
--> Insert arr[i] into bucket[n*array[i]]
--> Sort individual buckets using insertion sort.
--> Concatenate all sorted buckets.
*/


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


void bucketSort(float arr[], int n)
{
	
	// 1) Create n empty buckets
	vector<float> b[n];

	// 2) Put array elements in different buckets
	for (int i = 0; i < n; i++) {
		int bi = n * arr[i]; 
		b[bi].push_back(arr[i]);
	}

	// 3) Sort individual buckets
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	// 4) Concatenate all buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}


int main()
{
	float arr[]
		= { 0.356, 0.56, 0.856, 0.1584, 0.535, 0.3484 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bucketSort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}