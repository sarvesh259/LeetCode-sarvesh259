class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> a(n,0);
        for(auto i:roads)
        {
            a[i[0]]++;
            a[i[1]]++;
        }
        sort(a.begin(),a.end(),greater<int>());
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(n-i)*1LL*a[i];
        }
        return ans;
    }
};