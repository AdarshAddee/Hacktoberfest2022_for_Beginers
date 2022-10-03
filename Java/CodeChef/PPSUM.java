package codechef_lib;

import java.util.Scanner;

public class PPSUM {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int d = sc.nextInt();
			int n=sc.nextInt();
			int sum_f=sum(n);
			for(int k=1;k<d;k++) {
				sum_f =sum(sum_f);
			}
			System.out.println(sum_f);
		}

	}
	public static int sum(int a) {
		int sum =0;
		for (int i =1;i<=a;i++) {
			sum=sum+i;
		}
		return sum;
	}

}
