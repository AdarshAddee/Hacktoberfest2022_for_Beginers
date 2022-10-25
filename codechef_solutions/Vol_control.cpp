#include <iostream>
using namespace std;

int main() {
	int i,j,k,m,n;
	int arr[1000];
	cin>>k;
	for(i=0;i<k;i++)
	{
	    cin>>m>>n;
	    if(m>n)
	    {
	        j = m-n;
	    }
	    else if(n>m)
	    {
	        j = n-m;
	    }
	    else
	    {
	        j = m-n;
	    }
	    arr[i] = j;
	}
	for(i=0;i<k;i++)
	{
	    cout<<arr[i]<<endl;
	}
	return 0;
}
