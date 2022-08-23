class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    dp[i][j]=1;
                }
                else{
                    int down=0,right=0;
                    if(i-1>=0)
                    {
                        down=dp[i-1][j];
                    }
                    if(j-1>=0)
                    {
                        right=dp[i][j-1];
                    }
                    dp[i][j]=right+down;
                }
            }
        }
        return dp[m-1][n-1];
    }
};