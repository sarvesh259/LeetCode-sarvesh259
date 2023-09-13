class Solution {
public:
    bool f(int i,int j,vector<int> adj[],vector<bool> &vis)
    {
        if(i==j)
            return true;
        vis[i]=true;
        for(auto node:adj[i])
        {
            if(!vis[node])
            {
                if(f(node,j,adj,vis))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,0);
        return f(source,dest,adj,vis);
    }
};