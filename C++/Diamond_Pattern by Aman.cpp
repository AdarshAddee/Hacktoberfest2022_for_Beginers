// Github username: Aman-Singh-Kushwaha
// Aim: Program for Printing Palindrome Number Triangle Pattern
//        *   
//       * *  
//      * * * 
//     * * * *
//    * * * * *
//     * * * *
//      * * *
//       * *
//        *

//Date of Coding: 10/10/2022
#include <iostream>
using namespace std;

int main()
{ 
    int x;
    cout<<"Enter your no.:  ";cin>>x;
    int i = 1;
    while ( i <= x )
    {
        int y = 0;
        while ( y < (x-i) )
        {
            cout<<" ";
            y++;
        }
        int j = 1 ;
        while (  j <= i )
        {
            cout<<"* ";
            j++;
        }
        cout<<endl;
        i++;
    }
    int k = x-1;
    while ( k >= 1  )
    {
        int y = 1;
        while ( y <= x-k )
        {
            cout<<" ";
            y++;
        }
        int j = k ;
        while (  j >=1  )
        {
            cout<<"* ";
            j--;
        }
        cout<<endl;
        k--;
    }
    
    return 0;
}