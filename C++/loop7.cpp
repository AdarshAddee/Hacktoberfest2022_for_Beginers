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
        k=i;
        for(int j=1;j<=i;j++)
        {   
            cout<<k;
            k--;
        }
        if(i>1)
        {
            k=2;
            for(int j=1;j<i;j++)
            {
                cout<<k++;
            }
        }
        

        cout<<endl;
        
        
    }
    return 0;
}