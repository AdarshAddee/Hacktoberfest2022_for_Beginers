#include <stdio.h>
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

int main()
{
    int count;
    scanf("%d", &count);
    int num1 = 0, num2 = 1, next;
    for (int i = 0; i < count - 1; i++)
    {
        if (i == 0)
        {
            printf("%d\n", num1);
        }
        else if (i == 1)
        {
            printf("%d\n", num2);
        }
        else
        {
            next = num1 + num2;
            num1 = num2;
            num2 = next;
            printf("%d \n", next);
        }
    }
    return 0;
}
