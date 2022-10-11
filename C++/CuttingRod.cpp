// Github username: nickel-28
// Aim: C++ implementation of Cutting Rod Problem
// Date: 11-10-2022

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int cutRod(int price[], int index, int n)
{
	if (index == 0) {
		return n * price[0];
	}
	int notCut = cutRod(price,index - 1,n);
	int cut = INT_MIN;
	int rod_length = index + 1;

	if (rod_length <= n)
		cut = price[index]
			+ cutRod(price,index,n - rod_length);

	return max(notCut, cut);
}

int main()
{
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum Obtainable Value is "
		<< cutRod(arr, size - 1, size);
	getchar();
	return 0;
}
