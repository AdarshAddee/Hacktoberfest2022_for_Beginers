package codechef_lib;

import java.util.Scanner;

public class EQUIVALENT {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			boolean flag=false;
			double a1[] = new double[20];
			double a2[] = new double[20];
			
			for(int i=0;i<20;i++) {
				a1[i]=Math.pow(a, i+1);
				a2[i]=Math.pow(b, i+1);
			}
			
			for(int i=0;i<20;i++) {
				for(int j=0;j<20;j++) {
					if(a1[i]==a2[j]) {
						flag=true;
						break;
					}
				}
			}
			if(flag) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
			
		}

	}

}
//AC