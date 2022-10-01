#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n,long long s){
        // Your code here
        int right=0, left=0;
        long long curr_sum=0;
        vector<int> ans;
        while(left<=n && right<=n){
            if(curr_sum<s){
                curr_sum=curr_sum+arr[right];
                right++;
            }else if(curr_sum>s){
                curr_sum=curr_sum-arr[left];
                left++;
            }else if(curr_sum==s){
                ans.push_back(left+1);
                ans.push_back(right);
                break;
            }
        }
        if(curr_sum!=s){
    	ans.push_back(-1);
	}
        return ans;
}

int main(){
	int n,i;
	long long s;
	cout<<"Enter the size"<<endl;
	cin>>n;
	cout<<"Enter the sum"<<endl;
	cin>>s;
	int arr[n];
	vector<int> res;
	cout<<"Enter the values"<<endl;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	res=subarraySum(arr,n,s);
	
	for(i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
}
