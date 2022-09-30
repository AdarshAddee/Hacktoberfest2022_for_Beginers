import java.util.*;
import java.io.*;
import java.lang.*;



class GFG 
{ 
	
	

	static int bSearch(int arr[], int n, int x)
	{
		int low = 0, high = n - 1;

		while(low <= high)
		{
		int mid=(low+high)/2;
		if(x>arr[mid]){
		    low=mid+1;
		}
		else if(x<arr[mid]){
		    high=mid-1;
		}
		else{
		    if(arr[mid]==x & mid==n-1){
		        return(mid);
		    }
		    else if(arr[mid]==x & arr[mid]!=arr[mid+1]){
		        return(mid);
		    }
		    else{
		        low=mid+1;
		    }
		}
		}

		return -1;
	}

	public static void main(String args[]) 
    {
        int arr[] = {10,10,10,10,10}, n = 5;

		int x = 10;
    
        System.out.println(bSearch(arr, n, x));
		
    } 

}
