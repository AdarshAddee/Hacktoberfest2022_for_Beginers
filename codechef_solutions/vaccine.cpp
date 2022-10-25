#include <iostream>
using namespace std;

int main() {
	int i,t,d,l,r;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>d>>l>>r;
	    if(d>=l && d<=r)
	    {
	        cout<<"Take second dose now"<<endl;
	    }
	    else if(d<l)
	    {
	        cout<<"Too Early"<<endl;
	    }
	    else
	    {
	        cout<<"Too Late"<<endl;
	    }
	}
	return 0;
}
