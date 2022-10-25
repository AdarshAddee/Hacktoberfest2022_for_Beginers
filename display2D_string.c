#include<stdio.h>
#include<string.h>

int main()
{
    char a[4][20];
    int i,j;
    printf("enter 4 strings ");
    for(i=0;i<4;i++)
    {
        fgets(a[i],20,stdin);
    }
    printf("you entered : \n");
    for(i=0;i<4;i++)
    {
        int l=strlen(a[i]);
        for(j=0;j<=l-2;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
