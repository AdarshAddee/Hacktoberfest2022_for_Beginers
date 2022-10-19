import java.util.Scanner;

public class mergetwosortedarry {

    // Merges the two sorted array
    public static int[] mergetwosortedarray(int []a ,int []b) {
        int []res = new int[a.length + b.length];
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<a.length && j < b.length){
            if(a[i] < b[j]){
                res[k] = a[i];
                i++;
                k++;
            }
            else{
                res[k] = b[j];
                j++;
                k++;
            }
        }
        while(i<a.length){
            res[k] = a[i];
            i++;
            k++;
        }
        while(j<b.length){
            res[k] = b[j];
            j++;
            k++;
        }
        return res;
    }
    //Prints the array
    public static void printarr(int []res) {
        for (int i = 0; i < res.length; i++) {
            System.out.print(res[i] + " ");
        }
    }
    //Code starts from here
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n1 = scn.nextInt();
        int []arr1 = new int[n1];
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = scn.nextInt();
        }
        int n2 = scn.nextInt();
        int []arr2 = new int[n2];
        for (int i = 0; i < arr2.length; i++) {
            arr2[i] = scn.nextInt();
        }
        int []res = mergetwosortedarray(arr1, arr2);
        printarr(res);
        scn.close();
    }
}
