#include <stdio.h>
void main()
{
    int i,j,key,low=0,high=10,found,mid;
    int a[10]={10,20,30,40,50,60,70,80,90,100};
    printf("Enter the element you want to search: ");
    scanf("%d",&key);
    while (low<=high)
    {
        mid=(high+low)/2;
        if(key < a[mid])
        {
            high=mid-1;
        }
        else if (key > a[mid])
        {
            low=mid+1;
        }
        else if(key == a[mid])
        {
            printf("Found at location %d",mid+1);
            found=1;
            break;
        }
    }
    if(!found)
    {
        printf("Not found");
    }
}