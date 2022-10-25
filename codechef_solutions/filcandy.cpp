#include <iostream>
using namespace std;

int main() {
int i,t,n,k,m;
cin>>t;
for(i=0;i<t;i++)
{
    cin>>n>>k>>m;
    if(n%(k*m)==0)
    {
        cout<<n/(k*m)<<endl;
    }
    else
    {
        cout<<n/(k*m)+1<<endl;
    }
}
	return 0;
}
