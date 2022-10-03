
public class MergeSort {
	
	static void mergesort(int l,int h,int[] arr) {
		int m=(l)+(h-l)/2;
 		mergesort(l,m,arr);
		mergesort(m+1,h,arr);
		merge(l,m,h,arr);
	}
	static void merge(int l,int m,int h,int[] arr) {
		int k=l,i=l,j=m+1;
		int[] b=new int[arr.length];
		while((k<=m) && (j<=h)) {
			if(arr[k]<=arr[j]) {
				b[i]=arr[k];
				k=k+1;
			}else {
				b[i]=arr[j];
				j=j+1;
			}
			i=i+1;
		}
		i=l;
		if(k>m) {
			for(int z=j;z<h;z++) {
				b[i]=arr[z];
				i=i+1;
			}
		}else {
			for(int x=l;x<=m;x++) {
				b[i]=arr[x];i=i+1;
			}
		}
		for(int s=l;s<h;s++) {
			arr[s]=b[s];
		}
	}
public static void main(String[] args) {
	try {
	int arr[]= {2,3,42,1,3,4,2};
	mergesort(0, arr.length-1, arr);

	for(int i:arr) {
		System.out.print(i+" ");
	}
	}catch(Exception e) {
		e.printStackTrace();
	
	}
	
}
}
