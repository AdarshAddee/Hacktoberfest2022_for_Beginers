#include <iostream>
using namespace std;

int main() {
	int i,t,x,y;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x>>y;
	    if(x>=y)
	    {
	        cout<<"0"<<endl;
	    }
	    else if((y-x)%8==0)
	    {
	        cout<<(y-x)/8<<endl;
	    }
	    else
	    {
	        cout<<(y-x)/8 + 1<<endl;
	    }
	}
	return 0;
}
