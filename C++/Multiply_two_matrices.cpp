#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter dimension of matrix: ";
    cin>>n;
    int elements = n*n;
    int matOne[n][n], matTwo[n][n], matThree[n][n];
    int i, j, k, sum=0;
    cout<<"Enter "<<elements<<" Elements for first Matrix: \n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cin>>matOne[i][j];
    }
    cout<<"\nEnter "<<elements<<" Elements for Second Matrix: \n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cin>>matTwo[i][j];
    }
    // Multiplying two matrices...
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            sum=0;
            for(k=0; k<n; k++)
                sum = sum + (matOne[i][k] * matTwo[k][j]);
            matThree[i][j] = sum;
        }
    }
    cout<<"\nMultiplication Result:\n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout<<matThree[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}