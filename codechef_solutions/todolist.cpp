#include <iostream>
using namespace std;
int loop(int n)
{
    int j;
    int arr[1000];
    int count = 0;
    for(j=0;j<n;j++)
	{
	    cin>>arr[j];
	    if(arr[j]>=1000)
	    {
	        count+=1;
	    }
	}
	return count;
}

int main() {
	int i,t,n;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    int count = 0;
	    cin>>n;
	    cout<<loop(n)<<endl;
	   
	}
	
	return 0;
}
