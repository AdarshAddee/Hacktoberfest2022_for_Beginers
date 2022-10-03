package codechef_lib;

import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class SUBSEQDIST {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			int n = sc.nextInt();
			HashMap<Long,Long> map = new HashMap<>();
			
			long arr[] = new long[n];
			for(int i=0;i<n;i++) {
				arr[i]=sc.nextLong();
				map.put(arr[i], map.getOrDefault(arr[i],(long) 0)+1);
			}
			long max = Collections.max(map.values());
			int ans=0;
			int val=1;
			while(val<max) {
				val*=2;
				ans++;
			}
			System.out.println(ans);
			
			
		}

	}

}
//AC