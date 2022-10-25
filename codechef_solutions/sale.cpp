#include <iostream>
using namespace std;

int main() {
	int i,t,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x;
	    if(x<=100)
	    cout<<x<<endl;
	    
	    else if(100<x && x<=1000)
	    cout<<x-25<<endl;
	    
	    else if(1000<x && x<=5000)
	    cout<<x-100<<endl;
	    
	    else if(5000<x)
	    cout<<x-500<<endl;
	}
	return 0;
}
