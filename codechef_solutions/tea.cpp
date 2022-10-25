#include <iostream>
using namespace std;

int main() {
	int i,t,x,y,z;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x>>y>>z;
	    if(x%y==0)
	    {
	        cout<<(x/y)*z<<endl;
	    }
	    else if(x<y)
	    {
	        cout<<z<<endl;
	    }
	    else
	    {
	        cout<<(x/y + 1)*z<<endl;
	    }
	}
	return 0;
}
