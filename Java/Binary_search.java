public class Binary_search {
    public static void main(String[] args) {
        int[] arr={-2,0,1,5,7,12,18,22,24,34};
        int target=18;
        int ans=binarysearch(arr, target);
        System.out.println("target ele. index is=" +  ans);
    }

    static int binarysearch(int[] arr, int target){
        int start=0;
        int end=arr.length-1;

        while(start<=end){
            int mid=start + (end-start) / 2;

            if(target<arr[mid]){
                end=mid-1;
            }
            else if(target>arr[mid]){
                start=mid+1;
            }
            else{
                return mid;
            }

        }

        return -1;

    }
    
}

