import java.util.Scanner;

public class bubbleSort {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int []arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
        bubblesort(arr);
        printarr(arr);
        scn.close();
    }
    public static void bubblesort(int []arr) {
        for (int itr = 1; itr <= arr.length - 1; itr++) {
            for (int j = 0; j < arr.length - itr; j++) {
                if(isSmaller(arr,j+1,j)){
                    swap(arr,j+1,j);
                }
            }
        }
    }
    public static void swap(int []arr,int i,int j) {
        System.out.println("Swapping " + arr[i] + " with " + arr[j]);
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
    }
    
    public static boolean isSmaller(int []arr,int i,int j) {
        System.out.println("Comparing " + arr[i] + " with " + arr[j]);
        if(arr[i] < arr[j]){
            return true;
        }
        else{
            return false;
        }
    }
    public static void printarr(int []arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
