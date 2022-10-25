#include <iostream>
using namespace std;

int main() {
	int i,t,x,y,z;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x>>y>>z;
	    if(x>y+z || y>x+z || z>x+y)
	    cout<<"YES"<<endl;
	    else 
	    cout<<"NO"<<endl;
	}
	return 0;
}
