#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    //1
    //2 3
    //3 4 5
    //4 5 6 7
    int n,k;
    cout<<"Enter n : ";
    cin>>n;

    for(int i=1;i<=n;i++)
    {   k=i;
        for(int j=1;j<=i;j++)
        {
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
    }
    return 0;
}