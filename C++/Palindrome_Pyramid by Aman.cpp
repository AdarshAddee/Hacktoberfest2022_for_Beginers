// Github username: Aman-Singh-Kushwaha
// Aim: Program for Printing Palindrome Number Triangle Pattern
    //           1 
    //         2 1 2 
    //       3 2 1 2 3 
    //     4 3 2 1 2 3 4 
    //   5 4 3 2 1 2 3 4 5 
    // 6 5 4 3 2 1 2 3 4 5 6 

//Date of Coding: 10/10/2022

#include<iostream>
using namespace std ;


int main()
{
    int n;
    cout<<"Enter your no. : "; cin>>n;

    for (int i = 1; i <=n ; i++)
    {
        for (int j = n - i; j >= 1; j--)
        {
            cout<<"  ";
        }
        for (int k = i; k >= 1; k--)
        {
            cout<<k<<" ";
        }
        for (int k = 2; k <= i; k++)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}