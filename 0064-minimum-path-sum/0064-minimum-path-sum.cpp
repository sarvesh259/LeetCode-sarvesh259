class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
            dp[i][0]=grid[i][0]+dp[i-1][0];
        for(int i=1;i<n;i++)
            dp[0][i]=grid[0][i]+dp[0][i-1];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                int up=0,left=0;
                if(i>0)
                    up=dp[i-1][j];
                if(j>0)
                    left=dp[i][j-1];
                dp[i][j]=min(up,left)+grid[i][j];
            }
        }
        // for(auto i:dp)
        // {
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        return dp[m-1][n-1];
    }
};