#include <stdio.h>
void DFS (int a[10][10],int n,int src,int s[10])
{
    int i;
    s[src] = 1;
    printf ("%d\t",src);
    for (i=1;i<=n;i++)
    if (s[i]==0 && a[src][i])
    DFS (a,n,i,s);
}
int main ()
{
    int a[10][10],n,i,j,s[20],src;
    printf ("Enter no. of Nodes in Graph\n");
    scanf ("%d",&n);
    printf ("Enter the connections of Graph in Adjacency Matrix\n");
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    scanf ("%d",&a[i][j]);
    printf ("Enter the Source Node\n");
    scanf ("%d",&src);
    printf ("Source Node = %d\n",src);
    for (i=1;i<=n;i++)
    s[i]=0;
    printf("Visited Nodes using DFS:\n");
    DFS (a,n,src,s);
    printf ("\n");
    return 0;
}