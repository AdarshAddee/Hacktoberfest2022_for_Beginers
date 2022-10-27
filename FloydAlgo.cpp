#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
int dis[N][N];
//  this algo gives shortest path between any two vertices
// Time Complexity O(N^3)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i==j)
            dis[i][j]=0;
            dis[i][j]=INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dis[x][y]=wt;
    }
    for (int k = 1; k <=n; k++)
    {
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <=n ;j++)
            {
                if(dis[i][k]!=INF && dis[k][j]!=INF) // for negative weighted edges
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
            
        }
        
    }
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=n; j++)
        {
            if(dis[i][j]==INF)
            cout<<"I"<<" ";
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}
