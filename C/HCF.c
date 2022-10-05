#include<stdio.h>

int HCFNaive(int a,int b)
{
    int hcf = 1;
    int mini;
    if(a >= b)
        mini = b;
    else
        mini = a;
    for(int i = 2; i <= mini; i++)
    {
        if(a%i == 0 && b%i == 0)
            hcf = i;
    }
    return hcf;

    // time complexity --> O(min(a,b))
    // auxiliary space --> O(1)
}

int HCFEfficient(int a, int b)
{
    if(b == 0)
        return a;
    return HCFEfficient(b,a%b);

    // time complexity --> O(log(min(a,b)))
    // auxiliary space --> O(1)
}

int main()
{
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d\n", HCFNaive(a,b));
    printf("%d\n", HCFEfficient(a,b));

    return 0;
}
