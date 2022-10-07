#include<bits/stdc++.h>
using namespace std;
int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp){
    if(i==s.size()) return 0;
    if(j==t.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(s[i]==t[j]) ans=1+solve(s,t,i+1,j+1,dp);
    else ans=max(solve(s,t,i+1,j,dp), solve(s,t,i,j+1,dp));
    dp[i][j]=ans;
    return dp[i][j];
}
int longestCommonSubsequence(string text1, string text2) {
    int n=text1.size(), m=text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans=solve(text1,text2,0,0,dp);
    return ans;
}
int main(){
    string s,t;
    cin>>s>>t;
    int ans=longestCommonSubsequence(s,t);
    cout<<ans;
    return 0;
}


