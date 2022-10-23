// Kadane's Algorithm 

/*
Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
*/

import java.util.*;
public class Kadane_Algorithm
{
	public static void main(String[] args) 
	{
	    Scanner sc = new Scanner(System.in);
	    int n=sc.nextInt();
	    int arr[] = new int[n];
	    System.out.println("Enter elements of array:");
	    for(int i=0;i<n;i++)
	    {
	        arr[i] = sc.nextInt();
	    }
	    int csum = arr[0];
        int osum = arr[0];
        
        for(int i=1; i<n; i++)
        {
            if(csum >=0){
                csum = csum +arr[i];
            }
            else
            {
                csum = arr[i];
            }
            if(csum>osum)
            {
                osum = csum;
            }
        }
        System.out.print(osum);
	}
}
