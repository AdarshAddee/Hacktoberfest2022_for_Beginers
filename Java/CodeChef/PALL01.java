package codechef_lib;

import java.util.Scanner;

public class PALL01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n =sc.nextInt();
			int n_copy =n;
			int n_rev=0;
			while(n!=0) {
				int j = n%10;
				n_rev = j+n_rev*10;
				n=n/10;
			}
			if(n_rev == n_copy) {
				System.out.println("wins");
			}else {
				System.out.println("loses");
			}
		}

	}

}
