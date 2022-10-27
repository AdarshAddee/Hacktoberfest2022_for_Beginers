#include<stdio.h>
//#include<stdlib.h>
#define max 6
void merge_sort(int , int );
void merge(int ,int ,int ,int );// function to sort the subsection a[i .. j] of the array a[]
int arr[max];
void main()
{
    int i;
    printf("\n Enter %d number of elements :",max);
    for(i=0;i<max;i++)
    scanf("%d",&arr[i]);
     printf("\n  Elements Before Sorting :");
    
    for(i=0;i<=max-1;i++)
    printf("\t%d",arr[i]);
    merge_sort(0,max-1);   //function call
    printf("\n Elements After Sorting : ");
    for( i=0;i<=max-1;i++){
    printf("\t %d",arr[i]);
}
}
void merge_sort(int low, int high)
{
    int mid;
  // int pointer_left =low;
  //  int pointer_right=mid + 1;
    if(low<high)
    {
        mid =(low+high)/2;
        merge_sort(low,mid);// sort the left sub-array recursively
        merge_sort(mid + 1,high );  // sort the right sub-array recursively
        merge(low,mid ,mid + 1,high);
    }
}
  void merge(int low, int mid , int mid1 ,int high)
  {
       int t[50];
       int i=low,j=mid1,k=0;
       while(i<=mid && j<=high)
    {
       if(arr[i]<arr[j])
         t[k++]=arr[i++];  //value of index of k and i incremeted at this condition true.
     else
         t[k++]=arr[j++];   //value of indext of k and j incremented at this condition true.
         }
    while(i <= mid)  // // pointer left points to smaller element
         t[k++]=arr[i++];
   while (j <= high)     // pointer right points to smaller element
         t[k++]=arr[j++];
    for(i=low,j=0; i<=high ;i++,j++)
         {
        arr[i]=t[j];     // copy the elements from t[] to arr[].
        }
    }
    