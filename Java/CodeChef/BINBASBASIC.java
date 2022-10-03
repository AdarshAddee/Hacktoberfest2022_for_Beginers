package codechef_lib;

import java.util.Scanner;

public class BINBASBASIC {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int l = sc.nextInt();
			int o = sc.nextInt();
			String s = sc.next();
			if(l%2!=0 || o==0) {
				System.out.println("NO");
			}else {
				char s_arr[] = s.toCharArray();
				int op=0;
				for(int u=0;u<l/2;u++) {
					if(s_arr[u]!=s_arr[l-u-1]) {
						s_arr[l/2+u]=s_arr[u];op++;
					}
				}
				if(op==o || op==0) {
					System.out.println("YES");
				}else {
					System.out.println("NO");
				}
			}
		}

	}

}
