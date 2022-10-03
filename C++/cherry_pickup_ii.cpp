class Solution {
public:
    
    // 3D -> 2D
    
    int solve(int i , int j1, int j2, int rows,int  m, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        if(j1<0 || j2<0 || j1>=m || j2>=m)
        {
            return -1e8;
        }
        if(i==rows-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)
        {
            return dp[i][j1][j2];
        }
        
        // explore all paths 
        int mx = -1e8;
        for(int d1 =-1; d1<=1; d1++)
        {
            for(int d2 = -1; d2<=1; d2++)
            {
                int value=0;
                if(j1==j2)
                {
                   value = grid[i][j1] ;
                }
                else
                {
                   value = grid[i][j1] + grid[i][j2] ;
                }
                value +=  solve(i+1, j1+d1, j2+d2, rows, m, grid, dp);
                mx = max(mx, value);
            }
        }
        return dp[i][j1][j2] = mx;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        // dp[r][c][c];
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        vector<vector<int>> front(m, vector<int>(m,0));
        vector<vector<int>> curr(m, vector<int>(m,0));
        
        // return solve(0, 0, m-1, n,m, grid, dp);
        
        // base cases
        for(int j1 =0; j1<m; j1++)
        {
            for(int j2=0; j2<m ;j2++)
            {
                if(j1==j2)
                {
                    front[j1][j2] = grid[n-1][j1];
                }
                else
                {
                    front[j1][j2] = grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }
        
        for(int i = n-2; i>=0; i--)
        {
            for(int j1=0; j1<m; j1++)
            {
                for(int j2=0; j2<m; j2++)
                {
                     int mx = -1e8;
                for(int d1 =-1; d1<=1; d1++)
                {
                    for(int d2 = -1; d2<=1; d2++)
                    {
                        int value=0;
                        if(j1==j2)
                        {
                        value = grid[i][j1] ;
                        }
                        else
                        {
                        value = grid[i][j1] + grid[i][j2] ;
                        }
                        if(j1+d1>=0 && j1+d1<m && j2+d2>=0 && j2+d2<m)
                        {
                        value +=  front[j1+d1][j2+d2] ;
                        }
                        else
                        {
                        value+= -1e8;
                        }
                        mx = max(mx, value);
                    }
                }
                curr[j1][j2] = mx;
            }
        }
            front = curr;
    }
        
        return front[0][m-1];
    }
};
