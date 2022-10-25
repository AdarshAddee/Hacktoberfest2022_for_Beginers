#include <iostream>
using namespace std;

int main() {
	int i,t,a,b,c,d;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a>>b>>c>>d;
	    if(a!=c && b!=d)
	    {
	        cout<<"1"<<endl;
	    }
	    else
	    {
	        cout<<"2"<<endl;
	    }
	}
	return 0;
}
