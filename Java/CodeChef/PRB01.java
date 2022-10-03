package codechef_lib;

import java.util.Scanner;

public class PRB01 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n =sc.nextInt();
			boolean isprime = true;
			for(int j=2;j<n;j++) {
				if(n%j==0) {
					isprime=false;
					break;
				}
			}
			if(isprime) {
				System.out.println("yes");
			}else if(!isprime) {
				System.out.println("no");
			}
		}	

	}

}
