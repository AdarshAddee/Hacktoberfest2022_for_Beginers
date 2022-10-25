#include <iostream>
using namespace std;

int main() {
	int i,t,a,b,c;
	float s;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a>>b>>c;
	    s = ((float)a + (float)b)/2;
	    if(s>c)
	    {
	        cout<<"YES"<<endl;
	    }
	    else
	    cout<<"NO"<<endl;
	}
	return 0;
}
