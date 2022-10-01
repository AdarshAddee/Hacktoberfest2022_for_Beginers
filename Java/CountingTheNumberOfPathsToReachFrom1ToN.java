/**
 * Google Online Coding Challenge: Counting paths
 * You are given a matrix A having N rows and M columns. The rows are numbered 1 to N from top to bottom and columns are
 * numbered 1 to M from left to right. You are allowed to move right and down only, i.e., if you are at cell (i,j), then
 * you can move to (i+1, j) and (i, j+1). You are not allowed to move outside the matrix.
 * Your task is to find the number of good paths starting from (1, 1) and ending at (N, M).
 * Good Path: If the sum of all elements that lie in the path is divisible by K, then the path is considered as good.
 * 
 * @author: ShubhanshuJha
 * 
**/

import java.io.*;
import java.util.Set;
import java.util.HashSet;
import java.util.Scanner;

public class CountingTheNumberOfPathsToReachFrom1ToN {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(System.in);

		int testCase = Integer.parseInt(br.readLine());
		while(testCase-- > 0){
			long n = Long.parseLong(br.readLine());
			long m = Long.parseLong(br.readLine());
			long a[][] = new long[(int)n][(int)m];
			for (int i = 0; i < (int)n; i++) {
				for (int j = 0; j < (int)m; j++) {
					a[i][j] = sc.nextLong();
				}
			}
			long k = Long.parseLong(br.readLine());
			printMat(a);
			long res = paths(a, n, m);
			System.out.println(res);
		}
	}
	static void printMat(long[][] m){
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < m[0].length; j++) {
				System.out.print(m[i][j]+" ");
			}
			System.out.println();
		}
	}
	private static long paths(long a[][], long N, long M){
		if (a[(int)N][(int)M] == 1 || a[(int)N][(int)M] == 1) {
			return 1;
		}
		return paths(a, N, M-1) + paths(a, M, N-1);
	}
}