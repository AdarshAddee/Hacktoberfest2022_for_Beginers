#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int c[n]={};
	    for(int i=0;i<n;i++){
	        cin>>c[i];
	    }
	    
	    int max=-100000,ans;
	    for(int i=0;i<n;i++){
	        if(c[i]>max){
	            ans=i;
	            max=c[i];
	        }
	    }
	   // cout<<ans<<endl;
	    if(ans==0){
	        cout<<-1;
	    }
	    else{
	        cout<<ans<<endl;
	    for(int i=0;i<ans;i++){
	        cout<<c[i]<<" ";
	    }
	    cout<<endl;
	    cout<<n-ans<<endl;
	    for(int i=ans;i<n;i++){
	        cout<<c[i]<<" ";
	    }
	    }
	    cout<<endl;
	    
	}
	return 0;
}
