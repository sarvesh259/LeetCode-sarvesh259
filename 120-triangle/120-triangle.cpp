class Solution {
public:
    int sol(int i,int n,int j,vector<vector<int>>& t,vector<vector<int>>& dp)
    {
        if(i==n)
        {
            return 0; 
        }
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=min(sol(i+1,n,j,t,dp)+t[i][j],sol(i+1,n,j+1,t,dp)+t[i][j+1]);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
        return sol(1,triangle.size(),0,triangle,dp)+triangle[0][0];
    }
};