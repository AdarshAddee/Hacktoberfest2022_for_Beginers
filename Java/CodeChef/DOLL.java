package codechef_lib;

import java.util.Arrays;
import java.util.Scanner;

public class DOLL {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			long n = sc.nextLong();
			long k = sc.nextLong();
			long arr[] = new long[(int)n];
			for (int f=0;f<n;f++) {
				arr[f] = sc.nextLong();
			}
			Arrays.sort(arr);
			int c =0;
			for(int f=0;f<n;f++) {
				if(arr[f]>k) {
					c++;
				}else {
					continue;
				}
			}
			System.out.println(c);
			
		}

	}

}
