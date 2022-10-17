class Solution{
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
         int sum=0;
         for(int i=0;i<n;i++){
             sum+=a[i];
         }
         if(k==1)return true;
         if(k>n)return false;
         if(sum%k!=0)return false;
         sum/=k;
         bool ans= false;
         vector<bool>vis(n,false);
         solve(a,k,0,0,ans,sum,vis,n);
         return ans;
    }
    void solve(int a[],int k,int curSum,int cnt,bool &ans,int sum,vector<bool>&vis,int n){
        if(cnt==k-1){
            ans=true;
            return;
        }
        if(curSum>sum){
            return;
        }
        if(curSum==sum){
            return solve(a,k,0,cnt+1,ans,sum,vis,n);
            // if(ans==true)return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                solve(a,k,curSum+a[i],cnt,ans,sum,vis,n);
                if(ans==true){
                    return;
                }
                vis[i]=false;
            }
        }
        return;    
    }

};
