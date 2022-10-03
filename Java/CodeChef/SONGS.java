package codechef_lib;

import java.util.Scanner;

public class SONGS {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			int x = sc.nextInt();
			int it=n/(x*3);
			System.out.println(it);
		}

	}

}
//AC