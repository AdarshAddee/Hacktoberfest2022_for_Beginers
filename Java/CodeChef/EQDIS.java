package codechef_lib;

import java.util.HashSet;
import java.util.Scanner;

public class EQDIS {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			int n = sc.nextInt();
			int cnt_ex=0;
			HashSet<Integer> set = new HashSet<>();
			int arr[] = new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=sc.nextInt();
				if(set.contains(arr[i])) {
					cnt_ex++;
				}
				set.add(arr[i]);
				
			}
			if(set.size()%2==0) {
				System.out.println("YES");
			}else {
				if(cnt_ex>0) {
					System.out.println("YES");
				}else {
					System.out.println("NO");
				}
			}
			
		}

	}

}
//AC