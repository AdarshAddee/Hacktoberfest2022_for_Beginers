#include <iostream>
using namespace std;

int main() {
	int t,i,w,x,y,z;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>w>>x>>y>>z;
	    if(x-w > y*z)
	    {
	        cout<<"Unfilled"<<endl;
	    }
	    else if(x-w < y*z)
	    {
	        cout<<"Overflow"<<endl;
	    }
	    else
	    cout<<"Filled"<<endl;
	}
	return 0;
}
