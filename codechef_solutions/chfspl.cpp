#include <iostream>
using namespace std;

int main() {
	int i,t,a,b,c;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a>>b>>c;
	    if(a>=c && b>=c)
	    {
	        cout<<a+b<<endl;
	    }
	    else if(b>=a && c>=a)
	    {
	        cout<<b+c<<endl;
	    }
	    else
	    {
	        cout<<a+c<<endl;
	    }
	}

	return 0;
}
