// C++ program to find minimum number of trials in worst
// case.
#include <bits/stdc++.h>
using namespace std;

int minTrials(int n, int k)
{
// Initialize 2D of size (k+1) * (n+1).
vector<vector<int> > dp(k + 1, vector<int>(n + 1, 0));
int m = 0; // Number of moves
while (dp[m][n] < k) {
	m++;
	for (int x = 1; x <= n; x++) {
		dp[m][x] = 1 + dp[m - 1][x - 1] + dp[m - 1][x];
	}
}
return m;
}

/* Driver code*/
int main()
{
cout << minTrials(2, 10);
return 0;
}


