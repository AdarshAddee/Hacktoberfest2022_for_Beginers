import java.util.Scanner;
import java.util.Arrays;

class Subsets
{
	public static void main(String[] args)
	{
		Scanner x=new Scanner(System.in);
		System.out.println("P. Sriram Bhardwaj");
		System.out.println("Regd.no - 122010308005");
		System.out.println(" ");
		System.out.println("Sum of subsets");
		System.out.println(" ");
		System.out.println("enter the number of elements");
		int n=x.nextInt();

		int[] arr=new int[n];
		for(int i=0;i<n;i++)
		{
			System.out.println("enter element "+i);
			arr[i]=x.nextInt();
		}
		System.out.println("enter the target element");
		int target=x.nextInt();
		System.out.println("the subsets are as following");
		targetSumSubsets(arr,0,"",0,target);

	}


	
	static void targetSumSubsets(int[] arr, int idx, String set, int sos, int target)                  //idx gives the no.of elements visited
	{
		if(idx==arr.length)                                                                          // all elements have been checked
		{
			
			if(sos==target)
			{
				System.out.println(set+".");                                                 
			}
			return;
	}

// dynamic programming.
		targetSumSubsets(arr,idx+1,set+arr[idx]+" , ",sos+arr[idx],target);     // including that vertex(left child)
		targetSumSubsets(arr,idx+1,set,sos,target);                            // skipping that vertex(right child)
	}
}
		
		
