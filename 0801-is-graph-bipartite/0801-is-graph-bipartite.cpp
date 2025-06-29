class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int k=0;k<n;k++)
        {
            if(vis[k]==-1)
            {
                queue<int> q;
                q.push(k);
                vis[k]=1;
                while(!q.empty())
                {
                    int t=q.front();
                    q.pop();
                    for(auto i:graph[t])
                    {
                        if(vis[i]==-1)
                        {
                            q.push(i);
                            vis[i]=vis[t]^1;
                        }
                        else if(vis[i]==vis[t])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};