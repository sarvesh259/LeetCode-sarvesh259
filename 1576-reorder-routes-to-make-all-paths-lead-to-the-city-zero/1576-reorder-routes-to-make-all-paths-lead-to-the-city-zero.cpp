class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> con(n);
        for (auto i : connections) {
            con[i[1]].push_back(i[0]);
            con[i[0]].push_back(i[1] * -1);
        }
        queue<int> q;
        q.push(0);
        vector<bool> vis(n, false);
        int ans = 0;
        while (!q.empty()) {
            int temp = q.front();
            vis[temp] = true;
            q.pop();
            for (auto i : con[temp]) {
                int node=i;
                if(i<0)
                    node*=-1;
                if (node != temp && !vis[node]) {
                    if (i > 0) {
                        q.push(i);
                    } else {
                        q.push(-1 * i);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};