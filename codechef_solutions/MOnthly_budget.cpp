#include <iostream>
using namespace std;

int main() {
	int i,t,m,n;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>m>>n;
	    if(m<n*30)
	    {
	        cout<<"NO"<<endl;
	    }
	    else{
	        cout<<"YES"<<endl;
	    }
	}
	return 0;
}
