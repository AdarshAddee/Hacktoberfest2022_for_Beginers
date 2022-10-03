package codechef_lib;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class PBATTLE {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			//For every Testcase
			int n=sc.nextInt();
			//Arr
			int ans=0;
			int arr_gnd[] = new int[n];
			int arr_wtr[] = new int[n];
			
			for(int i=0;i<n;i++) {
				
				arr_gnd[i]=sc.nextInt();
				
			}
			for(int i=0;i<n;i++) {
				arr_wtr[i]=sc.nextInt();
				
			}
			
			
			for(int i=0;i<n;i++) {
				int stren=0;
				for(int j=0;j<n;j++) {
					if(arr_gnd[i]>=arr_gnd[j] || 
							arr_wtr[i]>=arr_wtr[j]) {
						stren++;
					}else {
						break;
					}
				}
				if(stren>=n) {
					ans++;
				}
				
			}
			System.out.println(ans);
		}

	}

}
//AC