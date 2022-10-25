#include <iostream>
using namespace std;

int main() {
	int t,i,n,m,k;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>m>>k;
	    if(n<=m*k)
	    {
	        cout<<"yes"<<endl;
	    }
	    else
	    {
	        cout<<"no"<<endl;
	    }
	}
	return 0;
}
