package codechef_lib;

import java.util.Scanner;

public class SPEEDTEST {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			//For every Testcase
			float a=(float)sc.nextInt();
			float x = (float) sc.nextInt();
			float b = (float)sc.nextInt();
			float y = (float)sc.nextInt();
			float sp1=a/x;
			float sp2=b/y;
			if(sp1==sp2) {
				System.out.println("EQUAL");
			}else if(sp1>sp2) {
				System.out.println("ALICE");
			}else {
				System.out.println("BOB");
			}
		}

	}

}
//AC