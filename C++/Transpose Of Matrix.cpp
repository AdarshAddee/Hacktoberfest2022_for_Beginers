#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Number of rows and coluns: ";
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter value at "<<i<<","<<j<<": ";
            cin>>a[i][j];
        }
    }

    cout<<"Given Matrix: \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j];
            cout<<" ";
        }
        cout<<endl;
    }

    cout<<"Transpose of given Matrix: \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[j][i];
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
