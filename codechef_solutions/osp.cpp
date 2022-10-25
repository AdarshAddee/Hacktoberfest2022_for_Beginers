#include <iostream>
using namespace std;

int main() {
	int i,t,a,b,c;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a>>b>>c;
	    if((a%2==0 && b%2==0 && c%2==0) || (a%2!=0 && b%2!=0 && c%2!=0))
	    {
	        cout<<"NO"<<endl;
	    }
	    else
	    cout<<"YES"<<endl;
	}
	return 0;
}
