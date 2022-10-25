#include <iostream>
using namespace std;

int main() {
	int i,t,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x;
	    if(x/25==0)
	    {
	        cout<<"1"<<endl;
	    }
	    else if(x%25==0)
	    {
	        cout<<x/25<<endl;
	    }
	    else
	    {
	        cout<<x/25 + 1<<endl;
	    }
	    
	}
	return 0;
}
