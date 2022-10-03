package codechef_lib;

import java.util.Scanner;

public class ABOVEAVG {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n =sc.nextInt();int m = sc.nextInt();int x = sc.nextInt();
			int sigma=n*x;
			if(x!=m) {
				System.out.println(sigma/(x+1));
			}else {
				System.out.println(0);
			}
				
		}

	}

}
//Accepted