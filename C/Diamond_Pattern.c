/* 
Github username: SonamMalik17
Aim: To create a diamond pattern program in C
Date: 27 October, 2022
*/

//Code starts here
#include<stdio.h>
int main()
{
    int r,i,j,k;
    printf("Enter no. of rows after which u want to mirror image below of above : ");
    scanf("%d",&r);
    printf("Diamond Pattern : \n");
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=r-i;j++)
        printf(" ");
        for(k=1;k<=((2*i)-1);k++)
        printf("*");
        printf("\n");
    }
    for(i=1;i<r;i++)
    {
        for(j=1;j<=i;j++)
        printf(" ");
        for(k=1;k<=((2*r)-(2*i)-1);k++)
        printf("*");
        printf("\n");
    }
}