class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp)
    {
        if(i==0&&j==0)
            return grid[0][0];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=1e9,left=1e9;
        if(i>0)
            up=f(i-1,j,grid,dp);
        if(j>0)
            left=f(i,j-1,grid,dp);
        return dp[i][j]=min(up,left)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return f(grid.size()-1,grid[0].size()-1,grid,dp);
    }
    // int f(int i,int j, vector<vector<int>> &a,vector<vector<int>> &dp)
    // {
    //     if(i==0&&j==0) return a[0][0];
    //     if(dp[i][j]!=-1)    return dp[i][j];
    //     int p[3]={-1,0};
    //     int q[3]={0,-1};
    //     int mini=1e9;
    //     for(int k=0;k<2;++k)
    //     {
    //         int ui=i+p[k],uj=j+q[k];
    //         if(ui>=0&&uj>=0)
    //         {
    //             int temp=f(ui,uj,a,dp);
    //             mini=min(mini,temp);
    //         }
    //     }
    //     return dp[i][j]=a[i][j]+mini;
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
    //     return f(grid.size()-1,grid[0].size()-1,grid,dp);
    // }
};