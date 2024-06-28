class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> a(n,0);
        for(auto i:roads)
        {
            a[i[0]]++;
            a[i[1]]++;
        }
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(a[i]);
        }
        long long ans=0;
        while(!pq.empty())
        {
            ans+=pq.top()*1LL*n*1LL;
            n--;
            pq.pop();
        }
        return ans;
    }
};