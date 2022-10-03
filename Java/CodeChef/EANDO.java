package codechef_lib;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class EANDO {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			//int n =sc.nextInt();
//			int arr[] = new int[n];
//			ArrayList<Integer> od = new ArrayList<Integer>();
//			ArrayList<Integer> en = new ArrayList<Integer>();
//			for(int j=0;j<n;j++) {
//				arr[j]=sc.nextInt();
//				if(arr[j]%2==0) {
//					en.add(arr[j]);
//				}else {
//					od.add(arr[j]);
//				}
//			}
//			Collections.sort(od);Collections.sort(en);
//			int s_en=0;int s_od=0;boolean f_en=true;boolean f_od=true;
//			boolean flag=true;
//			for(int j=0;j<od.size();j++) {
//				int st_1=en.get(en.size()-1)-en.get(j);
//				s_en+=st_1;
//				int st_2=od.get(od.size()-1)-od.get(j);
//				s_od+=st_2;
//				if(st_1!=st_2) {
//					flag=false;
//					break;
//				}
//				
//			}
//			if(flag) {
//				System.out.println("YES");
//			}else {
//				System.out.println("NO");
//			}
//			if(s_en==s_od) {
//				System.out.println("YES");
//			}else {
//				if(((int)s_en/en.size())%2==0) {
//					if(((int)s_od/od.size())%2==0) {
//						System.out.println("YES");
//					}else {
//						System.out.println("NO");
//					}
//				}else {
//					System.out.println("NO");
//				}
//			}
			int n = sc.nextInt();
			int arr[] = new int[n];
			long sum=0;
			for(int j=0;j<n;j++) {
				arr[j]=sc.nextInt();
				sum+=arr[j];
			}
			sum-=(n/2);
			if(sum%n==0) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
			
		}
		
	}
	
}
//Accepted editorial solution