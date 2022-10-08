#include <stdio.h>
#include <stdlib.h>

#define SHRINK 1.3 // Set the gap shrink factor
int* comb_sort(int array_nums[], int size)
{
    int gap = size; // Initialize gap size
    while (gap > 1)  // gap = 1 means that the array is sorted
    {
        // Update the gap value for a next comb
		gap = gap / SHRINK;
        int i = 0;
        while ((i + gap) < size)
        {  // similiar to the Shell Sort
            if (array_nums[i] > array_nums[i + gap])
            {
                int tmp = array_nums[i];
                array_nums[i] = array_nums[i + gap];
                array_nums[i + gap] = tmp;
            }
            i++;
        }       
    }
    return array_nums; 
}

int main()
{
    int arr[100], i, n=0;    
	printf("Input number of elements you want to sort: ");
    scanf("%d", &n);
    if ( n >= 1)
    {
	printf("\nInput the numbers:\n");    
    for (i = 0; i < n; i++) scanf(" %d", &arr[i]);
    int* result_arra = comb_sort(arr, n);
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", result_arra[i]);
    }
    printf("\n");
    }
	return 0;
}
