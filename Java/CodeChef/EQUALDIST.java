package codechef_lib;

import java.util.Scanner;

public class EQUALDIST {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if((a+b)%2==0) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
		}

	}

}
