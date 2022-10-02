#include <iostream>
using namespace std;
int main()
{
    int rows, i, j, n;
    cout << "Enter the number of rows: ";
    cin >> rows;
    i = 1;
    while (i <= rows)
    {
        j = 1;
        while (j <= rows - i)
        {
            cout << " ";
            j++;
        }
        n = 1;
        while (n <= ((2 * i) - 1))
        {
            cout << "*";
            n++;
        }
        i++;
        cout << endl;
    }
    return 0;
}