package codechef_lib;

import java.util.Scanner;

public class COVID_19 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();//rows
			int m = sc.nextInt();//seats per row
			int n_a=0;
			int m_a=0;
			if(n%2==0) {
				n_a=(int)(n/2);
			}else if(n%2!=0){
				n_a=(int)(n/2+1);
			}
			if(m%2==0) {
				m_a=(int)(m/2);
			}else if(m%2!=0){
				m_a=(int)(m/2+1);
			}
			System.out.println(n_a*m_a);
		}

	}

}
