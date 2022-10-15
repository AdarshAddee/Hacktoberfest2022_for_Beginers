#include<iostream>
using namespace std;
int main()
/*
5
*** ***
**   **
*     *
**   **
*** ***
*/


// there is assumption that we get only odd no. as input
{
    int n;
    cin>>n;
    int sp=1;
    int st=n/2+1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=st;j++){
            cout<<"*";
        }
        for(int j=1;j<=sp;j++){
            cout<<" ";
        }
        for(int j=1;j<=st;j++){
            cout<<"*";
        }
        if(i<=n/2){
            st--;
            sp+=2;
        }else{
            st++;
            sp-=2;
        }
        cout<<endl;
    }
    return 0;
}