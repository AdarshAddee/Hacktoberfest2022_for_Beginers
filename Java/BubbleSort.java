import java.util.Scanner;
public class BubbleSort
{
   public static void main(String[] args)
   {
      int i, j, x;
      Scanner s = new Scanner(System.in);
      System.out.print("Enter the size of the array : ");
      int n = s.nextInt();
      int[] array = new int[n];
      System.out.print("Enter the Elements : ");
      for(i=0; i<n; i++)
      {
         array[i] = s.nextInt();
      }
      for(i=0; i<(n-1); i++)
      {
         for(j=0; j<(n-i-1); j++)
         {
            if(array[j]>array[j+1])
            {
               x = array[j];
               array[j] = array[j+1];
               array[j+1] = x;
            }
         }
      }
      System.out.println("The sorted array is:");
      for(i=0; i<n; i++)
         System.out.print(array[i]+ " ");
   }
}