#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the lines you want to print for the pattern  :  ";
    cin>>n;
    cout<<"The output for "<< 2 *n<<" lines is : "<<endl;
    int j;
    for(int i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            cout<<"*";
        }
        int space = 2*n - 2*i;
        for(j=1 ; j<=space; j++)
        {
            cout<<" ";
        }
        for(j=1; j<=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=n; i>=1; i--)
    {
        for(j=1; j<=i; j++)
        {
            cout<<"*";
        }
        int space = 2*n - 2*i;
        for(j=1 ; j<=space; j++)
        {
            cout<<" ";
        }
        for(j=1; j<=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}
