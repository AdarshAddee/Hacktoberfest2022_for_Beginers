#include <iostream>
using namespace std;

int main() {
	int i,t,x,y,m;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x>>y>>m;
	    if(x*m<y)
	    cout<<"YES"<<endl;
	    
	    else
	    cout<<"NO"<<endl;
	}
	return 0;
}
