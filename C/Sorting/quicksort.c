#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int partition(int A[],int low,int high)
{
    int pivot=A[low];
    int i=low+1;
    int j=high;
    int temp;
    do
    {
        while(A[i]<=pivot)
        {
            i++;
        }
        while(A[j]>pivot)
        {
            j--;
        }
        if (i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    while(i<j);
        temp=A[low];
        A[low]=A[j];
        A[j]=temp;
        return j;
}
void quicksort(int A[],int low,int high)
{
    int partitionIndex; // Index of pivot after partition
    if(low<high)
    {
        partitionIndex=partition(A,low,high);
        quicksort(A,low,partitionIndex-1);//sort left sub-array
        quicksort(A,partitionIndex+1,high);//sort right sub-array
    }
}
int main()
{
    int A[]={3,5,2,13,12};
    int n=5;
    printArray(A,n);
    quicksort(A,0,n-1);
    printArray(A,n);
    return 0;




}