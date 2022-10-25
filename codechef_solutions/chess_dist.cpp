#include <iostream>
using namespace std;

int main() {
	int i,t,a,b,c,d;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a>>b>>c>>d;
	    if(a>c)
	    {
	        if(b>d)
	        {
	            if((a-c)>(b-d))
	            cout<<a-c<<endl;
	            else
	            cout<<b-d<<endl;
	        }
	        else
	        {
	            if((a-c)>(d-b))
	            cout<<a-c<<endl;
	            else
	            cout<<d-b<<endl;
	        }
	    }
	    else
	    {
	        if(b>d)
	        {
	            if((c-a)>(b-d))
	            cout<<c-a<<endl;
	            else
	            cout<<b-d<<endl;
	        }
	        else
	        {
	            if((c-a)>(d-b))
	            cout<<c-a<<endl;
	            else
	            cout<<d-b<<endl;
	        }
	        
	    }
	}
	return 0;
}
