#include <iostream>
using namespace std;

int main() {
	int i,t,x,y,m;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x>>y;
	    if(x%2==0)
	    {
	        m = x/2;
	        if(y>=m)
	        cout<<"YES"<<endl;
	        else
	        cout<<"NO"<<endl;
	    }
	    else
	    {
	        m = x/2 + 1;
	        if(y>=m)
	        cout<<"YES"<<endl;
	        else
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
