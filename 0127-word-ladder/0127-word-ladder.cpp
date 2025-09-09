class Solution {
public:
    int dist(string &word1,string &word2)
    {
        int dist=0;
        for(int i=0;i<word1.size();i++)
        {
            if(word1[i]!=word2[i])
            {
                dist++;
            }
        }
        return dist;
    }
    int bfs(int src, int dest, vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> dist(n, -1); // -1 means unvisited
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == dest) return dist[u]; // found shortest distance

        for (int v : adj[u]) {
            if (dist[v] == -1) { // not visited
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1; // no path found
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int idx=-1;
        wordList.push_back(beginWord);
        int n=wordList.size();
        for(int i=0;i<n;i++)
        {
            if(wordList[i]==endWord)
            {
                idx=i;
                break;
            }
        }
        if(idx==-1)
            return 0;
        cout<<idx<<" IDX"<<endl;
        vector<vector<int>> v(n);
        wordList.push_back(beginWord);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dist(wordList[i],wordList[j])==1)
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,false);
        int ans=bfs(n-1,idx,v);
        return (ans==-1)?0:ans+1;
    }
};