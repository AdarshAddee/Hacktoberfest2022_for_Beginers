/*

 Find Minimum Cost Spanning Tree of a given connected undirected graph using Kruskal's
algorithm. Use Union-Find algorithms in your program.

 */
import java.util.Scanner;
public class Kruskal {
    public static int find(int v,int s[])
    {
        while(s[v]!=v)
            v=s[v];
        return v;
    }
    public static void union1(int i,int j,int s[])
    {
        s[i]=j;
    }
    public static void kruskal(int n,int c[][])
    {
        int count,i,min,j,u=0,v=0,k,sum;
        int s[]= new int[10];
        int t[][]=new int[10][2];
        for(i=0;i<n;i++)
            s[i]=i;
        count=0;
        sum=0;
        k=0;
        while(count<n-1)
        {
            min=999;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(c[i][j]!=0 && c[i][j]<min)
                    {
                        min=c[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
            if(min==999) break;
            i=find(u,s);
            j=find(v,s);
            if(i!=j)
            {
                t[k][0]=u;
                t[k][1]=v;
                k++;
                count++;
                sum+=min;
                union1(i,j,s);
            }
            c[u][v]=c[v][u]=999;
        }
        if(count==n-1)
        {
            System.out.println("cost of spanning tree=" +sum+ "\n");
            System.out.println("spanning tree is\n");
            for(k=0;k<n-1;k++)
            {
                System.out.println("\n"+t[k][0]+","+t[k][1]);
            }
        }
        else {
            System.out.println("spanning treee doesn't exist");
        }
    }
    public static void main(String args[])
    {
        int n,i,j;
        int c[][]=new int[10][10];
        Scanner in=new Scanner(System.in);
        System.out.println("Enter no of nodes\n");
        n=in.nextInt();
        System.out.println("Enter the cost adjacency matrix\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                c[i][j]=in.nextInt();
            }
        }
        kruskal(n,c);
    }
}

/*
Output:
Enter no of nodes

6
Enter the cost adjacency matrix

999 3 999 999 6 5
3 999 1 999 999 4
999 1 999 6 999 4
999 999 6 999 8 5
6 999 999 8 999 2
5 4 4 5 2 999
cost of spanning tree=15

spanning tree is


1,2

4,5

0,1

1,5

3,5
 */
