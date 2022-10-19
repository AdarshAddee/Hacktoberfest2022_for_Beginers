import java.util.Scanner;

public class quickSort {

    public static void sort(int []arr,int lo,int hi) {
        if(lo >= hi){
            return;
        }
        int pivot = arr[hi];
        int pi = parition(arr, pivot, lo, hi);
        printarr(arr);
        sort(arr, lo, pi - 1);
        sort(arr, pi+1, hi);
    }
    public static int parition(int []arr,int pivot,int lo,int hi) {
        System.out.println("Pivot -> "+ pivot);
        int i = lo;
        int j = lo;
        while(i<=hi){
            if(arr[i] <= pivot){
                swap(arr, i, j);
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        System.out.println("Pivot index -> " + (j-1));
        return (j - 1);
    }
    public static void swap(int[] arr, int i, int j) {
        System.out.println("Swapping " + arr[i] + " and " + arr[j]);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    public static void printarr(int []arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int []arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
        sort(arr, 0, n-1);
        printarr(arr);
        scn.close();
    }
}
