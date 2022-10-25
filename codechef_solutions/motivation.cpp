#include <iostream>
using namespace std;
int fun(int n, int x)
{
    int j,a[1000],b[1000],count=0;
    for(j=0;j<n;j++)
    {
        cin>>a[j]>>b[j];
    }
    for(j=0;j<n;j++)
    {
        if(x>=a[j])
        {
            if(b[j]>count)
            {
                count = b[j];
            }
        }
    }
    return count;
    
}
int main() {
	int i,t,n,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>x;
	    cout<<fun(n,x)<<endl;
	}
	return 0;
}
