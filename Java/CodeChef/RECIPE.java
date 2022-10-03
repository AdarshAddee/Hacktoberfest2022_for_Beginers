package codechef_lib;
import java.util.Scanner;

public class RECIPE {

	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			long arr[] = new long[n];
			for(int k=0;k<n;k++) {
				arr[k] = sc.nextLong();
			}
			long Gcd = arr[0];
		    
		    for(int p=0;p<n;p++){
		    Gcd=gcd(Gcd,arr[p]);
		    }
			
			
			for(int f=0;f<n;f++) {
				System.out.print((long)(arr[f]/Gcd)+" ");
			}
			System.out.println();
			
		}
	}
	
	
	public static long gcd(long a,long b) {
        if(b==0)
        return a;
        else
        return gcd(b, a%b);
    
	}

}
