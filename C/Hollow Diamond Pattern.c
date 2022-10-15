#include<stdio.h>
int main()
{
   int n, a=1;

   printf("Enter number of rows: ");
   scanf("%d", &n);

   for(int i=1; i<=n; i++)
   {
     for(int j=i; j<=n; j++)
     {
       printf(" ");
     }
     for(int k=1; k<=2*i-1; k++)
     {
       if(k==1 || k==2*i-1) printf("%d",a);
       else printf(" ");
     }
     a++;
     printf("\n");
   }

   a=n-1;

   for(int i=n-1; i>=1; i--)
   {
     for(int j=n; j>=i; j--)
     {
       printf(" ");
     }
     for(int k=1; k<=2*i-1; k++)
     {
       if(k==1 || k==2*i-1) printf("%d",a);
       else printf(" ");
     }
     a--;
     printf("\n");
   }

   return 0;
}