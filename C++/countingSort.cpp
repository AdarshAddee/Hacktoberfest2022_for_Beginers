// C++ Program for counting sort
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define RANGE 255


void printArray(char arr[]){
    for(int i = 0; i<strlen(arr); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
// The main function that sort
// the given string arr[] in
// alphabetical order
void countSort(char arr[])
{
	// The output character array
	// that will have sorted arr
	char output[strlen(arr)];

	// Create a count array to store count of individual
	// characters and initialize count array as 0
	int count[RANGE + 1], i;
	memset(count, 0, sizeof(count));

	// Store count of each character
	for (i = 0; arr[i]; ++i)
		++count[arr[i]];

	// Change count[i] so that count[i] now contains actual
	// position of this character in output array
	for (i = 1; i <= RANGE; ++i)
		count[i] += count[i - 1];



	// Build the output character array
    //we iterate over array and find the position from count array and place it in output array.
	for (i = 0; arr[i]; ++i) {
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
        // printArray(output);
	}

	/*
	For Stable algorithm
	for (i = sizeof(arr)-1; i>=0; --i)
	{
		output[count[arr[i]]-1] = arr[i];
		--count[arr[i]];
	}
	
	For Logic : See implementation
	*/

	// Copy the output array to arr, so that arr now
	// contains sorted characters
	for (i = 0; arr[i]; ++i)
		arr[i] = output[i];
}

// Driver code
int main()
{
	char arr[] = "geeksforgeeks";

	countSort(arr);

	cout << "Sorted character array is " << arr;
	return 0;
}

// This code is contributed by rathbhupendra



/*

// Counting sort which takes negative numbers as well
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
void countSort(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
 
    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
 
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
 
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
 
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}
 
void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}
 
int main()
{
    vector<int> arr = { -5, -10, 0, -3, 8, 5, -1, 10 };
    countSort(arr);
    printArray(arr);
    return 0;
}


*/
