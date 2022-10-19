import java.util.Scanner;

public class insertionSort{

// For printing the array
public static void print(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
}

// Main insertion code
public static void insertion(int[] arr) {
    for (int i = 1; i < arr.length; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if(isGreater(arr, j, j + 1)){
                swap(arr, j, j + 1);
            }
            else{
                break;
            }
        }
    }   
}


// return true if jth element is greater than ith element
public static boolean isGreater(int[] arr, int j, int i) {
    System.out.println("Comparing " + arr[i] + " and " + arr[j]);
    if (arr[i] < arr[j]) {
        return true;
    } 
    else {
        return false;
    }
}

// used for swapping ith and jth elements of array
public static void swap(int[] arr, int i, int j) {
    System.out.println("Swapping " + arr[i] + " and " + arr[j]);
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}




    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
          arr[i] = scn.nextInt();
        }
        insertion(arr);
        print(arr);
        scn.close();
    }
}
