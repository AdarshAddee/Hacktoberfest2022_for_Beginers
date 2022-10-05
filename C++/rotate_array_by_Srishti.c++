// Github username: @Srishtihere 
// Aim: I wrote a program in C++ where an array ,which takes user input --- array(arr[]), array-zize(N) and the times(d), to be roated. This will rotate the array by d times.
// Date: 05-10-22


#include<iostream>
#include<stdio.h>
using namespace std;
void Rotate(int arr[], int d, int n)
{
    int temp[n];
    int k = 0;
 
    for (int i = d; i < n; i++) {
        temp[k] = arr[i];
        k++;
    }
 
    for (int i = 0; i < d; i++) {
        temp[k] = arr[i];
        k++;
    }
 
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}
 

void PrintTheArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
 

int main()
{
    int arr[10],N,d;
    cout<<"Enter the size of an array: ";
    cin>>N;
    cout<<"Enter the array items:";
    for(int i=0; i<N;i++)
    {
      cin>>arr[i];
    }
    cout<<"Enter the times to be rotated: ";
    cin>>d;
    Rotate(arr, d, N);
    PrintTheArray(arr, N);
    return 0;
}