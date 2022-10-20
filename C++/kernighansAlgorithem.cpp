

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt= 0;
    while(n!=0){
        int rmb = n & -n;
        n = n-rmb;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
// 58 => 4
