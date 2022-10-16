// Github username: Vidip-Ghosh
// Aim: Binary Search
// Date: 16th October 2022

// start coding
public class BinarySearch{
    public static void main(String[] args) {
        int[] arr = {-18,-12,-4,0,2,3,4,15,16,18,22,45,89};
        int target = 18;
        int ans = binarySearch(arr, target);
        System.out.println(ans);
    }
    static int binarySearch(int[] arr,int target)
    {
        int start = 0;
        int end = arr.length - 1;
        while(start<=end){
            //find the middle element
            // int mid = (start+end)/2;    //(start+end) thing exceeds the length of int in java
            int mid = start+(end-start)/2;
            if(target<arr[mid]){
                end = mid-1;
            }
            else if(target>arr[mid]){
                start = mid+1;
            }
            else{
                return mid; //target element == middle element
            }
        }
        return -1;
    }
}
