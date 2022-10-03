package codechef_lib;

import java.util.Arrays;
import java.util.Scanner;

public class BSCOST {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			int x = sc.nextInt();
			int y = sc.nextInt();
			String s = sc.next();
			int n_p = 0;
			char s_arr[]=s.toCharArray();
			Arrays.sort(s_arr);
			boolean taking=false;
			for(int j=0;j<s_arr.length;j++) {
				if(s_arr[j]=='0') {
					taking = true;
				}
				if(s_arr[j]=='1' && taking) {
					n_p++;
					taking=false;
				}else {
					continue;
				}
			}
			System.out.println(n_p*Math.min(x, y));
		}

	}

}
//Accepted