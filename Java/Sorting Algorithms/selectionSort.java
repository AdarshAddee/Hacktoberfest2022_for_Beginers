import java.util.Scanner;

public class selectionSort {

    public static void Selectiont(int []arr) {
        for (int itr = 0; itr < arr.length - 1; itr++) {
            int mi = itr;
            for (int j = itr+1; j < arr.length; j++) {
                if(isSmaller(arr,j,mi)){
                    mi = j;
                }
            }
            swap(arr,itr,mi);
        }
    }
    // Used to swap ith element of the array with jth element
    public static void swap(int []arr,int i,int j) {
        System.out.println("Swapping " + arr[i] + " and " + arr[j]);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    //return true if ith element is smaller than jth element 
    public static boolean isSmaller(int []arr,int i,int j) {
        System.out.println("Comparing " + arr[i] + " and " + arr[j]);
        if(arr[i] < arr[j]){
            return true;
        }
        else{
            return false;
        }

    }

    //prints the array
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
        Selectiont(arr);
        printarr(arr);
        scn.close();
    }
    
}
