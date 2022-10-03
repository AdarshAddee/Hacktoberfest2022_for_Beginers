package codechef_lib;

import java.util.Arrays;
import java.util.Scanner;

public class ANTI_PAL {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int h=0;h<t;h++) {
			int n =sc.nextInt();
			String s = sc.next();
			String s_copy = "";
			String f = "";
			String s_sort="";
			char s_arr[] = s.toCharArray();
			Arrays.sort(s_arr);
			for(char u:s_arr) {
				s_sort+=u;
			}
			s=s_sort;
			if(n%2==0) {
				for(int j=0;j<n/2;j++) {
					f+=s.charAt(j);
				}
				for(int j=n-1;j>=n/2;j--) {
					f+=s.charAt(j);
				}
				for(int j=0;j<n;j++) {
					s_copy+=s.charAt(n-j-1);
				}
				boolean isno = false;

				for(int j=0;j<n;j++) {
					if(f.charAt(j)==f.charAt(n-j-1)) {
						System.out.println("NO");
						isno=true;
						break;
					}
				}
				if(!isno) {
					System.out.println("YES");
					System.out.println(f);
				}
			}else {
				System.out.println("NO");
			}
					
		}

	}

}
