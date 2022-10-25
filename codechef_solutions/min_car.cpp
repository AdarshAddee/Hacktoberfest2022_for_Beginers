#include <iostream>
using namespace std;

int main() {
	int i,t,n;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n;
	    if(n%4==0)
	    {
	        cout<<n/4<<endl;
	    }
	    else if(n/4==0)
	    {
	        cout<<"1"<<endl;
	    }
	    else
	    {
	        cout<<n/4 + 1<<endl;
	    }
	}
	return 0;
}
