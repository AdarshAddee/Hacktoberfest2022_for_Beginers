#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void merge(int A[], int low, int high, int mid)
{
    int i, j, k, B[1000];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            A[i] = B[k];
            i++;
            k++;
        }
        else
        {
            A[j] = B[k];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
    void mergesort(int A[],int low,int high)
    {
        int mid;
        if (low < high)
        {
            mid = (low + high) / 2;
            mergesort(A, low, mid);
            mergesort(A, mid + 1, high);
            merge(A, mid, low, high);
        }
    }
    void main()
    {
        int A[]={9,5,16,8,34,55,4};
        int n=7;
        printf("Array before implementing merge sort : ");
        printArray(A, n);
        mergesort(A, 0, 6);
        printf("Array after implementing merge sort: ");
        printArray(A, n);
    }
