class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int maxi=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1)
                {
                    freshOranges++;
                }
            }
        }
        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int level=q.front().second;
            maxi=max(maxi,level);
            q.pop();
            int dCol[4]={0,1,0,-1};
            int dRow[4]={1,0,-1,0};
            for(int k=0;k<4;k++)
            {
                int adjI=i+dCol[k];
                int adjJ=j+dRow[k];
                if(adjI>=0&&adjJ>=0&&adjI<m&&adjJ<n&&vis[adjI][adjJ]!=2&&grid[adjI][adjJ]==1)
                {
                    q.push({{adjI,adjJ},level+1});
                    vis[adjI][adjJ]=2;
                    freshOranges--;
                }
            }
        }
        if(freshOranges) return -1;
        return maxi;
    }
};