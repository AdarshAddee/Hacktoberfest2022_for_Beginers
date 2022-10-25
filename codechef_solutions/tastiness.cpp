#include <iostream>
using namespace std;

int main() {
	int i,t,a,b,c,d,p,q,r,s;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a>>b>>c>>d;
	    p=a+c;
	    q=a+d;
	    r=b+c;
	    s=b+d;
	    if(p>=q && p>=r && p>=s)
	    {
	        cout<<p<<endl;
	    }
	    
	    else if(q>=p && q>=r && q>=s)
	    {
	        cout<<q<<endl;
	    }
	    else if(r>=p && r>=q && r>=s)
	    {
	        cout<<r<<endl;
	    }
	    else
	    {
	        cout<<s<<endl;
	    }
	}
	return 0;
}
