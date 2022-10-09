#include<bits/stdc++.h>
using namespace std;
int abs(int a)
{
    if(a>0)
        return a;
    else
        return -1*a;
}
int main()
{

     int n;
     cin>>n;
     for(int i=1;i<=n;i++)
     {
        for(int j=-i+1;j<i;j++)
            cout<<i-abs(j);

        cout<<"\t";
     }
     
     
    return 0;
}