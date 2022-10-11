#include<bits/stdc++.h>
using namespace std;

//longest increasing subsequence using O(n^2) dp approach
int LIS_dp(vector<int> &arr) {
	if(arr.empty()) return 0;

	int n = arr.size(), lis = 1;
	vector<int> dp(n,1); // dp[i] -- longest increasing subsequence ending at ith index

	for(int i=1; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(arr[j]<=arr[i]) dp[i] = max(dp[i],1+dp[j]);
		}
		lis = max(lis,dp[i]);
	}

	return lis;
}


//longest increasing subsequence using O(nlogn) dp with binary search approach
int LIS_binary_search(vector<int> &arr) {
	if(arr.empty()) return 0;

	int n = arr.size();
	vector<int> lis;

	lis.push_back(arr[0]);
	for(int i=1; i<n; i++) {
		int low = 0, high = lis.size() - 1, pos = -1;

		while(low<=high) {
			int mid = (low + high)/2;
			if(lis[mid]<=arr[i]) {
				pos = mid;
				low = mid + 1;
			}
			else high = mid - 1;
		}

		if(pos==lis.size()-1) {
			lis.push_back(arr[i]);
		}
		else {
			lis[pos+1] = arr[i];
		}
	}

	return lis.size();
}


int main() {
	vector<int> arr;
	int n;

	cout<<"enter size of array\n";
	cin>>n;

	cout<<"enter array elements\n";
	for(int i=0; i<n; i++) {
		int t;
		cin>>t;
		arr.push_back(t);
	}

	int len = 0;
	if(LIS_dp(arr)==LIS_binary_search(arr)) len = LIS_binary_search(arr);

	cout<<"size of longest increasing subsequence: "<<len<<"\n";
}