//Github username: JPV2207
//Aim: To create a program for printing the Diamond of Stars pattern for odd value of n
//Date: 14/10/2022

#include<iostream>
using namespace std;
int main() {
    
    
    int n;
    cin>>n;
    int n1=(n+1)/2;
    int n2=n/2;
    int i=1;

    // Printing of Upper Half
    while(i<=n1)
    {
        int k=1;
        while(k<=n1-i)
        {
            cout<<" ";
            k++;
        }
        int j=1;
        while(j<=2*i-1)
        {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }

    // Printing of Lower Half
    int i1=n2;
    while(i1>=1)
    {
        int k1=1;
        while(k1<=n2-i1+1)
        {
            cout<<" ";
            k1++;
        }
        int j1=1; 
        while(j1<=2*i1-1)
        {
            cout<<"*";
            j1++;
        }
        cout<<endl;
        i1--;
    }
}

