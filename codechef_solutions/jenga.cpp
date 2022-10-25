#include <iostream>
using namespace std;

int main() {
	int i,t,n,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>x;
	    if(x%n==0 && x>=n)
	    {
	        cout<<"YES"<<endl;
	    }
	    else 
	    cout<<"NO"<<endl;
	}
	return 0;
}
