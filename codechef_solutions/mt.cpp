#include <iostream>
using namespace std;

int main() {
    int i,t,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x;
	    if(x%3==0)
	    {
	        cout<<"NORMAL"<<endl;
	    }
	    else if(x%3==2)
	    {
	        cout<<"SMALL"<<endl;
	    }
	    else{
	        cout<<"HUGE"<<endl;
	    }
	}
	return 0;
}
