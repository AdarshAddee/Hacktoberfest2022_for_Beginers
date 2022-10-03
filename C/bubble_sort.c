#include<stdio.h>
#include<conio.h>

void bubblesort(int a[],int n)
{
 int i,j;
 int temp;
 for(i=1;i<n;i++)
  {
    for(j=0;j<n-i;j++)
     {
      if(a[j]>a[j+1])
       {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
       }
     }
   }
}


void main()
{
 int arr[20];
 int i;
 int size;


 printf("\nEnter the size of array :");
 scanf("%d",&size);
 printf("\nEnter the element\n");

 for(i=0;i<size;i++)
 {
 scanf("%d",&arr[i]);
 }

 printf("\nBefore sorting\n");
 for(i=0;i<size;i++)
 {
 printf("%d, ",arr[i]);
 }

 bubblesort(arr,size);

 printf("\nAfter sorting\n");
 for(i=0;i<size;i++)
 {
 printf("%d ,",arr[i]);
 }
}
