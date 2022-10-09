#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    int temp=n;
    while(n>=0)
    {
        
        cout<<n<<" ";
        n=n-5;
    }
    while(n<=temp)
    {
        
        cout<<n<<" "; 
        n=n+5;
    }
     
     
    return 0;
}