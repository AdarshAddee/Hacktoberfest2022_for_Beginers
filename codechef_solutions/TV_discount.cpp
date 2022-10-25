#include <iostream>
using namespace std;

int main() {
	int t,a,b,c,d,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a>>b>>c>>d;
	    if(a-c>b-d)
	    {
	        cout<<"Second"<<endl;
	    }
	    else if(a-c<b-d)
	    {
	        cout<<"First"<<endl;
	    }
	    else
	    {
	        cout<<"Any"<<endl;
	    }
	}
	return 0;
}
