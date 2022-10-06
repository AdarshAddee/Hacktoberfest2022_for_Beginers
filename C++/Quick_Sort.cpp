#include<bits/stdc++.h>
using namespace std;

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
int parti(int arr[],int low,int high)  //pivot as middle element
{
        int mid =(low+high)/2;
        int pivot=arr[mid];
        int start=low;
        int end=high; 
        while (start<=end)
        {
                while(arr[start]<pivot)
                {
                        start++;;
                }
                while(arr[end]>pivot)
                {
                        end--;
                }
                if(start<=end)
                {
                        swap(arr[start],arr[end]);
                        start++;
                        end--;
                }
        }

        return start;
}
void quick(int arr[] , int low,int high)
{
       if(low<high)
        {
                int part=parti(arr,low,high);
                quick(arr,low,part-1);
                quick(arr,part,high);
        }
        
}
int main()
{
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   quick(arr, 0, n-1);     //(n-1) for last index
   cout << "Array after Sorting: ";
   display(arr, n);
    return 0;
}