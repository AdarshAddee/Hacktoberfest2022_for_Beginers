// Github username: Vanshika-RJIT
// Aim: Added Solution for 3SumProblem
// Date: 19 October 2022

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
     for (int i = 0; i < arr_size - 2; i++)
    {
 
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++)
        {
            if (s.find(curr_sum - A[j]) != s.end())
            {
                cout<<"Triplet is Found"<<endl;
                return 1;
            }
            s.insert(A[j]);
        }
    }
    cout<<"No Such Triplet Exists"<<endl;
    return 0;
}