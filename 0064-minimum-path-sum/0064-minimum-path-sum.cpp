class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> prev(n,0),cur(n,0);
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)  cur[j]=grid[0][0];
                else
                {
                    int up=grid[i][j],left=grid[i][j];
                    if(i>0)
                        up+=prev[j];
                    else up=1e9;
                    if(j>0)
                        left+=cur[j-1];
                    else left=1e9;
                    cur[j]=min(up,left);
                }
            }
            prev=cur;
        }
        return prev[n-1];
    }
};