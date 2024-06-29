class Solution {
public:
    void travel(int m,int n,vector<vector<int>> &graph,vector<vector<int>> &ans,vector<bool> &vis)
    {
        for(auto i:graph[m])
        {
            if(!vis[i])
            {
                ans[i].push_back(n);
                vis[i]=true;
                travel(i,n,graph,ans,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n),ans(n);
        for(auto i:edges)
        {
            graph[i[0]].push_back(i[1]);
        }
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n,false);
            travel(i,i,graph,ans,vis);
        }
        return ans;
    }
};