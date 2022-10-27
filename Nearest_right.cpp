#include<bits/stdc++.h>

using namespace std; 

void NGr(vector<int>&arr,int cnt){
    vector<int>v;
    stack<int>s;

    for(int i = cnt - 1; i>=0 ; i--){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top()>arr[i]){
            v.push_back(s.top());
        }
        else if(s.size()>0 && s.top()>=arr[i]){
            while(s.size()>0 && s.top()>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    for(int i = 0 ; i< cnt; i++){
        cout<<v[i]<<" ";
    }

    }

int main(){

   #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
   #endif


    int cnt; 
    cin>>cnt ; 

    vector<int>arr;

    for(int i = 0 ; i< cnt ; i++){

        int a; 
        cin>>a; 
        arr.push_back(a);
    }

NGr(arr,cnt);


    return 0;
}
