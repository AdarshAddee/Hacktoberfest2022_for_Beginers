package codechef_lib;

import java.util.Scanner;

public class NEARESTEXIT {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			int x = sc.nextInt();
			if(x<=50) {
				System.out.println("LEFT");
			}else {
				System.out.println("RIGHT");
			}
		}

	}

}
//AC