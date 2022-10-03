package codechef_lib;

import java.util.Scanner;

public class CWIREFRAME {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			//For every Testcase
			int n=sc.nextInt();
			int m = sc.nextInt();
			int x = sc.nextInt();
			System.out.println(2*(n+m)*x);
		}

	}

}
//AC