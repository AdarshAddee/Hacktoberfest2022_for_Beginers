import java.util.*;

public class HeapSort {
    public static void main(String[] args) {
        int[] arr = { 7, 30, 20, 35, -15, 69, 24, 1 };
        buildHeap(arr, arr.length);
        heap_Sort(arr, arr.length);
        System.out.println(Arrays.toString(arr));
    }

    static void buildHeap(int[] arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    static void heapify(int[] arr, int n, int i) {

        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // left = 2*i + 1
        int right = 2 * i + 2; // right = 2*i + 2

        // take care of index out of bounds exception
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr, largest, i);
            heapify(arr, n, largest);
        }
    }

    // swapping function
    static void swap(int[] arr, int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

    static void heap_Sort(int[] arr, int n) {
        for (int i = n - 1; i > 0; i--) {
            // in heap first element is always maximum , so swap it with the last index.
            swap(arr, 0, i);
            /*
             * after swapping one element is at its correct position and
             * now make the balanced heap but now reduce the size to n-1
             * coz our last element is already at its position
             */

            // make the balanced heap from first index 0
            heapify(arr, i, 0);
        }
    }
}
