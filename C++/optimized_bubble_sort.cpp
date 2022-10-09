#include<bits/stdc++.h>
using namespace std;

vector<int> optimizedBubbleSort(vector<int> v){
    bool swapped;
    int n= v.size();
    for(int i=0; i<n; i++){
        swapped=false;
        for(int j=0; j<n-i-1; j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                swapped=true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    return v;
    
}
