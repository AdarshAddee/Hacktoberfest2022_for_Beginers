#include <iostream>
using namespace std;

int main() {
	int i,t,n,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>x;
	    if(n%6!=0)
	    {
	        cout<<(n/6 + 1)*x<<endl;
	    }
	    else
	    cout<<(n/6)*x<<endl;
	}
	return 0;
}
