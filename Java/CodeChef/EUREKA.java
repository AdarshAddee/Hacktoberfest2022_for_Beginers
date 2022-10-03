package codechef_lib;

import java.util.Scanner;

public class EUREKA {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			double f = Math.pow((0.143)*n,n);
			double f_floor = Math.floor(f);
			if(f-f_floor<0.5) {
				System.out.println((int)f_floor);
			}else {
				System.out.println((int)f_floor +1);
			}
		}

	}

}
