#include <stdio.h>
void BFS (int a[10][10],int n,int src,int s[10])
{
    int f=0,r=-1,q[20],i,v;
    printf ("Source Node: %d\n",src);
    s[src] = 1;
    q[++r] = src;
    printf("Visited Nodes using BFS:\n");
    while (f <= r)
    {
        v = q[f++];
        for (i=1;i<=n;i++)
        if (s[i]==0 && a[v][i])
        {
            q[++r] = i;
            printf ("%d\t",i);
            s[i] = 1;
        }
    }
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
    for(i=1;i<=n;i++)
    s[i]=0;
    BFS (a,n,src,s);
    printf ("\n");
    return 0;
}