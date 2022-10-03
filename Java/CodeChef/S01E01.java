package codechef_lib;

import java.util.Scanner;

public class S01E01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n =sc.nextInt();
			if(n<21) {
				System.out.println("NO");
			}else {
				System.out.println("YES");
			}
		}

	}

}
