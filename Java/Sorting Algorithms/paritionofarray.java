import java.util.Scanner;

public class paritionofarray {

    public static void merge(int []arr,int pivot) {
        
        int i = 0;
        int j = 0;
        while(i < arr.length){
            if(arr[i] > pivot){
                i++;
            }
            else{
                swap(arr, i, j);
                i++;
                j++;
            }
        }
    }
    public static void swap(int []arr,int i,int j) {
        System.out.println("Swapping " + arr[i] + " and " + arr[j]);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static void printarr(int []arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int []arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
        int pivot = scn.nextInt();
        merge(arr, pivot);
        printarr(arr);
        scn.close();
    }
}
