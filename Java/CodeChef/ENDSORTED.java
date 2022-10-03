package codechef_lib;

import java.util.ArrayList;
import java.util.Scanner;

public class ENDSORTED {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			ArrayList<Integer> arr = new ArrayList<Integer>();
			for(int j=0;j<n;j++) {
				arr.add(sc.nextInt());
			}
			int idx_1=arr.indexOf(1);
			for(int j=0;j<idx_1;j++) {
				arr.set(idx_1-j,arr.get(idx_1-1-j));				
			}
			arr.set(0, 1);
			int idx_n=arr.indexOf(n);
			int ans=idx_1+n-1-idx_n;
			System.out.println(ans);
		}
		

	}

}
//Ac