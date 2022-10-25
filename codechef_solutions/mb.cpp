#include <iostream>
using namespace std;

int main() {
	int i,t,x,y,z;
	
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x>>y>>z;
	    if(z>y/x)
	    {
	        cout<<z-y/x<<endl;
	    }
	    else
	    {
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}
