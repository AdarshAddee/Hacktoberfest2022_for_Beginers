#include <iostream>
using namespace std;

int main() {
	int arr[100];
	int i,c=0;
	for(i=0;i<4;i++)
	{
	    cin>>arr[i];
	    if(arr[i]>=10)
	    {
	        c+=1;
	    }
	}
	cout<<c<<endl;
	
	
	return 0;
}
