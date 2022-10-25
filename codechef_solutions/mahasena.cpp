#include <iostream>
using namespace std;

int main() {
	int i,t;
	cin>>t;
	int arr[100];
	int count = 0;
	for(i=0;i<t;i++)
	{
	    cin>>arr[i];
	    if(arr[i]%2==0)
	    {
	        count = count+1;
	    }
	}
	if(count>t/2)
	cout<<"READY FOR BATTLE"<<endl;
	
	else
	cout<<"NOT READY"<<endl;
	return 0;
}
