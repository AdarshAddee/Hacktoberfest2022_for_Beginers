#include <iostream>
using namespace std;

int main() {
	int i,t,x,y,z;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>x>>y>>z;
	    if(z%x==0 && z%y==0)
	    {
	        cout<<"ANY"<<endl;
	    }
	    else if(z%x==0 && z%y!=0)
	    {
	        cout<<"CHICKEN"<<endl;
	    }
	    else if(z%x!=0 && z%y==0)
	    {
	        cout<<"DUCK"<<endl;
	    }
	    else
	    cout<<"NONE"<<endl;
	}
	return 0;
}
