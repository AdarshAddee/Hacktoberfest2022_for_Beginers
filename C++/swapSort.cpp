// CPP program to test whether array
// can be sorted by swapping adjacent
// elements using boolean array
#include <bits/stdc++.h>
using namespace std;

// Return true if array can be
// sorted otherwise false
bool sortedAfterSwap(int A[], int B[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (B[i])
        {
            if (A[i] != i + 1)
                swap(A[i], A[i + 1]);
        }
    }

    // Check if array is sorted or not
    for (int i = 0; i < n; i++)
    {
        if (A[i] != i + 1)
            return false;
    }

    return true;
}

// Driver program to test sortedAfterSwap()
int main()
{
    int n;
    cin >> n;
    int A[n];
    int B[n - 1];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n - 1; i++)
        cin >> B[i];

    if (sortedAfterSwap(A, B, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
