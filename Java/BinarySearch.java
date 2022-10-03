import java.util.*;
public class BinarySearch{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter size of array:");
        int n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the array elements in sorted order:");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("Enter the element to search:");
        int target=sc.nextInt();
        if(binary(arr,target,0,arr.length-1)){
            System.out.println("Search successful");
        }
        else{
            System.out.println("Search unsuccessful");
        }

    }
    static boolean binary(int[] arr, int target,int start, int end){
        int mid=start+(end-start)/2;
        while(start<=end){
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]>target){
                return binary(arr, target, start, mid-1);
            }
            else{
                return binary(arr, target, mid+1, end);
            }
        }
        return false;
    }
}