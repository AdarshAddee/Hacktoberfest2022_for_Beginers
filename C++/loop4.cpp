#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    /*
    A
    BB
    CCC
    */
    int n;
    char c='A';

    //cout<<"Enter n : ";
    //cin>>n;
    n=5;
    
    for(int i=1;i<=n;i++)
    {   
        for(int j=1;j<=i;j++)
        {
            cout<<c;
            c++;
            
        }
        cout<<endl;
        
        
    }
    return 0;
}