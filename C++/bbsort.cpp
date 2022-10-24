#include <iostream>

using namespace std;

void inp(int arr[], int n)
{
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

void bbsort(int arr[], int n)
{
    for (int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}



int main()
{
    int input;
    cin>>input;
    int arr[input];
    inp(arr,input);
    bbsort(arr,input);
    
    for(int i=0;i<input;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}