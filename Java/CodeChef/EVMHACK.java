package codechef_lib;

import java.util.Scanner;

public class EVMHACK {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int p = sc.nextInt();
			int q = sc.nextInt();
			int r = sc.nextInt();
			int half_t = (int)(p+q+r)/2;
			int c_votes = a+b+c;
			int diff_a = p-a;
			int diff_b = q-b;
			int diff_c = r-c;
			c_votes+=Math.max(Math.max(diff_a, diff_b), Math.max(diff_c, diff_b));
			if(c_votes>=half_t) {
				System.out.println("NO");
			}else {
				System.out.println("YES");
			}
					
			
		}

	}

}
