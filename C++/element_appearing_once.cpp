#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	int j=0;
	while(j<=n-1){
	    
	    if(a[j]==a[j+1]){
	        j+=2;  
	    }
	    else{
	        cout<<a[j]<<endl;
	        break;
	    }
	    
	    
	    
	    
	}
	}
	return 0;
}
