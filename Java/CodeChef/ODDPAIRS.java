package codechef_lib;

import java.util.Scanner;

public class ODDPAIRS {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			long n = sc.nextInt();
			if(n%2==0) {
				long odd=n/2;
				long even=n-odd;
				System.out.println(odd*even*2);
			}else {
				long odd=n/2+1;
				long even = n-odd;
				System.out.println(odd*even*2);
			}
		}

	}

}
//AC