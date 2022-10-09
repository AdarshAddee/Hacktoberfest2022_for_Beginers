#include <stdio.h>
void main()
{
    int arr[100],n,i,num;
    printf("Enter no of cells : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the array elements :");
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("The array elements are : %d \n",arr[i]);
    }
    printf("ENTER AN ELEMENT YOU WANT TO SEARCH : ");
    scanf("%d",&num);
    for (i=0;i<n;i++)
    {
        if (num==arr[i])
        {
            printf("The %d is present at the location %d",num,i+1);
            break;
        }

    }
     if (i == n)
     {
        printf("%d isn't present in the array.\n", num);
     }

}