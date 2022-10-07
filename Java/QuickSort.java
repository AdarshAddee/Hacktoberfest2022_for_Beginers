import java.util.Scanner;
// Other imports go here
// Do NOT change the class name
class Main{
    static void printArray(int array[], int size){
        int i;
        for (i=0; i < size; i++)
            System.out.printf("%d\t", array[i]);
        System.out.printf("\n");
    }

    /* This function takes last element as pivot, and places all smaller
    elements to left of pivot and all greater elements to right of pivot */
    static int partition (int array[], int low, int high){
        int pivot = array[high];    // pivot
        int i = (low - 1);  // Index of smaller element
        int j;

        for (j = low; j <= high- 1; j++)
        {
            if (array[j] <= pivot)
            {
                i++;            // increment index of smaller element
                // shift all lesser elements in left half
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        // place pivot element at end of smaller elements
        int temp = array[i+1];
        array[i+1] = array[high];
        array[high] = temp;
        return (i + 1);    // the index of pivot element
    }

    // Recursive function to sort array with quicksort
    static void quickSort(int array[], int low, int high){
        if (low < high){
            int pivot_index;
            pivot_index = partition(array, low, high);
            System.out.printf("Pivot element is %d \n",array[pivot_index]);
            System.out.printf("Array after pivot partitioning : \n");
            printArray(array,8);

            // Call quicksort() on left half and right half excluding
            // pivot element as it is already at proper position i.e.
            // between lesser and greater elements.
            quickSort(array, low, pivot_index - 1);
            quickSort(array, pivot_index + 1, high);
        }
    }

    public static void main(String[] args){
        int array[] = {17, 13, 20, 16, 19, 24, 22, 21};
        int n = array.length;
        System.out.printf("Given array: \n");
        printArray(array, n);
        quickSort(array, 0, n-1);
        System.out.printf("Sorted array: \n");
        printArray(array, n);
    }
}
