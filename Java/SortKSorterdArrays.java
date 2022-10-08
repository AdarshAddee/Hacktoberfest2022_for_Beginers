import java.util.*;

public class SortKSorterdArrays {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = scn.nextInt();
		}
		int k = scn.nextInt();
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(int val : arr) {
			pq.add(val);
		}
		int m = pq.size();
		for(int i = 0; i < m; i++) {
			System.out.println(pq.remove());
		}
	
//problem with this code
	//space complexity = O(n)
	//time complexity = O(nlogn)
	// we can reduce the time complexity to some extent let us try  that
	
	
	PriorityQueue<Integer> mq = new PriorityQueue<>();
	for(int i = 0; i <= k; i++)
		mq.add(arr[i]);
	
	for(int i = k+1; i < arr.length; i++) {
		System.out.println(mq.remove());
		mq.add(arr[i]);
	}
	
	while(mq.size() > 0) {
		System.out.println(mq.remove());
	}
	
	// time complexity reduced to O(nlogk)
	// space complexity reduced to O(k)
	}
}
