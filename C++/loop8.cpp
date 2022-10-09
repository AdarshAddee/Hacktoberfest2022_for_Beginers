#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    /*
    
    */
    int n;
    int k=1,l=1;

    //cout<<"Enter n : ";
    //cin>>n;
    n=5;
    
    for(int i=1;i<=n;i++)
    {   
        for(int j=5;j>=i;j--)
        {
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++)
        {
            cout<<"*";
        }
        

        cout<<endl;
        
        
    }
    return 0;
}