import java.util.Scanner;

public class kthsmallestfindinguisngparition{
    public static int quickSelect(int []arr,int lo,int hi,int k) {
        int pivot = arr[hi];
        int pi = parition(arr,pivot,lo,hi);
        if(k > pi){
            return quickSelect(arr,pi + 1, hi, k);
        }
        else if(k < pi){
            return quickSelect(arr, lo, pi - 1, k);
        }
        else{
            return arr[pi];
        }
    }
    public static int parition(int []arr,int pivot,int lo,int hi) {
        System.out.println("Pivot -> " + pivot);
        int i = lo,j = lo;
        while(i <= hi){
            if(arr[i] > pivot){
                i++;
            }
            else{
                swap(arr,i,j);
                i++;
                j++;
            }
        }
        System.out.println("Pivot Index is: " + (j - 1));
        return (j - 1);
    }
    public static void swap(int []arr,int i,int j) {
        System.out.println("Swapping " + arr[i] + " with " + arr[j]);
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
        int k = scn.nextInt();
        int ans = quickSelect(arr, 0, arr.length - 1, k - 1);
        System.out.println("Answer : " + ans);
        scn.close();
    }
}
