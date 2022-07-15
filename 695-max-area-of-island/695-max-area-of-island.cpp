class Solution {
public:
    int f(vector<vector<int>>& g,int i,int j)
    {
        int size=1;
        g[i][j]=0;
        if(j>0)
        {
            if(g[i][j-1]==1)
            {
                size+=f(g,i,j-1);
            }
        }
        if(i>0)
        {    if(g[i-1][j]==1)
            {
                size+=f(g,i-1,j);
            }
        }
        if(i+1<g.size())
        {
            if(g[i+1][j]==1)
            {
                size+=f(g,i+1,j);
            }
        }
        if(j+1<g[0].size())
        {
             if(g[i][j+1]==1)
            {
                size+=f(g,i,j+1);
            }
        }
        return size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(grid[i][j]==1)
                {
                    ans=max(ans,f(grid,i,j));
                }
            }
        }
        return ans;
    }
};