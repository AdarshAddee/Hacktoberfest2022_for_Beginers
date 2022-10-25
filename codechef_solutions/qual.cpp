#include <iostream>
using namespace std;

int main() {
	int i,t,n,a,b;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>a>>b;
	    if(n<=a+2*b)
	    {
	        cout<<"Qualify"<<endl;
	    }
	    else
	    cout<<"NotQualify"<<endl;
	}
	return 0;
}
