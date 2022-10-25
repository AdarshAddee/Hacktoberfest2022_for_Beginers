#include <iostream>
using namespace std;

int main() {
	int t,i,m,n,k;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>m>>k;
	    if(m-k>=n)
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
