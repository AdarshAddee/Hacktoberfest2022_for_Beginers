package codechef_lib;

import java.util.Arrays;
import java.util.Scanner;

public class RECTANGL {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int arr[] = new int[4];
			for (int h=0;h<4;h++) {
				arr[h] = sc.nextInt();
			}
			Arrays.sort(arr);
			boolean t1 = arr[0]==arr[1];
			boolean t2 = arr[2]==arr[3];
			if(t1 && t2) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
			
		}

	}

}
