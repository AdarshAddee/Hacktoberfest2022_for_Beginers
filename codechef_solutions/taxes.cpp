#include <iostream>
using namespace std;

int main() {
	int i,t,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x;
	    if(x>100)
	    {
	        cout<<x-10<<endl;
	    }
	    else
	    cout<<x<<endl;
	}
	return 0;
}
