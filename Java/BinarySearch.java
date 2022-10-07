// Github username: gitssz

public class Main {
    public static void main(String[] args) {
        int array[]={9,7,6,5,4,3,2,1};
        int result=binarySearch(array,9,true);
        if(result==-1){
            System.out.println("Number not found!");
        }
        else{
            System.out.println("NUmber found!");
        }
    }
    public static int binarySearch(int[] arr, int target,boolean isDesc){
        int start=0;
        int end=arr.length-1;
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            if(!isDesc){
                if(arr[mid]>target ){
                    end=mid-1;
                }
                else if(arr[mid]<target){
                    start=mid+1;
                }
                else{
                    return mid;
                }
            }
            else if(isDesc){
                if(arr[mid]>target){
                    start=mid+1;
                }
                else if(arr[mid]<target){
                    end=mid-1;
                }
                else {
                    return mid;
                }
            }
        }
        return -1;
    }
}
