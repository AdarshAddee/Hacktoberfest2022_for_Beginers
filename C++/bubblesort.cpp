#include <bits/stdc++.h>
using namespace std;
 
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

 
int main()
{   int n;
    cout << "enter the no of int in array : ";
    cin >> n ;
    int arr[n];
    cout << endl << "enter the array : ";
    
    int i;
    for (i = 0; i < n; i++){
        cin >> arr[i];}
    bubbleSort(arr, n);
    cout << endl << "Sorted array: \n";
    
    for (i = 0; i < n; i++){
        cout << arr[i] << " ";}
    cout << endl;
    
    return 0;
}
