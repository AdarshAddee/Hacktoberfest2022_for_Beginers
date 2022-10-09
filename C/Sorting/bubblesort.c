#include <stdio.h>
void main()
{
    int i,j,n,arr[50],temp;
    printf("Enter no of cells : ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("ENter the values of elements : ");
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
        
    } 
    printf("Array after implementing bubble sort: ");

    for(i = 0; i < n; i++){

        printf("%d  ", arr[i]);  
}
}