package codechef_lib;

import java.util.Scanner;

public class SIMPLE_XOR {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			if(l%2==0) {
				System.out.println(l+" "+(l+1)+" "+(l+2)+" "+(l+3));
			}else if(r==l+3) {
				System.out.println(-1);
			}else {
				System.out.println((l+1)+" "+(l+2)+" "+(l+3)+" "+(l+4));
			}
		}

	}
	

}
//AC