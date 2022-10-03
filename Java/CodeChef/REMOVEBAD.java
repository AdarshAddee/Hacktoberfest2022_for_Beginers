package codechef_lib;

import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class REMOVEBAD {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			int n = sc.nextInt();
			HashMap<Integer,Integer> map = new HashMap<>();
			
			int arr[] = new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=sc.nextInt();
				map.put(arr[i], map.getOrDefault(arr[i],0)+1);
			}
			int ma=Collections.max(map.values());
			//System.out.println(ma);
			System.out.println(n-ma);
			
		}
	}

}
//AC