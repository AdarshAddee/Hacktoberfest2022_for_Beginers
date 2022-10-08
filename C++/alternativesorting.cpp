/*Input : arr[] = {7, 1, 2, 3, 4, 5, 6}
Output : 7 1 6 2 5 3 4

Input : arr[] = {1, 6, 9, 4, 3, 7, 8, 2}
Output : 9 1 8 2 7 3 6 4
*/

#include<bits/stdc++.h>
using namespace std;

void alternatesort(int arr[], int n)
{
    //sorting the array
    sort(arr , arr+n);
    // Printing the last element of array
    // first and then first element and then
    // second last element and then second
    // element and so on.
    int i=0, j=n-1;
    while(i<j){
        cout<<arr[j--]<<" ";
        cout<<arr[i++]<<" ";
    }
     // If the total element in array is odd
    // then print the last middle element.
    if (n % 2 != 0)

    cout<<arr[i];
}

int main()
{
    int arr[] = {1,12,4,6,7,10,11,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    alternatesort(arr,n);
    return 0;
}