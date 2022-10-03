package codechef_lib;

import java.util.HashSet;
import java.util.Scanner;

public class CHEFRACES {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			int a = sc.nextInt();
			int b = sc.nextInt();
			HashSet<Integer> l = new HashSet<Integer>();
			l.add(x);l.add(y);l.add(a);l.add(b);
			if(l.size()==4) {
				System.out.println(2);
			}else if(l.size()==3) {
				System.out.println(1);
			}else if(l.size()==2) {
				System.out.println(0);
			}
		}

	}

}
//Accepted