// Github username: ankitsri98
// Aim: Shortest distance between 2 nodes 
// Date: 07/10/2022

// start coding

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
typedef pair<int, int> pi;
vector<pair<ll,ll > > adj[20];
int dist[20];
void bfs(int x,int n)         //0-1 bfs concept of dijktra's algo.
{
    priority_queue<pair<int,int > > pq;
    pq.push(make_pair(0,x));
    dist[x]=0;
    while(!pq.empty())
    {
        int m=pq.top().second;
        //cout<< m <<" ";
        pq.pop();
        for(int j=0;j<adj[m].size();j++)
        {
           // cout<<dist[adj[m][j].first]<<" --> "<<dist[m]<<" "<<adj[m][j].second<<endl;
            if(dist[adj[m][j].first] > dist[m] + adj[m][j].second )
            {
                dist[adj[m][j].first] = dist[m] + adj[m][j].second ;
               // cout<<"entered "<<dist[adj[m][j].first]<<" --> "<<dist[m]<<" "<<adj[m][j].second<<endl;
                pq.push(make_pair(dist[adj[m][j].first],adj[m][j].first));
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<< i<<"  "<<dist[i]<<endl;
}

int main()
{
    ll n,e,x,y,z;    //n=nodes e=edges
    cin>>n>>e;    //entering no. of node and edges
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y>>z;              //x-->y  edges connection...corresponding z weight
        adj[x].push_back(make_pair(y,z));          //undirected graph
        adj[y].push_back(make_pair(y,z));
    }
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    bfs(0,n);
    return 0;
}
