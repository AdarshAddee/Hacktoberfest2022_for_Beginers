package codechef_lib;

import java.util.Scanner;

public class AGELIMIT {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			int a = sc.nextInt();
			if(a>=x && y>a) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
		}

	}

}
//AC