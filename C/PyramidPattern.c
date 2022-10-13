// Github username: MuskanVerma11
// Aim: Printing Pyramid Pattern
// Date: 13-10-2022

// start coding

#include <stdio.h>
int main() {
   int i, space, n, k = 0;
   printf("Enter the number of rows: ");
   scanf("%d", &n);
   for (i = 1; i <=n; ++i, k = 0) {
      for (space = 1; space <= n - i; space++) {
         printf("  ");
      }
      while (k != 2 * i - 1) {
         printf("* ");
         ++k;
      }
      printf("\n");
   }
   return 0;
}
