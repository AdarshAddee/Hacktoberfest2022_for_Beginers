// Github username: tanmoy27112000
// Aim:To search for element using interpolation Search
// Date: 8th Oct 2022

#include<stdio.h>
int interplorationSearch(int a[],int element,int size);
int main()
{
    int n,element,a[20],i;
    printf("Enter the number of elements you want to store: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element you want to search: ");
    scanf("%d",&element);
    int index = interplorationSearch(a,element,n);
    if (index == -1)
    {
        printf("Element not found");
    }
    else
        printf("Element found at position : %d ",index+1);

    return 0;
}
int interplorationSearch(int a[],int element, int size)
{
    int low,high,pos;
    low = 0;
    high = size-1;

    while(low<=high)
    {
        pos = low+((element-a[low])/(a[high]-a[low]))*(high-low);
        if(a[pos] == element)
            return pos;
        else if(a[pos]>element)
            high = pos-1;
        else
            low = pos+1;
    }
    return -1;
}
