package codechef_lib;

import java.util.Scanner;

public class DIV3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int z = sc.nextInt();//number of zeros
			int o = sc.nextInt();//number of ones
			int w = sc.nextInt();//number of twos
			int num = z;//number of sets possible_ min are zero's ones too
			if (o>0 && w>0 && o>=w)
		    {
		        num+=w;
		        o-=w;
		        w=0;
		    }
		    if (o>0 && w>0 && w>=o)
		    {
		        num+=o;
		        w=w-o;
		        o=0;
		    }
		    if (w>0 && o==0)
		    {
		        num+=w/3;
		        w-=(w/3)*3;
		    }
		    if (o>0 && w==0)
		    {
		        num+=o/3;
		        o-=(o/3)*3;
		    }
						
			System.out.println(num);
			
		}

	}

}
