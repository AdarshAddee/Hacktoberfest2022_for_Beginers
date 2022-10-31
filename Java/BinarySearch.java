import java.util.Scanner;
public class BinarySearch{
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.print("Enter the size of array : ");
    int n = in.nextInt();
    int[] arr = new int[n];
    System.out.println("Enter the values : ");
    for (int i = 0; i < n; i++) {
        arr[i] = in.nextInt();
    }
    System.out.println("Enter the value to search");
    int num = in.nextInt();
    int low = 0;
    int high = n - 1;
    int mid = 0;
     while (low <= high) {
        mid = (low + high) / 2; 
       if (arr[mid] == num) { 
          System.out.print("Value is present"); 
          break; 
       } else if (arr[mid] > num) {
          high = mid - 1;
       } else if (num > arr[mid]) {
         low = mid + 1;
       }
   }
  if (low > high) {
      System.out.println("Value is not present in the array ");
   }
 }
}