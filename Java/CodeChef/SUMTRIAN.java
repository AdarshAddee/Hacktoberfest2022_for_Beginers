package codechef_lib;

import java.util.Scanner;

public class SUMTRIAN {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int k=sc.nextInt();//k x k matrix//change int to long
			int arr[][]= new int[k][k];
			for (int j=0;j<k;j++) {
				for(int l=0;l<=j;l++) {
					arr[j][l]=sc.nextInt();
				}
			}
			//summing
			for(int f=k-1;f>0;f--) {
				for(int w=k-1;w>0;w--) {
					arr[f-1][w-1]=arr[f-1][w-1] + Math.max(arr[f][w-1],arr[f][w]);
				}
				
			}
			System.out.println(arr[0][0]);
			//after sum
			
			//printin arr
			/*
			for (int j=0;j<k;j++) {
				for(int l=0;l<=j;l++) {
					System.out.print(arr[j][l]+" ");
				}
				System.out.println("");
			}*/
			
		}

	}

}
