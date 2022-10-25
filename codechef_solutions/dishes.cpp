#include <iostream>
using namespace std;

int main() {
	int i,t,n,a,b,c;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>a>>b>>c;
	    if((a+c)>=n && b>=n)
	    {
	        cout<<"YES"<<endl;
	    }
	    else
	    {
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
