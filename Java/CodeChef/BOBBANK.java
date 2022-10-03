package codechef_lib;

import java.util.Scanner;

public class BOBBANK {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			//For every Testcase
			int w=sc.nextInt();
			int x = sc.nextInt();
			int y = sc.nextInt();
			int z = sc.nextInt();
			System.out.println(w+(x-y)*z);
		}

	}

}
//AC