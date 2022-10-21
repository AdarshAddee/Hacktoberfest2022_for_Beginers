class Solution {
public:
    long  maxprofit(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(ind==prices.size())
        {
            return 0;
        }
        if(dp[ind][buy]!=-1)
        {
            return dp[ind][buy];
        }
        long profit=0;
        if(buy)
        {
            profit=max(-prices[ind]+maxprofit(ind+1,0,prices,dp),maxprofit(ind+1,1,prices,dp));
        }
        else
        {
            profit=max(prices[ind]+maxprofit(ind+1,1,prices,dp),maxprofit(ind+1,0,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return maxprofit(0,1,prices,dp);
    }
    
    
};
