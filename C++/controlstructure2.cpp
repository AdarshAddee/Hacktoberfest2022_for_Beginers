#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    //find the largest number among the three numbers entered by the user.

    int a, b, c;

    cout << "Enter three numbers ";
    cin >> a >> b >> c;

    (a > c) ? (a > b ? cout << a : cout << b) : (c>b?cout<<c:cout<<b);
    
    cout<<" is largest number.";
    return 0;
}