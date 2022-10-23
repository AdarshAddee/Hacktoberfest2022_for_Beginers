#include <iostream>
using namespace std;
void main()
{
  int c,n,i,sn,f=0;
  cout<<"enter size of array"<<endl;
  cin>>n;
  int a[n];
  cout<<"elements of array"<<endl;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<"enter no. to be search"<<endl;
  cin>>sn;
  for(i=0;i<n;i++)
  {
    if(a[i]==sn)
    {
      f=1;
      break;
    }
  }
  if(f==1)
    cout<<"no. found at position"<<i+1<<endl;
  else
    cout<<"no. not found<<endl;
  }
