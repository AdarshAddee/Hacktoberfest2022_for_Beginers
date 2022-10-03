package codechef_lib;

import java.util.Scanner;

public class ALTER {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int a = sc.nextInt();int a_worked=0;
			int b = sc.nextInt();int b_worked=0;
			int p = sc.nextInt();
			int q = sc.nextInt();
			int day = 1;
			boolean dokill=false;
			while(!dokill) {
				if(b_worked<q) {
					if(day%2!=0) {
						b_worked+=b;day++;
					}else {
						break;
					}
				}
				if(a_worked<p ) {
					if(day%2==0) {
						a_worked += a;day++;
					}else {
						break;
					}
				}
				if(a_worked>=p && b_worked>=q) {
					dokill = true;
					break;
				}
					
			}
			if(a_worked==p && b_worked==q ) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
		}

	}

}
