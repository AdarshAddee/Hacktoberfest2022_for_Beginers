#include <iostream>
using namespace std;

int main() {
	int t,i,k,l,m;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>k>>l>>m;
	    if(k>l && k>m)
	    {
	        cout<<"Setter"<<endl;
	    }
	    else if(l>k && l>m)
	    {
	        cout<<"Tester"<<endl;
	    }
	    else
	    {
	        cout<<"Editorialist"<<endl;
	    }
	}
	
	return 0;
}
