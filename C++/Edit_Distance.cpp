// Github username: sayskar500
// Aim: Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// Date: 04/10/2023

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

ll fnd(string a,string b,ll i,ll j,ll n, ll m, vector<vector<ll>>& dp){
  if(i==n and j==m) return 0;
  if(i==n) return m-j;
  if(j==m) return n-i;
  if(dp[i][j]!=-1) return dp[i][j];
  if(a[i]==b[j]) return dp[i][j]=fnd(a,b,i+1,j+1,n,m,dp);
  ll x=INT_MAX,y=INT_MAX,z=INT_MAX;
  x=fnd(a,b,i,j+1,n,m,dp);
  y=fnd(a,b,i+1,j,n,m,dp);
  z=fnd(a,b,i+1,j+1,n,m,dp);
  ll o=min({x,y,z});
  return dp[i][j]=1+min((ll)INT_MAX,o);
}

void solve() {
  string a,b;
  cin>>a>>b;
  ll n=a.length(),m=b.length();
  vector<vector<ll>> dp(n,vector<ll>(m,-1));
  cout<<fnd(a,b,0,0,n,m,dp)<<endl;
}

int main() {
  fastio();
  solve();
}
