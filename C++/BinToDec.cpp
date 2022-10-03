#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans=0; 
    int i=0;
    while(n!=0)
    {
        int bit = n%10;
        n/=10;
        ans = (bit * pow(2,i)) + ans;
        i++;
    }
    cout<< "Answer is " << ans <<endl;
}