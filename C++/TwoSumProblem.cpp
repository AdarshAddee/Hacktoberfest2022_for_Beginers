// Github username: Vanshika-RJIT
// Aim: Added TwoSum Problem Solution
// Date: 19 October 2022

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int A[] = { 1, 4, 45, 6, 10, -8 };
    int sum = 16;
    int arr_size = sizeof(A) / sizeof(A[0]);
    int l, r;
    sort(A, A + arr_size);
    l = 0;
    r = arr_size - 1;
    while (l < r) {
        if (A[l] + A[r] == sum)
        {   cout<<"Pair Found";
             return 1;
           }
        else if (A[l] + A[r] < sum)
            l++;
        else // A[i] + A[j] > sum
            r--;
    }
    cout<<"No Such Pair exists";
    return 0;
}