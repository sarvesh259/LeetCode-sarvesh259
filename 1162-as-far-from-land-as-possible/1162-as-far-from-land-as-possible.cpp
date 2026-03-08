class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
       queue<pair<int,int>> q;
       int n=grid.size();
       for(int i=0;i<n;i++)
       {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
       }
       int ans=0;
       vector<vector<int>> dis={{0,1},{1,0},{-1,0},{0,-1}};
       while(!q.empty())
       {
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newI=p.first+dis[i][0];
                int newJ=p.second+dis[i][1];
                if(newI>=0&&newJ>=0&&newI<n&&newJ<n&&grid[newI][newJ]==0)
                {
                    q.push({newI,newJ});
                    grid[newI][newJ]=grid[p.first][p.second]+1;
                    ans=max(ans,grid[newI][newJ]);
                }
            }
       }
       return ans-1; 
    }
};