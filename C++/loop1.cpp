#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    //1
    //23
    //345
    //4567
    int n,k;
    cout<<"Enter n : ";
    cin>>n;

    for(int i=1;i<n;i++)
    {   k=i;
        for(int j=1;j<=i;j++)
        {
            cout<<k;
            k++;
        }
        cout<<endl;
    }
    return 0;
}