//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int node,vector<int> adj[],vector<int> &ans,vector<bool> &vis)
    {
        vis[node]=1;
        ans.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
                dfs(it,adj,ans,vis);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // stack<int> st;
        vector<int> ans;
        vector<bool> vis(V,0);
        dfs(0,adj,ans,vis);
        // for(int i=0;i<V;++i)
        // {
        //     if(!vis[i])
        //     {
        //         st.push(i);
        //     }
        //     while(!st.empty())
        //     {
        //         int temp=st.top();
        //         st.pop();
        //         vis[temp]=1;
        //         ans.push_back(temp);
        //         for(auto it:adj[temp])
        //         {
        //             if(!vis[it])
        //                 st.push(it);
        //         }
        //     }
        // }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends