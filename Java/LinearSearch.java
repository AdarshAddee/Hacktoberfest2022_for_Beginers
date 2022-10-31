import java.util.Scanner;
public class LinearSearch
{
   public static void main(String[] args)
   {
      int i, num, pos=0;
      Scanner s = new Scanner(System.in);
      System.out.print("Enter the size of the array : ");
      int n = s.nextInt();
      int[] arr = new int[n];
      System.out.print("Enter the Values: ");
      for(i=0; i<n; i++)
         arr[i] = s.nextInt();
      
      System.out.print("Enter the value to Search: ");
      num = s.nextInt();
      
      for(i=0; i<10; i++)
      {
         if(num==arr[i])
         {
            pos = i+1;
            break;
         }
      }
      if(pos==0)
         System.out.println("\nThe value is not found!");
      else
         System.out.println("\nThe element is found at position: " +pos);
   }
}