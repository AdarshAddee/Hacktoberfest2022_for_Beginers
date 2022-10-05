#include<bits/stdc++.h>
using namespace std;

int recFn(int nd, int mask, vector<vector<int>>& dists, vector<vector<int>>& dp){
    int n=dists.size();
    if(mask==pow(2, n)-1){
        return dists[nd][0];
    }
    
    if(dp[nd][mask]!=-1){
        return dp[nd][mask];
    }
    
    int res=INT_MAX, pof2=1;
    for(int i=0; i<n; i++){
        if((nd!=i)&&((mask&pof2)==0)){
            int currRes=dists[nd][i]+recFn(i, mask|pof2, dists, dp);
            res=min(res, currRes);
        }
        pof2*=2;
    }
    
    dp[nd][mask]=res;
    return res;
}

int calculateMinimumCost(vector<vector<int>> dists){
    int n=dists.size();
    vector<vector<int>> dp(n, vector<int>(pow(2, n), -1));
    return recFn(0, 1, dists, dp);
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
    
		int ans = calculateMinimumCost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
