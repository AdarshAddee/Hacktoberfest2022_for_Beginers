#include<iostream>
using namespace std;
int main()
{
	int t,n,i,m;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=1;i<n;i++)
		a[i]+=a[i-1];
	cin>>m;
	int q[m];
	for(i=0;i<m;i++)
	{
		cin>>q[i];
		cout<<(lower_bound(a,a+n,q[i])-a)+1<<endl; //lower_bound gives the address of location where q[i] is present and if not present the it will give the address of location where number just greater than q[i] is present in array a.
	}
}
