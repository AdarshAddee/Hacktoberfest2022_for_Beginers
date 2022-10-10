#include<stdio.h>
void merge(int a[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,k=beg,b[end+1],t;
	while((i<=mid)&&(j<=end))
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else{
			 b[k]=a[j];
			 j++;
			 k++;
		}
	}
	if(i>mid)
	{
		while(j<=end)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(t=beg;t<k;t++)
	{
		a[t]=b[t];
	}
}
void merge_sort(int a[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		merge_sort(a,beg,mid);
		merge_sort(a,mid+1,end);
		merge(a,beg,mid,end);
	}
}
int main()
{
	int a[]={10,5,2,21,11,15};
	int t;
	merge_sort(a,0,5);
	for(t=0;t<=5;t++)
	{
		printf("%d ",a[t]);
	}
}
