#include <iostream>
using namespace std;

int main() {
	int i,t,n,x,k;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>x>>k;
	    if(x>k)
	    {
	        cout<<"0"<<endl;
	    }
	    else
	    {
	        if(n>k/x)
	        {
	            cout<<k/x<<endl;
	        }
	        else
	        {
	            cout<<n<<endl;
	        }
	    }
	}
	return 0;
}
