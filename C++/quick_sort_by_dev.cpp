#include <iostream>  
using namespace std;  
  
/* function that consider last element as pivot,  
place the pivot at its exact position, and place  
smaller elements to left of pivot and greater  
elements to right of pivot.  */  

int partition(int a[], int start, int end)  
{  
    int pivot = a[end]; // pivot element  
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  {  
        // If current element is smaller than the pivot  
        if (a[j] < pivot)  {  
            i++; // increment index of smaller element  
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  
  
/* function to implement quick sort */  
void quicksort(int a[], int start, int end) /* a[] = array to be sorted, start = Starting index, end = Ending index */  
{  
    if (start < end)  {  
        int p = partition(a, start, end);  //p is the partitioning index  
        quicksort(a, start, p - 1);  
        quicksort(a, p + 1, end);  
    }  
}  
  
/* function to print an array */  
void printArr(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<< " ";  
}  
int main()  
{  
    int a[15], n;
	cout << "Enter the array size: ";
	cin >> n;
	cout << "Enter the array elements: \n";
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	} 
    cout<<"Before sorting array elements are - \n";  
    printArr(a, n);  
    quicksort(a, 0, n - 1);  
    cout<<"\nAfter sorting array elements are - \n";    
    printArr(a, n);  
      
    return 0;  
}  
