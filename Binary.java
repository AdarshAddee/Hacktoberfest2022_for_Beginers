import java.util.Scanner;
import java.time.Duration;
import java.time.Instant;


public class Binary {
    public static int binary_search(int[]A,int target){
        int lo=0;
        int hi=A.length-1;
        
        while(lo<=hi)
{
        int mid=lo+(hi-lo)/2;
        if(A[mid]==target)
        return mid;
        else if(A[mid]<target)
        lo=mid+1;
        else 
        hi=mid-1;
        }
        return -1;
    }
    public static void main(String[] args) {
        long start=System.currentTimeMillis();
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter How Many Elements:");
        int n=sc.nextInt();
        int[]A=new int[n];
        System.out.println("Enter Digits:");
        for(int i=0;i<A.length;i++)
        A[i]=sc.nextInt();
        System.out.println("Enter Target:");
        int target=sc.nextInt();
        System.out.println("element found at position: " +(binary_search(A, target)));
        long end=System.currentTimeMillis();
        System.out.println("  ");
        System.out.println("Total Time take:"+(end-start));
    }
    
}

