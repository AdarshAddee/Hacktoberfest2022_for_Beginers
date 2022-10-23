import java.util.*;
public class Sort012
{
public static void main(String[] args) 
{
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int arr[] = new int[n];
    System.out.println("Enter elements of array");
    for(int i=0;i<n;i++)
    {
        arr[i] = sc.nextInt();
    }
    Arrays.sort(arr);
    for(int i=0;i<n;i++)
    {
	    System.out.print(arr[i]);
    }
    
    
    //method 2
    int m = sc.nextInt();
    int b[] = new int[m];
    System.out.println("Enter elements of array");
    for(int i=0;i<m;i++)
    {
        b[i] = sc.nextInt();
    }
	int i=0, j=0,k=m-1,temp;
    while(j<=k)
    {
        if(b[j]==0)
        {
            temp=b[i];
            b[i]=b[j];
            b[j]=temp;
            i++;
            j++;
        }
        else if(b[j]==1)
        {
            j++;
        }
        else
        {   
            temp=b[j];
            b[j]=b[k];
            b[k]=temp;
            k--;
        }
    }
        for(i=0;i<m;i++)
    {
        System.out.print(b[i]);
    }
    

	}
}
