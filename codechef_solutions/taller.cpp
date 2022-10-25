#include <iostream>
using namespace std;

int main() {
	int i,t,x,y;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x>>y;
	    if(x>y)
	    {
	        cout<<"A"<<endl;
	    }
	    else
	    {
	        cout<<"B"<<endl;
	    }
	}
	return 0;
}
