#include<stdio.h>
int main()
{
    int x = 0,y = 0;
    unsigned int squareSide = 0;
    printf("Enter size of square = ");
    scanf("%u",&squareSide);
    //outer loop
    for(x = 0; x < squareSide; x++)
    {
        //inner loop
        for(y = 0; y < squareSide; y++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
