// Graph - Using DFS to find no of components of it and  
// find # of (x, y), such that connecting x & y reduces no of components

// Graph Input
// n - 8, m - 6
// 1 
// 7 6
// 1 2
// 2 3
// 2 4
// 3 4
// 5 6
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'// 6 7

vector<vector<int>> g;

vector<int> visited;
int cnt;
void dfs(int node){
    visited[node] = 1;
    cnt++;
    for(auto x : g[node]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n+1);  
    visited.assign(n+1,0);
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> comps;   
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt = 0;
            dfs(i);
            comps.push_back(cnt);
        }
    }
    cout<< "No of components : "<<comps.size()<<endl;
    cout<< "No of such pairs (x, y) : ";
    int prev = 0, sum = 0;
    for(auto v : comps){
        sum = prev*v;
        prev+=v;
    }
    cout << sum << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}