package codechef_lib;

import java.util.Arrays;
import java.util.Scanner;

public class COLOUR {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			int arr[] = new int[3];
			int x = sc.nextInt();
			int y = sc.nextInt();
			int z = sc.nextInt();
			arr[0]=x;arr[1]=y;arr[2]=z;
			Arrays.sort(arr);
			int s=0;
		    if(arr[0]>0){
		        arr[0]--;
		        s++;
		    }
		    if(arr[1]>0){
		        arr[1]--;
		        s++;
		    }
		    if(arr[2]>0){
		        arr[2]--;
		        s++;
		    }
		    if(arr[2]>0 && arr[1]>0){
		        arr[2]--; arr[1]--; s++;
		    }
		    if(arr[2]>0 && arr[0]>0){
		        arr[2]--; arr[0]--; s++;
		    }
		    if(arr[1]>0 && arr[0]>0){
		        arr[1]--; arr[0]--; s++;
		    }
		    System.out.println(s);
			
		}

	}

}
//AC