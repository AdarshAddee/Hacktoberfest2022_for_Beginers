#include <iostream>
using namespace std;

int main() {
	int i,t,a,b,c,d;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a>>b;
	    cin>>c>>d;
	    if(a<=c && b<=d)
	    {
	        cout<<"POSSIBLE"<<endl;
	    }
	    else
	    {
	        cout<<"IMPOSSIBLE"<<endl;
	    }
	}
	return 0;
}
