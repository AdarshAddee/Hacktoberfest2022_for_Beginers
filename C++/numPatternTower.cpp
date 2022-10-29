// Github username: Darkshadow0001boss
// Aim: This program gives you a pattern of numbers when you enter the number.
// Date: 29/10/2022

// start coding
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        // space
        int sp = n - i;
        while (sp > 0)
        {
            cout << " ";
            sp--;
        }

        // nos.
        int j = 1;
        while (j <= i)
        {
            cout << j;
            j++;
        }

        // 2nd nos.
        int m = i - 1;
        while (m > 0)
        {
            cout << m;
            m--;
        }
        cout << endl;
        i++;
    }
    return 0;
}