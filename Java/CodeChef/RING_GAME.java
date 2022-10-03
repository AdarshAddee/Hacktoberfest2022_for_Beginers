package codechef_lib;

import java.util.Scanner;

public class RING_GAME {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int cases=sc.nextInt();
		while(cases--!=0) {
			int n = sc.nextInt();
			int arr[] = new int[n];
			int cnt1=0;int cnt0=0;
			for(int i=0;i<n;i++) {
				arr[i]=sc.nextInt();
				if(arr[i]==1) {
					cnt1++;
				}else {
					cnt0++;
				}
			}
			int currDiff = Currdiff(arr);
			int maxDiff=maxDiff(cnt0, cnt1);
			int d=(maxDiff-currDiff)/2;
			if(d%2==0) {
				System.out.println("BOB");
			}else {
				System.out.println("ALICE");
			}
		}

	}
	public static int Currdiff(int arr[]) {
		int ans=0;
		for(int i=0;i<arr.length-1;i++) {
			if(arr[i]!=arr[i+1]) {
				ans++;
			}
		}
		if(arr[arr.length-1]!=arr[0]) {
			ans++;
		}
		return ans;
	}
	public static int maxDiff(int a,int b) {
		return 2*Math.min(a, b);
	}

	
}
//AC