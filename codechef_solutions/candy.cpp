#include <iostream>
using namespace std;

int main() {
	int i,t,n,m;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>m;
	    if(n%m==0 && (n/m)%2==0)
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
