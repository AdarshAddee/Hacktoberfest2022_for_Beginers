// Github username: Vidip-Ghosh
// Aim: Printing Pattern
// Date: 16th October 2022

// start coding
#include<iostream>
using namespace std;

void printPattern(int n)
{
    int row=1,count=1;
    while(row<=n)
    {
        int col=1;
        while(col<=row)
        {
            cout<<count<<" ";
            count++;
            col++;
        }
        cout<<endl;
        row++;
    }
}

int main()
{
    int n;
    cin>>n;
    printPattern(n);
}
/* Output Example: 
4   Put n=4
1 
2 3 
4 5 6 
7 8 9 10 

*/