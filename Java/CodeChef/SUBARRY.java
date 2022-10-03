package codechef_lib;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class SUBARRY {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			//For every Testcase
			int n=sc.nextInt();
			long max=Integer.MIN_VALUE;
			long min=Integer.MAX_VALUE;
			//Arr
			long arr[] =new long[n];
			
			for(int i=0;i<n;i++) {
				arr[i]=sc.nextInt();
				if(arr[i]<min) {
					min=arr[i];
				}
				if(arr[i]>max) {
					max=arr[i];
				}
			}
			long ans_min=Math.min(Math.min(max*max, min*min),
					Math.min(max*min, min*min));	
			long ans_max=Math.max(max*max, min*min);
			System.out.println(ans_min+" "+ans_max);
		}
		

	}

}
//AC