package codechef_lib;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
public class CRYCOLR {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in)); 
		
		int num = Integer.parseInt(br.readLine());
		for (int q =1;q<=num;q++) {
			int n =Integer.parseInt(br.readLine());
			int b1[] = new int[3];
			int b2[] = new int[3];
			int b3[] = new int[3];
			
			
			//enyter values to arr
			
				String line1 = br.readLine();
		        String[] strs1 = line1.trim().split("\\s+");
		    for (int k=0;k<3;k++) {	        
				b1[k] = Integer.parseInt(strs1[k]);
			}
			
				String line2 = br.readLine();
		        String[] strs2 = line2.trim().split("\\s+");
		    for (int k=0;k<3;k++) {	
		        b2[k] = Integer.parseInt(strs2[k]);
			}
			
				String line3 = br.readLine();
		        String[] strs3 = line3.trim().split("\\s+");
		    for (int k=0;k<3;k++) {    
				b3[k] = Integer.parseInt(strs3[k]);
			}
			//swwapping algo
			int count =0;
			
			while((b1[0] != n) || (b2[1] != n) || (b3[2] != n)) {
				//setting b1 filling with red
				while(b1[0] !=n) {//until box 1 has n in 1st pos
					if(b1[1] !=0) {
						if(b2[0] ==0) {
							if(b3[0]!=0 && b2[2]!=0) {
								b3[0]--;b2[2]--;b2[0]++;b3[2]++;count++;
							}
						}else if(b2[0]!=0) {
							b2[0]--;b1[0]++;b1[1]--;b2[1]++;count++;
						}
					}
					if(b1[2] !=0) {
						if(b3[0] ==0) {
							if(b2[0]!=0 && b3[1]!=0) {
								b3[1]--;b2[1]++;b2[0]--;b3[0]++;count++;
							}
						}else if(b3[0]!=0) {
							b3[0]--;b1[0]++;b3[2]++;b1[2]--;count++;
						}
					}
				}
				
				
				
			}
			//printin matrix formed after 1
			for (int c:b1) {
				System.out.print(c+" ");
			}
			System.out.println("");
			for (int c:b2) {
				System.out.print(c+" ");
			}
			System.out.println("");
			for (int c:b3) {
				System.out.print(c+" ");
			}
			System.out.println("");
			
				
			//final check
			if((b1[0] == n) && (b2[1] == n) && (b3[2] == n)) {//final cond reached
				System.out.println(count);
			}
			
			
		}

	}

}
