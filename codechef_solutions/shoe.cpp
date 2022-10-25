#include <iostream>
using namespace std;

int main() {
	int i,t,n,m;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>m;
	    if(n>m)
	    {
	    cout<<(2*n-m)<<endl;   
	    }
	    else
	    {
	        cout<<n<<endl;
	    }
	}
	return 0;
}
