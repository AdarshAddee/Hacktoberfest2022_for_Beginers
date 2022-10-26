//Github username: lakkshyag
//Aim: Creates a number diamond pattern with the singled digit input number at the centre
//Date: 26/10/2022

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int i=1;
    while (i<=n)
    {
        int k=1;
        while (k<=n-i)
        {
            cout<<' ';
            k++;
        }

        int j=1;
        while (j<=i)
        {
            cout<<j;
            j++;
        }

        j-=2;
        while (j>=1)
        {
            cout<<j;
            j--;
        }

        cout<<endl;
        i++;
    }

    i-=2;
    while (i>=1)
    {
        int k=1;
        while (k<=n-i)
        {
            cout<<' ';
            k++;
        }

        int j=1;
        while (j<=i)
        {
            cout<<j;
            j++;
        }

        j-=2;
        while (j>=1)
        {
            cout<<j;
            j--;
        }

        cout<<endl;
        i--;
    }

    return 0;

}