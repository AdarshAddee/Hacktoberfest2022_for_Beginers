package codechef_lib;

import java.util.Scanner;

public class CHEFGAMES {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			//For every Testcase
			int r1=sc.nextInt();
			int r2=sc.nextInt();
			int r3=sc.nextInt();
			int r4=sc.nextInt();
			if(r4==0 && r3==r2 && r2==r1) {
				System.out.println("IN");
			}else {
				System.out.println("OUT");
			}
		}

	}

}
//AC