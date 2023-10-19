// Github username: @FarukhS52
// Aim:Java program for implementation of QuickSort
// Date: 19/10/2023

import java.util.Arrays;



public class QuickSort {
 /*
  * This function takes last element as pivot, places the pivot element at
  * its correct position in sorted array, and places all smaller (smaller
  * than pivot) to left of pivot and all greater elements to right of pivot
  */
 private int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1); // index of smaller element
  for (int j = low; j < high; j++) {
   // If current element is smaller than or
   // equal to pivot
   if (arr[j] <= pivot) {
    i++;

    // swap arr[i] and arr[j]
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
   }
  }

  // swap arr[i+1] and arr[high] (or pivot)
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return i + 1;
 }

 /*
  * The main function that implements QuickSort() arr[] --> Array to be
  * sorted, low --> Starting index, high --> Ending index
  */
 private void quickSort(int arr[], int low, int high) {
  if (low < high) {
   /*
    * pi is partitioning index, arr[pi] is now at right place
    */
   int pi = partition(arr, low, high);

   // Recursively sort elements before
   // partition and after partition
   quickSort(arr, low, pi - 1);
   quickSort(arr, pi + 1, high);
  }
 }

 public static void main(String args[]) {
        int arr[] = { 20,10,5,6,2,3,4};
        QuickSort quickSort = new QuickSort();
  System.out.println("Before Sorting an array : " + Arrays.toString(arr));
  quickSort.quickSort(arr, 0, arr.length - 1);
  System.out.println("After Sorting an array : " + Arrays.toString(arr));
 }
}
