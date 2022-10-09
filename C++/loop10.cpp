#include<bits\stdc++.h>
using namespace std;
int abs(int a)
{
    if(a>0)
        return a;
    else
        return -a;
}
int main()
{
    int i,j,n=5;
    // printf("\n enter n ");
    // scanf("%d",&n);
    
    for(i=-n+1;i<n;i++)
    {
        for(int j=0;j<=n-abs(i);j++)
        {
            cout<<"  ";
        }
        for(int j=0;j<=2*abs(i);j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;

   
}
