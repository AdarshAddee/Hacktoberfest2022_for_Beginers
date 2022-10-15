// Github username: Jahnvi9044
// Aim: This program is based on sliding Window Algorithm ,so that whosoever sees this can understand proberly
// Date: 15-10-2022

/**
 * This program prints the maximum no. of elements with the given target sum
 * This program demonstrates the Sliding Window Algorithm
 * Enter the array such that a[i]>0 (0>=i<a.length())
 * All the elements of the array should be positive integers
 *
 */
    import java.util.*;
    public class SlidingWindow
    {public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the array size:");
        int n=sc.nextInt();
        System.out.println("Enter the array elements(only positive integers should be entered ):");
        int a[]=new int[n];
        for(int i=0;i<n;i++)
            a[i]=sc.nextInt();
        System.out.println("Enter the target sum:");
        int l=sc.nextInt();
        int i=0,j=0;
        int sum=0;
        int max=0;

        while(j<a.length)
        {sum=sum+a[j];
            if(sum==l)
            {int k=j-i+1;
                if(max<k)
                {max=k;}

                j++;

            }
            else if(sum<l)
            {
                j++; }
            else if(sum>l)
            {   while(sum>l)
            { sum=sum-a[i];
                i++;}
                j++;
            }
        }
       // System.out.println(i+" "+j);
       // System.out.println(sum);
        System.out.println("Max no. of elements in array which make up the sum "+l+" = "+max);
        sc.close();
    }


    }

