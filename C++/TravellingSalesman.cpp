// Github username: Khushi-Shukla
// Aim: encoding and decoding a string by building a huffman tree
// Date: 27/10/22
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

const int N=100;
int dist[N][N];
vector<vector<int>> dp(N, vector<int> (N, -1));

int tsp(int mask, int pos, int visited, int n){
    if(mask==visited){ 
        return dist[pos][0];
    }
    if(dp[mask][pos]!=-1){
        return dp[mask][pos]; 
    }
    int ans=INT_MAX;
    for(int city=0;city<n;city++){
        if((mask&(1<<city))==0){
            int newAns=dist[pos][city] + tsp(mask|(1<<city), city, visited, n);
            ans=min(ans, newAns);
            
        }
    }
     dp[mask][pos]=ans;
    return  ans;
}

int main(){
    int n;
    cout<<"Enter total city: ";
    cin>>n;
    cout<<"Enter distance matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }
    int visited=(1<<n)-1;
    int city;
    cout<<"Enter starting city: ";
    cin>>city;
    int ans=tsp(1, city, visited, n);
    cout<<"The shortest path distance is "<<ans<<endl;

    return 0;
}