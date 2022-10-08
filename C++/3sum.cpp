//github username : Mishra1999
//Date : 8/10/2022
//Aim :  Hacktoberfest 2022 Participation
#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int arr_size, int sum)
{
    for (int i = 0; i < arr_size - 2; i++)
    {
        for (int j = i + 1; j < arr_size - 1; j++)
        {
            for (int k = j + 1; k < arr_size; k++)
            {
                if (A[i] + A[j] + A[k] == sum)
                {
                    cout << "Triplet is " << A[i] <<
                        ", " << A[j] << ", " << A[k];
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{   int sz;
    cout<<"enter size of array : ";
    cin>>sz;
    int Arr[sz];
    cout<<"enter elements of array"<<endl;
    for(int i=0;i<sz;i++){
        cin>>Arr[i];
    }
    int sum;
    cout<<"enter target sum : ";
    cin>>sum;
    /*int Arr[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    int sz = sizeof(Arr) / sizeof(Arr[0]);*/
    find3Numbers(Arr, sz, sum);
    return 0;
}
