// Fibonacci Series in c++
#include <iostream>
using namespace std;
int main()
{
    int n, first = 0, second = 1, sum = 0;
    cout << "enter the number of terms:";
    cin >> n;
    cout << "fibonacci series:";
    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
        {
            sum = i; // to print 0 and 1
        }
        else
        {
            sum = first + second; // to calculate the remaining terms.
            first = second;       // value of first and second changes as new term is printed.
            second = sum;
        }
        cout << sum << " ";
    }
    return 0;
}
