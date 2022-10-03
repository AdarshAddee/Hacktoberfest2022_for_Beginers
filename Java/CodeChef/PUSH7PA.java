package codechef_lib;

import java.util.Arrays;
import java.util.Scanner;

public class PUSH7PA {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			long arr[] = new long[n];
//			long max=0;int idx=0;
//			for(int j=0;j<n;j++) {
//				arr[j]=sc.nextLong();
//				if(max<arr[j]) {
//					max=arr[j];idx=j;
//				}
//			}
//			int c=0;
//			for(long h:arr) {
//				if(h==max) {
//					c++;
//				}
//			}
//			if(c==1) {
//				System.out.println(max);
//			}else {
//				System.out.println(max+(c-1));
//			}
			for(int j=0;j<n;j++) {
				arr[j]=sc.nextLong();
			}
			Arrays.sort(arr);
			if(n==1) {
				System.out.println(arr[0]);
			}else {
				int max=0;
				int c=0;
				for(int j=n-1;j>=1;j--) {
					if(arr[j]==arr[j-1]) {
						c++;
					}else {
						if(max<arr[j]+c) {
							max=(int) (arr[j]+c);
						}
						c=0;
					}
				}
				System.out.println(max);
			}
			
		}

	}
}
//Accepted