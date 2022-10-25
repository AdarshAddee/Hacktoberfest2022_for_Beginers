#include <iostream>
using namespace std;

int main() {
	int t,i,m,n;
	long int d,c;
	string str[100];
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>m>>n;
	    d = m*100;
	    c = n*10;
	    if(c<=d)
	    {
	        cout<<"Cloth"<<endl;
	    }
	    else{
	        cout<<"Disposable"<<endl;
	    }
	}
	return 0;
}
