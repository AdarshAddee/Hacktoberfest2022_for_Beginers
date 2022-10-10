import java.util.Arrays;

/**
 * Bubblesort
 */
public class Bubblesort {

    //make bubble sort method
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < (n - i); j++) {
                if (arr[j - 1] > arr[j]) {
                    //swap elements
                    temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    public static void main(String[] args) {
        int[] x = {5,20,2,9,3,1,6};

        System.out.println("Array Before Bubble Sort");
        System.out.println(Arrays.toString(x));
        bubbleSort(x);
        System.out.println("Array After Bubble Sort");
        System.out.println(Arrays.toString(x));

    }
}