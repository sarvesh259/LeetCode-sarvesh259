class Solution {
public:
    bool dfs(int ind,int col,vector<vector<int>>& graph,vector<int> &vis)
    {
        vis[ind]=col;
        for(auto &i:graph[ind])
        {
            if(vis[i]==-1)
            {
                bool temp=dfs(i,(col^1),graph,vis);
                if(!temp) return false;
            }
            else if(vis[i]==col)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int k=0;k<n;k++)
        {
            if(vis[k]==-1)
            {
                bool temp=dfs(k,0,graph,vis);
                if(!temp) return false;
            }
        }
        return true;
    }
};