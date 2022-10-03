package codechef_lib;

import java.util.Arrays;
import java.util.Scanner;

public class SMPAIR {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n =sc.nextInt();
			int arr[] = new int[n];
			for (int k=0;k<n;k++) {
				arr[k] = sc.nextInt();
			}
			Arrays.sort(arr);
			System.out.println(arr[0]+arr[1]);
			
			
			
		}

	}

}
