#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 100;
const int MAX_SUM = 1e5;
 
bool dp[MAX_N + 1][MAX_SUM + 1];
 
int main() {
	int n;
	cin >> n;
 
	vector<int> coins_values(n);
	for (int i = 0; i < n; i++) {
		cin >> coins_values[i];
	}
 
	dp[0][0] = true;
 
	for (int i = 1; i <= n; i++) {
		for (int current_sum = 0; current_sum <= MAX_SUM; current_sum++) {
			dp[i][current_sum] = dp[i - 1][current_sum];
			int prev_sum = current_sum - coins_values[i - 1];
			if (prev_sum >= 0 && dp[i - 1][prev_sum]) {
				dp[i][current_sum] = true;
			}
		}
	}
 
	vector<int> possible;
	for (int sum = 1; sum <= MAX_SUM; sum++) {
		if (dp[n][sum]) {
			possible.push_back(sum);
		}
	}
 
	cout << (int)(possible.size()) << endl;
 
	for (int sum : possible) {
		cout << sum << " ";
	}
	cout << endl;
}
