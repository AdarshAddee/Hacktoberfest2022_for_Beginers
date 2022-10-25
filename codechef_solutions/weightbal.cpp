#include <iostream>
using namespace std;

int main() {
	int i,t,w1,w2,x1,x2,m;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>w1>>w2>>x1>>x2>>m;
	    if((w2-w1)>=m*x1 && (w2-w1)<=m*x2)
	    {
	        cout<<"1"<<endl;
	    }
	    else
	    {
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}
