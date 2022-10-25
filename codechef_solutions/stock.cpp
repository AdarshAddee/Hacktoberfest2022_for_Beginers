#include <iostream>
using namespace std;

int main() {
	int i,t;
	double s,a,b,c;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>s>>a>>b>>c;
	    if((s+s*c/100)>=a && (s+s*c/100)<=b)
	    {
	        cout<<"YES"<<endl;
	    }
	    else{
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
