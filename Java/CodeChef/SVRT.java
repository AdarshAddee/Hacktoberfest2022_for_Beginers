package codechef_lib;

import java.util.Scanner;

public class SVRT {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			int d = (n+k-1)/k;
			int x=0;
			if(n%k==0) {
				x=k;
			}else {
				x=n%k;
			}
			System.out.println(d+" "+x);
		}

	}

}
