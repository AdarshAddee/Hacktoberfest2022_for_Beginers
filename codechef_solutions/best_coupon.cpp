#include <iostream>
using namespace std;

int main() {
	int i,t,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x;
	    if(x/10 > 100)
	    cout<<x/10<<endl;
	    
	    else
	    cout<<"100"<<endl;
	}
	return 0;
}
