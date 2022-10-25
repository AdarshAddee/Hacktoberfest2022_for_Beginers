#include <iostream>
using namespace std;

int main() {
	int i,t,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x;
	    if(x!=0 && x%3 != 0)
	    {
	        cout<<3-x%3<<endl;
	    }
	    else
	    {
	        cout<<"0"<<endl;
	    }
	    
	}
	return 0;
}
