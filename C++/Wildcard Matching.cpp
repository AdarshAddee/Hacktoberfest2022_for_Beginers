// leetcode hard question 

class Solution {
public:
    bool isMatch(string s, string p) {
       int n=p.size(); //having * and ? character
       int m=s.size();
        
       vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int j=0;j<=m;j++){
            dp[0][j]=false;
        }
        bool check=true;
        for(int i=1;i<=n;i++){
            if(p[i-1]!='*' and check) check=false;
            dp[i][0]=check;
        }
        dp[0][0]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==s[j-1] or p[i-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='*') dp[i][j]=dp[i-1][j] or dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};