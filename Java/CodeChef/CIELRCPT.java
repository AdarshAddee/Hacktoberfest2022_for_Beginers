package codechef_lib;
import java.util.Scanner;
public class CIELRCPT {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=1;i<=t;i++) {
			int p =sc.nextInt();
			int money = p;
			int count =0;
			while(money!=0) {
				int c_val = (int)num(money);		
				if(c_val<=money) {
					money=money-c_val;count++;
				}
			}
			System.out.println(count);
						
		}
		

	}
	
	public static int num(int money) {//returns just bigger pow 2
		for(int k=0;k<12;k++) {
			if(Math.pow(2, k)>money) {
				return (int)Math.pow(2, k-1);
			}else if(Math.pow(2, k)==money) {
				return (int)Math.pow(2, k);
			}else if(money>Math.pow(2, 11)){
				return (int)Math.pow(2,11);
			}else {
				continue;
			}
		}
		return 1;
	}

}
