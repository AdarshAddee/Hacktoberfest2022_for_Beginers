#include <iostream>
using namespace std;

int main() {
	int t,i,x,y,z;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x>>y>>z;
	    cout<<(z-y)/x<<endl;
	}
	return 0;
}
