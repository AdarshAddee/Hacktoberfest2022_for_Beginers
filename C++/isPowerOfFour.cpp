
// Author: DIVYANSH RAI
// Date Modified: 27/10/2022

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n) {
    // It should be a power of 2 and n-1 should be divisible by 3;
    return (n && !(n & (n - 1)))&&((n-1)%3==0);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << ((isPowerOfFour(n)) ? "It's a power of 4." : "It's not a power of 4.")<<endl; 
    return 0;
}