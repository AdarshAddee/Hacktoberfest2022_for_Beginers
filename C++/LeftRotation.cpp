#include<iostream>
using namespace std;
int main()
{
	int size;
	cout<<"Enter size of array:";
	cin>>size;
	int*a=new int[size];
  
	int temp,d;
	cout<<"Enter elements in array:"<<endl;
	for(int i=0;i<size;i++)
	cin>>a[i];
  
	cout<<"How many times do you want array to be left rotated? ";
	cin>>d;
  
	cout<<endl<<"Original array:"<<endl;
	for(int i=0;i<size;i++)
	cout<<a[i]<<"   ";
  
  for(int k=1;k<=d;k++)
  {
	 temp=a[0];
      for(int i=0;i<size;i++)
	  {
		a[i]=a[i+1];
	  }
	 a[size-1]=temp;
	}
  
	cout<<endl<<"Array after left rotation:"<<endl;
	for(int i=0;i<size;i++)
	cout<<a[i]<<"   ";
}
