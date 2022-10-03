#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	
	int maxi = a[0];
	int res = 0;
	for(int i=1;i<n;i++){
		maxi = max(a[i],maxi+a[i]);
		res = max(maxi,res);
	}
	cout<<res;
}
