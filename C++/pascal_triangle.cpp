#include <iostream>
using namespace std;
int fact(int n)
{
    int factorial = 1;
    for(int i=2; i<=n; i++)
    {
        factorial*=i;
    }
    return factorial;
}
int comb(int n, int r)
{
    int val;
    val = fact(n)/(fact(n-r)* fact(r));
    return val;
}
int main()
{
    /*
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
    */
//    here we can take i=n and j=r
   int n;
   cout<<"Enter number of rows: ";
   cin>>n;
   for(int i=0; i<n; i++)
   {
    for(int j=0; j<=i; j++)
    {
        cout<<comb(i, j);
    }
    cout<<"\n";
   }
   return 0;
}