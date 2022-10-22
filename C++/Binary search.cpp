#include<bits/stdc++.h>
using namespace std;


int findItems(int arr[], int n, int temp)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += (temp/arr[i]);
	return ans;
}

// Binary search to find minimum time required
// to produce M items.
int bs(int arr[], int n, int m, int high)
{
	int low = 1;

	// Doing binary search to find minimum
	// time.
	while (low < high)
	{
		// Finding the middle value.
		int mid = (low+high)>>1;

		// Calculate number of items to
		// be produce in mid sec.
		int itm = findItems(arr, n, mid);

		// If items produce is less than
		// required, set low = mid + 1.
		if (itm < m)
			low = mid+1;

		// Else set high = mid.
		else
			high = mid;
	}

	return high;
}

// Return the minimum time required to
// produce m items with given machine.
int minTime(int arr[], int n, int m)
{
	int maxval = INT_MIN;

	// Finding the maximum time in the array.
	for (int i = 0; i < n; i++)
		maxval = max(maxval, arr[i]);

	return bs(arr, n, m, maxval*m);
}

// Driven Program
int main()
{
	int arr[] = { 1, 2, 3 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int m = 11;

	cout << minTime(arr, n, m) << endl;

	return 0;
}
