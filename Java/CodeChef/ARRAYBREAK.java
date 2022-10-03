package codechef_lib;

import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class ARRAYBREAK {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			int n = sc.nextInt();
			long cnt_e=0;
			long cnt_o=0;
			long arr[] = new long[n];
			for(int i=0;i<n;i++) {
				arr[i]=sc.nextLong();
				if(arr[i]%2==0) {
					cnt_e++;
				}else {
					cnt_o++;
				}
			}
			if(cnt_o==0) {
				System.out.println(0);
			}else {
				System.out.println(cnt_e);
			}
			
		}

	}

}
//AC