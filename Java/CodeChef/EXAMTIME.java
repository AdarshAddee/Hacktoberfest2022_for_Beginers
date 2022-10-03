package codechef_lib;
import java.util.Scanner;
public class EXAMTIME {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i =1;i<=n;i++) {
			//dragon
			int dsa_d = sc.nextInt();
			int toc_d = sc.nextInt();
			int dm_d = sc.nextInt();
			int total_d = dsa_d + toc_d + dm_d;
			//sloth
			int dsa_s = sc.nextInt();
			int toc_s = sc.nextInt();
			int dm_s = sc.nextInt();
			int total_s = dsa_s + toc_s+dm_s;
			if(total_d>total_s) {
				System.out.println("Dragon");
			}else if(total_s>total_d) {
				System.out.println("Sloth");
			}else if(total_s == total_d) {
				if(dsa_d>dsa_s) {
					System.out.println("Dragon");
				}else if(dsa_s>dsa_d) {
					System.out.println("Sloth");
				}else if(dsa_s == dsa_d) {
					if(toc_s>toc_d) {
						System.out.println("Sloth");
					}else if(toc_d>toc_s) {
						System.out.println("Dragon");
					}else if(toc_d == toc_s) {
						if(dm_s>dm_d) {
							System.out.println("Sloth");
						}else if(dm_d>dm_s) {
							System.out.println("Dragon");
						}else if(dm_d == dm_s) {
							System.out.println("Tie");
						}
					}
				}
			}
			
		}

	}

}
