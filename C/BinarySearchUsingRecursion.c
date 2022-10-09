// Github username: HimanshuMohanty-Git24
// Aim: searching an element in a array using Binary Search method using recursion
// Date: 09-10-2022

// start coding
#include <stdio.h>
#include <stdlib.h>
int binarysearch(int a[], int key, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (a[mid] == key)
    {
        return mid;
    }
    if (key > a[mid])
    {
        return binarysearch(a, key, mid + 1, high);
    }
    else
    {
        return binarysearch(a, key, low, mid - 1);
    }
}
int main()
{
    int n, key;
    printf("Enter the number of element:");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the element:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the key:");
    scanf("%d", &key);
    int res;
    res = binarysearch(a, key, 0, n - 1);
    if (res != -1)
    {
        printf("Yes %d is present at %d postion", key, (res + 1));
    }
    else
    {
        printf("%d not found in the array !!", key);
    }
    return 0;
}
