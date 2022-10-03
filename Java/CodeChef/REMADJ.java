package codechef_lib;

import java.util.Scanner;

public class REMADJ {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n =sc.nextInt();
			int arr[] = new int[n];
			for(int d=0;d<n;d++) {
				arr[d]=sc.nextInt();
			}
			if(n%2==0) {
				int sum_arr=0;
				for(int d=0;d<n;d++) {
					sum_arr+=arr[d];
				}
				int req_sum = sum_arr*2/n;
				System.out.println();
			}
		}

	}

}
