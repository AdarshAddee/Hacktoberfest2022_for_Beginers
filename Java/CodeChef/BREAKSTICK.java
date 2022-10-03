package codechef_lib;

import java.util.Scanner;

public class BREAKSTICK {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			int x = sc.nextInt();
			if(n%2==0) {
				System.out.println("YES");
			}else {
				if(x%2!=0) {
					System.out.println("YES");
				}else {
					System.out.println("NO");
				}
			}
			
		}

	}

}
//AC