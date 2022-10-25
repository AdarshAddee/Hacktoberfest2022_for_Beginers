#include <iostream>
using namespace std;

int main() {
	int i,t,n,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>x;
	    if((n*x)%4==0)
	    cout<<(n*x)/4<<endl;
	    
	    else 
	    cout<<(n*x)/4 + 1<<endl;
	}
	return 0;
}
