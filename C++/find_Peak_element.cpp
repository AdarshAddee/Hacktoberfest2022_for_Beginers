//peak element: an element is a peak element if it is not smaller than its neighbours
#include<iostream>
using namespace std;
int getPeak(int arr[],int n)
{
  int low=0,high=n-1;
  while(low<=high)
  {
    int mid=(low+high)/2;
    if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]))
    {
      return mid;
    }
    if(mid>0 && arr[mid-1]>=arr[mid])
    {
      high=mid-1;
    }
    else
    {
      low=mid+1;
    }
  }
  return -1;
}
int main()
{
  int arr[]={2,7,9,10,23,12};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<"The peak element is present at  index: "<<getPeak(arr,n);
  return 0;
}
