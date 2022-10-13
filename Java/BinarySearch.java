
// Github username: pandeyjii11
// Aim: Added Binary Search alogorithm in the Java folder, an very Important Algorithm 
// Date: 13th October, 2022

import java.util.*;
class BinarySearch
{
    static int binarySearch(int[] arr, int n)
    {
        int low=0, high=arr.length-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==n)
                return mid;
            else if(arr[mid]>n)
                high=mid-1;
            else 
                low=mid+1;
        }
        return-1;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int size=sc.nextInt();
        System.out.println("Enter the Array Elments");
        int[] arr=new int[size];
        for(int i=0;i<size;i++)
        {
            arr[i]=sc.nextInt();
        }
        System.out.println("Enter the elements to be searched");
        int n=sc.nextInt();
        int position = binarySearch(arr, n);
        if(position==-1)
            System.out.println("Element not present in the array");
        else 
            System.out.println("Elemment present at index "+position);
    }
}