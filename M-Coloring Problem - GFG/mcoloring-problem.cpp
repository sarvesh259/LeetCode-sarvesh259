//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool issafe(int c,int node,bool graph[101][101],vector<int> &a,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(i!=node&&graph[node][i])
            {
                if(a[i]==c)
                    return false;
            }
        }
        return true;
    }
    bool f(int node,vector<int> &a,bool graph[101][101], int m, int n)
    {
        if(node==n)
            return true;
        for(int i=1;i<=m;i++)
        {
            if(issafe(i,node,graph,a,n))
            {
                a[node]=i;
                if(f(node+1,a,graph,m,n)) return true;
                a[node]=-1;
                
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> a(n,-1);
        return f(0,a,graph,m,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends