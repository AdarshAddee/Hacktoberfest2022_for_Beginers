package codechef_lib;

import java.util.Scanner;

public class PIZZA_BURGER {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int x =sc.nextInt();//money
			int y =sc.nextInt();//cost p
			int z = sc.nextInt();//cost b
			if(x>=y) {
				System.out.println("PIZZA");
			}else if(y>x && x>=z) {
				System.out.println("BURGER");
			}else if(y>x && z>x) {
				System.out.println("NOTHING");
			}
		}

	}

}
