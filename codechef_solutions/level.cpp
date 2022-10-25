#include <iostream>
using namespace std;

int main() {
	int i,t,x,y,z;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x>>y>>z;
	    if(x<3)
	    {
	        cout<<x*y<<endl;
	    }
	    else if(x%3==0)
	    {
	        cout<<x*y + (x/3 - 1)*z<<endl;
	    }
	    else
	    {
	        cout<<x*y + (x/3)*z<<endl;
	    }
	}
	return 0;
}
