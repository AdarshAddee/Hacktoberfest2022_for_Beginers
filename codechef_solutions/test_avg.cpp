#include <iostream>
using namespace std;

int main() {
	int i,t,a,b,c;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a>>b>>c;
	    if((a+b)/2 >= 35 && (a+c)/2 >= 35 && (c+b)/2 >= 35)
	    cout<<"PASS"<<endl;
	    
	    else
	    cout<<"FAIL"<<endl;
	}
	return 0;
}
