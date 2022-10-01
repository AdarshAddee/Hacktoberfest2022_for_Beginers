/*
Enter the number of rows in the matrix
3
Enter the number of columns in the matrix
2
Enter the elements in the matrix
4 5
6 9
0 3

Output:
5
9
3
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, i = 0, j = 0, max = 0;

    printf("Enter the number of rows in the matrix\n");
    scanf("%d", &m);

    printf("Enter the number of columns in the matrix\n");
    scanf("%d", &n);

    int *ptr = (int *)malloc(m * n * sizeof(int));

    printf("Enter the elements in the matrix:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", (ptr + i * n + j));
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (max < *(ptr + i * n + j))
            {
                max = *(ptr + i * n + j);
            }
        }

        printf("%d\n", max);
        max = 0;
    }

    free(ptr);

    return 0;
}