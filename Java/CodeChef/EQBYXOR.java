package codechef_lib;

import java.util.Scanner;

public class EQBYXOR {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int n = sc.nextInt();
			int z=1;
			while(z<n) {
				z*=2;
			}
			int x = a^b;
			if(x==0) {
				System.out.println(0);
			}else if(x<n) {
				System.out.println(1);
			}else if(x<z) {
				System.out.println(2);
			}else {
				System.out.println(-1);
			}
		}
		

	}

}
//Ac