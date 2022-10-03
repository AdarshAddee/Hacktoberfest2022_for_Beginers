package codechef_lib;
import java.util.Scanner;
public class AMR15A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int c_e =0;
		int c_o =0;
		for (int i=1;i<=t;i++) {
			int a = sc.nextInt();
			if(a%2==0) {
				c_e++;
			}else {
				c_o++;
			}
		}
		if(c_e>c_o) {
			System.out.println("READY FOR BATTLE");
		}else {
			System.out.println("NOT READY");
		}

	}

}
