/*

Problem Input and Output ---------

Star Pattern : It takes input from the user and produces the star pattern accordingly as given below..

For eg :-- 
Inout: 

Enter the value of n: 5
Output:
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*

Enter the value of n: 8
Output:
*
* *
* * *
* * * *
* * * * *
* * * * * *
* * * * * * *
* * * * * * * *
* * * * * * *
* * * * * *
* * * * *
* * * *
* * *
* *
*


*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n ; cout << "Enter the value of n : " ; 
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << "* " ;
        }
        cout << endl ; 
        
    }
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* " ;
        }
        cout << endl ; 
        
    }
    
    return 0;
}