class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n=isConnected.size();
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int temp=q.front();
                    q.pop();
                    vis[temp]=true;
                    for(int j=0;j<n;j++)
                    {
                        if(temp!=j&&!vis[j]&&isConnected[temp][j]==1)
                        {
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};