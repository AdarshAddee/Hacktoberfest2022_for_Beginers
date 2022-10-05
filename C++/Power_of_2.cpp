// Author: ADARSH
// Date Modified: 01/10/2022

#include <bits/stdc++.h>
using namespace std;

bool isPowerOf2(int n) {
    return 1073741824%n==0 ? 1:0;
}

int main(int argc, char const *argv[])
{
  
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << ((isPowerOf2(n)) ? "It's a power of 2." : "It's not a power of 2."); 
    return 0;
}
