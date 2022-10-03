
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define tej() ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

int main()

{
    /*



    */

    tej();
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {

        int j=1;
        while(j<=n-i+1)
        {
            cout<<j<<" ";
            j++;
        }

        int k=1;
        while(k<=2*i-2)
        {
            cout<<"*"<<" ";
            k++;
        }

        int z=n-i+1;
        while(z>=1)
        {
            cout<<z<<" ";
            z--;
        }


        cout<<endl;
        i++;

    }


    return 0;


}
