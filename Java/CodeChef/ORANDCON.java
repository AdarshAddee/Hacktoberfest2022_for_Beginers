package codechef_lib;

import java.util.Scanner;

public class ORANDCON {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int x = sc.nextInt();
			System.out.println(x+" "+(x^1)+" "+(x^2));
		}

	}

}
