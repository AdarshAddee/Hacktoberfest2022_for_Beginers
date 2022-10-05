#include <iostream>
#include<stdio.h>

using namespace std;
void selsrt(int [],int);

int main()
{
    int n,ar[100];
cout<<"Enter The No of Elements you want in your array :";
cin>>n;
cout<<endl<<"Enter the values of the "<<n<<" elements:--"<<endl;
for(int i=0;i<n;i++)
{
cin>>ar[i];
}
selsrt(ar,n);
cout<<"The sorted Array is below :--"<<endl;
for(int i=0;i<n;i++)
{
    cout<<ar[i]<<" ";
}







return 0;
}
void selsrt(int ar[],int size)//.....the function defination.....
{
int small,pos,temp;
for(int k=0; k<size-1;k++)
{
for(int i=0;i<size-1;i++)
{
    small=ar[i];
    pos=i;
    for(int j=i+1;j<size;j++)
    {
        if(ar[j]<small)
        {
            small=ar[j];
            pos=j;
          
        }
            temp=ar[i];
        ar[i]=ar[pos];
        ar[pos]=temp;
        cout<<"\narray after pass - "<<i+1<<" is  :";
        for( j=0;j<size;j++)
            cout<<ar[j]<<" ";
            
        

    }
    cout<<endl;
}
cout<<endl<<"round no.-- "<<k+1<<" done.";
}
}

