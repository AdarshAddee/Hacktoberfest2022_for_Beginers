package codechef_lib;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class TEAMOF2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			int n = sc.nextInt();
			HashMap<Integer,ArrayList<Integer >> map = 
					new HashMap<Integer,ArrayList<Integer>>();
			for(int  i=0;i<n;i++) {
				int k = sc.nextInt();
				ArrayList<Integer> temp = new ArrayList<>();
				int arr[] = new int[k];
				for(int j=0;j<k;j++) {
					arr[j]=sc.nextInt();
					temp.add(arr[j]);
				}
				map.put(i,temp);
			}
			boolean found=false;
			for(int i=0;i<n-1;i++) {
				ArrayList<Integer> lst_2 = map.get(i);
				for(int j=i+1;j<n;j++) {
					int score[] = new int[5];
					Arrays.fill(score, 0);
					ArrayList<Integer> lst_1 = map.get(j);
					for(Integer e:lst_1) {
						score[e-1]++;
					}
					for(Integer e:lst_2) {
						score[e-1]++;
					}
					
					//chcekc score
					boolean flag = false;
					for(int e: score) {
						if(e>0) {
							continue;
						}else {
							flag = true;
							break;
						}
					}
					if(flag) {
						continue;
					}else {
						found=true;
						System.out.println("YES");
						break;
					}
				}
				if(found) {
					break;
				}
			}
			if(!found) {
				System.out.println("NO");
			}
		}

	}

}
//AC