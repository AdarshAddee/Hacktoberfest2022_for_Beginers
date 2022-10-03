package codechef_lib;

import java.util.Scanner;

public class NOPAL {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n =sc.nextInt();
			String s = str(n);
			if(!isPal(s)) {
				System.out.println(s);
			}
			
		}

	}
	public static String str(int n) {
		StringBuilder s = new StringBuilder();
		for (int i =1;i<=n;i++) {
			s.append((char) (Math.random()*(122-97)+97));	
		}
		return s.toString();
	}
	public static boolean isPal(String s) {
		char s_arr[] = s.toCharArray();
		char s_arr_copy[]=new char[s_arr.length];
		for (int o=0;o<=s_arr.length;o++) {
			s_arr_copy[s_arr.length-o-1]=s_arr[o];
		}
		boolean isSame = true;
		for(int h=0;h<s_arr.length;h++) {
			if(s_arr[h]!=s_arr_copy[h]) {
				isSame = false;break;
			}
		}
		if(isSame) {
			s=str(s_arr.length);
			isPal(s);
		}else {
			return false;
		}
		return true;
	}

}
