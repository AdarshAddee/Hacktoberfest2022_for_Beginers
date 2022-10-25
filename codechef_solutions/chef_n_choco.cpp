#include <iostream>
using namespace std;

int main() {
	int i,t,c,x,y;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>c>>x>>y;
	    if(c<=x)
	    cout<<0<<endl;
	    else
	    cout<<(c-x)*y<<endl;
	}
	return 0;
}
