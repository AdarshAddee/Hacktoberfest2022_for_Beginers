#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct edge{
    int a;
    int b;
    int w;
};
edge arr[100];
int par[100];
bool comp(edge a,edge b){
    if(a.w<b.w)
        return true;
    return false;
}
int find1(int a){
    if(par[a]==-1){
        return a;
    }
    return par[a]=find1(par[a]);
}
int merge1(int a,int b){
    par[a]=b;
}
int main()
{
    int n,m,s,b,a,i,w;
    cout<<"Now enter no. of elements:";
    cin>>m;
    cout<<"Enter the number of links between 1 to n(node1, node2, weight):";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].w;
    }
    for(i=0;i<m;i++){
        par[i]=-1;
    }
    sort(arr,arr+n,comp);

    int sum=0;
    for(i=0;i<n;i++){
        a=find1(arr[i].a);
        b=find1(arr[i].b);
        if(a!=b){
            cout<<arr[i].a<<"->"<<arr[i].b<<endl;
            sum+=arr[i].w;
            merge1(a,b);
        }
    }
    cout<<"Minimum total weight of MST is:"<<sum<<endl;
    return 0;
}

/*
Now enter no. of elements:4
Enter the number of links between 1 to n(node1, node2, weight):5
0 1 10
1 3 15
2 3 4
2 0 6
0 3 5
2->3
0->3
0->1
Minimum total weight of MST is:19
*/
