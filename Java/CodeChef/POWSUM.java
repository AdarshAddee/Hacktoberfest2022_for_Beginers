package codechef_lib;
import java.util.Arrays;
import java.util.Scanner;
public class POWSUM {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
		for (int i =1;i<=num;i++) {
			int n =sc.nextInt();
			int arr[] = new int[n];
			for (int j=0;j<n;j++) {
				arr[j] = sc.nextInt();
			}
			Arrays.sort(arr);
			boolean isgood = false;
			int count =0;
			int sumarray =0;
			//summing digits of array
			for (int c:arr) {
				sumarray = sumarray +c;
			}
			
			
		}

	}

}
