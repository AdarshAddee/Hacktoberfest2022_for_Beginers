// Github username: Tiwari-Niket
// Aim: Binary Search
// Date: 22-10-2022

// start coding
class binarySearch{
    public static int binarySearch(int number[], int key){
        int start = 0, end = number.length-1;

        while(start<=end){
            int mid = (end + start)/2;
            if(key == number[mid]){
                return mid;
            }
            else if( key < number[mid]){
                end = mid -1;
            }
            else{
                start = mid+1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int number[] = {1, 12, 27, 37, 63, 72, 91};
        int key =63;

        System.out.println("Largest number in array is :" + binarySearch(number, key));
    }
}
