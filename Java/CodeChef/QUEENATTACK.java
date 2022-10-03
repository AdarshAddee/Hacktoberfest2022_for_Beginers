package codechef_lib;

import java.util.Scanner;

public class QUEENATTACK {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			int x = sc.nextInt();int y = sc.nextInt();
			int ans=2*(n-1);
			if(x==1&&y==1 || x==1&&y==n ||x==n&&y==1 ||x==n&&y==n) {
				ans+=n-1;
			}else if(x==1 || x==n) {
				ans+=n-1;
			}else if(y==1 || y==n) {
				ans+=n-1;
			}else {
				int c=0;
				int t_x=x;int t_y=y;
				while(t_x>1 && t_y>1) {
					c++;
					t_x--;t_y--;
				}
				int e_x=x;int e_y=y;
				while(e_x>1 && e_y<n) {
					c++;
					e_x--;e_y++;
				}
				int h_x=x;int h_y=y;
				while(h_x<n && h_y>1) {
					c++;
					h_x++;h_y--;
				}
				int u_x=x;int u_y=y;
				while(u_x<n && u_y<n) {
					c++;
					u_x++;u_y++;
				}
				ans+=c;
				
			}
			System.out.println(ans);
		}

	}

}
//Accepted