package codechef_lib;

import java.util.HashMap;
import java.util.Scanner;

public class EQPAIR {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			//For every Testcase
			int n=sc.nextInt();
			long ans=0;
			//Arr
			int arr[] = new int[n];
			HashMap<Integer,Long> map = new HashMap<>();
			for(int i=0;i<n;i++) {
				arr[i]=sc.nextInt();
				long val=map.getOrDefault(arr[i], (long)0);
				val++;
				
				map.put(arr[i], val);
			}
			for(Integer e:map.keySet()) {
				long cnt=map.get(e);
				if(cnt>1) {
					ans+=(long)cnt*(cnt-1)/2;
				}
			}
			System.out.println(ans);
		}
		

	}

}
//AC