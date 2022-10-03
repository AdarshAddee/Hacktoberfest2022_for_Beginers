#include<bits/stdc++.h>
using namespace std;

int josephus(int, int);

int main()
{
    int n, k;
    cout<<"Enter the number of people: ";
    cin>>n;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"The last person remaining is "<<josephus(n, k)<<endl;
    return 0;
}

int josephus(int n, int k)
{
    if(n==1)
        return 0;
    return (josephus(n-1, k) + k)%n;
}