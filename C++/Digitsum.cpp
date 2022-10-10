/*
Code for digit sum using recursive function

*/

#include<bits/stdc++.h>
using namespace std;
int digitsum(int n){
    if(n==0) return 0;
    return digitsum(n/10)+n%10;
}
int main(){
    int t;
    /*
    Author : Sonali Rao */
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<digitsum(n);
    }
}
/* 
sonali rao 
*/