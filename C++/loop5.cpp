#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    /*
    
    */
    int n;
    char c='E';

    //cout<<"Enter n : ";
    //cin>>n;
    n=5;
    
    for(int i=1;i<=n;i++)
    {   c='E';
        for(int j=1;j<=i;j++)
        {

            cout<<char(c-i+j);
            
            
        }
        cout<<endl;
        
        
    }
    return 0;
}