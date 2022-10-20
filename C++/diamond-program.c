#include <stdio.h>
int main(void)
{
int n,a,i,j,k;
printf("Enter only odd no. of lines\n");
scanf("%d",&n);
a=(n+1)/2;
for(i=1;i<=n;i++)
{ 
if(i<=a)
{
for(j=1;j<=a-i;j++)
{
printf(" ");
}
for(k=1;k<=2*i-1;k++)
{
printf("*");
}
printf("\n");
}
else 
{
for(j=1;j<=i-a;j++)
{
printf(" ");
}
for(k=1;k<=(2*n-(2*i-1));k++)
{
printf("*");
}
printf("\n");
}
}
}
