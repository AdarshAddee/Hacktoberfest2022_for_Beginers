#include <iostream>
using namespace std;

int main() {
	int t,i,x,y;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x>>y;
	    if(y<=x*1.07)
	    cout<<"YES"<<endl;
	    else
	    cout<<"NO"<<endl;
	}
	return 0;
}
