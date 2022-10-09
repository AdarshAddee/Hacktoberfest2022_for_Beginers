#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
int abs(int a)
{
    if(a>0)
    return a;
    else 
    return((-1)*a);
}
int main()
{
    int n=6;
    for(int i=0;i<n;i++)
    {
        for(int j=-1*n;j<n-1;j++)
        {
            if((n-abs(j+1))<=(n-i))
            printf("%d ",n-abs(j+1));
            else
            printf("  ");
            
        }
        printf("\n");
    }

    return 0;
}