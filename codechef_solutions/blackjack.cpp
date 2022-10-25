#include <iostream>
using namespace std;

int main() {
	int i,t,a,b;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a>>b;
	    if((21-(a+b))<=10)
	    {
	        cout<<21-(a+b)<<endl;
	    }
	    else
	    {
	        cout<<"-1"<<endl;
	    }
	}
	return 0;
}
