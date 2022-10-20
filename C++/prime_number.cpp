#include <bits/stdc++.h>

using namespace std;

// Github username: khushpreet-007
// Aim: To check Number is prime or not. Time complexity : (square of n)
// Date: 20/10/2022

int prime_or_not(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    cout << "Enter a number to check it is prime or not: " << endl;
    cin >> n;
    if ((prime_or_not(n)) && (n > 1))
        cout << n << " is prime" << endl;
    else
        cout << n << " is not a prime number" << endl;
}