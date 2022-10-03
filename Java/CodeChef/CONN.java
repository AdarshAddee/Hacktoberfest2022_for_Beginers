package codechef_lib;

import java.util.Scanner;

public class CONN {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			if(n%2==0) {
				System.out.println("YES");
			}else {
				if((n-7)%2==0 && n-7>=0) {
					System.out.println("YES");
				}else {
					System.out.println("NO");
				}
			}
		}

	}

}
//AC