package codechef_lib;

import java.util.Scanner;

public class STRINGXOR {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			char[] a = sc.next().toCharArray();
			char[] b = sc.next().toCharArray();
			
			int c_1=0;int c_2=0;
			if(String.valueOf(a).equals(String.valueOf(b))) {
				System.out.println("YES");
				continue;
			}
			for(int j=0;j<n;j++) {
				if(a[j]=='1') {
					c_1++;
				}
				if(b[j]=='1') {
					c_2++;
				}
			}
			if(c_1==0 && c_2>0) {
				System.out.println("NO");
				continue;
			}
			int c=0;
			for(int k=0;k<n-1;k++) {
				if(b[k]!=b[k+1]) {
					c++;
				}
			}
			if(c==n-1) {
				System.out.println("NO");
				continue;
			}else{
				System.out.println("YES");
			}
			
		}

	}

}
//Ac