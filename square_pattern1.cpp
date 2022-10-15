#include<bits/stdc++.h>
using namespace std;

int main(){
    int i = 1;
    int n = 5; 
    while(i<=5){
        int j=n-i+1;
        while (j<=n)
        {
            cout<<j;
            j++;
        }
        int k = 1;
        while (k<=n-i)
        {
            cout<<"5";
            k++;
        }
        
        cout<< endl;
        i++;
    }

    return 0;
}   
