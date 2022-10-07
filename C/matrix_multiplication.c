// matrix multiplication
#include <stdio.h>
int main()
{
   int a[50][50], b[50][50], c[50][50], i, j, K;
   // input values for matrix a
   for (i = 1; i <= 2; i++)
   {
      for (j = 1; j <= 2; j++)
      {
         printf("Enter value for a[%d][%d]", i, j);
         scanf("%d", &a[i][j]);
      }
   }
   // // input values for matrix b
   for (i = 1; i <= 2; i++)
   {
      for (j = 1; j <= 2; j++)
      {
         printf("Enter value for b[%d][%d]", i, j);
         scanf("%d", &b[i][j]);
      }
   }

   // print matrix a

   for (i = 1; i <= 2; i++)
   {
      for (j = 1; j <= 2; j++)
      {
         // printf("Enter value for a[%d][%d]", i, j);
         printf("%d \t", a[i][j]);
         if (j == 2)
         {
            printf("\n");
         }
      }
   }
   // print matrix b
   printf("\n");

   for (i = 1; i <= 2; i++)
   {
      for (j = 1; j <= 2; j++)
      {
         // printf("Enter value for a[%d][%d]", i, j);
         printf("%d \t", b[i][j]);
         if (j == 2)
         {
            printf("\n");
         }
      }
   }
   c[1][1] =
       return 0;
}