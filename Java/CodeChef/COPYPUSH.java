package codechef_lib;

import java.util.Scanner;

public class COPYPUSH {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int n = sc.nextInt();
			String a = sc.next();
			String a_1="";
			String a_2="";
			boolean n_f=false;
			while(!a.equals("")) {
				if(a.length()%2==0){
					a_1=a.substring(0, a.length()/2);
					a_2=a.substring(a.length()/2);
					if(a_1.equals(a_2)) {
						a=a_1;
						//System.out.println(a);
					}else {
						System.out.println("NO");
						n_f=true;
						break;
					}
				}else {
					a_1=a.substring(0, a.length()/2);
					a_2=a.substring(a.length()/2,a.length()-1);
					if(a_1.equals(a_2)) {
						a=a_1;
						//System.out.println(a);
					}else {
						System.out.println("NO");
						n_f=true;
						break;
					}
				}
			}
			if(!n_f) {
				System.out.println("YES");
			}
		}	
	}

}
//AC