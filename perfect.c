#include <stdio.h>
int main() 
{
    int n,i,s=0;
    printf("Enter number ");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        s=s+i;
    }
    if(s==n)
    printf("%d is a Perfect Number.",n);
    else
    printf("%d is not a Perfect Number.",n);
}
