#include <bits/stdc++.h>
using namespace std;
void creategraph(vector<int>AdjList[],int e){
    int u,v;
    for(int i=0;i<e;i++){
        cout<<"enter u v:";
        cin>>u>>v;
        AdjList[u].push_back(v);
    }
}
void BFS(vector<int>AdjList[],int visited[],int i){
    
    queue<int>qe;
     qe.push(0);
    cout<<0;
    visited[0]=1;
    int x;
    while(!qe.empty()){
        x=qe.front();
        qe.pop();
        for(auto &it:AdjList[x]){
            if(visited[it]==0){qe.push(it);
                cout<<it;
                visited[it]=1;
            }
        }
    }

}
void DFS(vector<int>AdjList[],int visited[],int i){
    if(visited[i]==1)return;
    cout<<i;
    visited[i]=1;
    for(auto &it: AdjList[i]){
        DFS(AdjList,visited,it);
    }
}
void toposortDFS(vector<int>AdjList[],int visited[],int i,stack<int>&st){
    if(visited[i]==1)return;
    visited[i]=1;
    for(auto &it: AdjList[i]){
        toposortDFS(AdjList,visited,it,st);
    }
    st.push(i);
}
void toposortBFS(vector<int>AdjList[],int v){
    vector<int>indegree(v,0);
    
    for(int i=0;i<v;i++){
        for(auto &it: AdjList[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<v;i++){
        cout<<indegree[i]<<" ";
    }
    queue<int>qe;

    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            qe.push(i);
        }
    }
    cout<<endl;
    while(!qe.empty())
    {
        int x=qe.front();
        qe.pop();
        cout<<x<<" ";
        for(auto&it:AdjList[x]){
            indegree[it]--;
            if(indegree[it]==0){
                qe.push(it);
                // cout<<it<<" ";

            }
        }

    }

}
void print_graph(vector<int>AdjList[],int v){
    for(int i=0;i<v;i++){
       cout<<i<<" ";   
        for(auto it:AdjList[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }

}
int main(){
    //graph example 6 6 5 0 5 2 2 3 3 1 4 1 4 0    v e =6 6 then 6 edges
    cout<<"enter v e:";
    int v,e;
    cin>>v>>e;
    vector<int>AdjList[v];//for index start 0 else vector<int>AdjList[v+1]
    creategraph(AdjList,e);
    print_graph(AdjList,v);
    int visited[v]={0};
    for(int i=0;i<v;i++){
        if(visited[i]==0)
        {DFS(AdjList,visited,i);}
    } 
    
    
    stack<int>st;
    for(int i=0;i<v;i++){
        
        if(visited[i]==0)
        {toposortDFS(AdjList,visited,i,st);}
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    toposortBFS(AdjList,v);

    return 0;

    
}
