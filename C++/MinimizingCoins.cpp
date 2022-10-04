#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
 
int dp[N];
 
int main()
{
	int n,x; cin >> n >> x;
    vector <int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    dp[0] = 0;
 
    for(int i = 1; i<x+1; i++){
        int ans = INT_MAX;
        for(auto k:a){
            if(i>=k){
                if(dp[i-k] != -1){
                ans = min(ans, dp[i-k]+1);
                }
            }
        }
        dp[i] = (ans == INT_MAX? -1:ans);  
    }
 
    cout << dp[x] << "\n";
 
	return 0;
}
