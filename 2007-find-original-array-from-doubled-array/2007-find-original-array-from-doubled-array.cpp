class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n=a.size();
        if(n&1)
            return {};
        sort(a.begin(),a.end());
        for(int i=0;i<n;++i)
        {
            mp[a[i]]++;
        }
        for(int i=0;i<n;++i)
        {
            if(mp[a[i]]==0)
                continue;
            if(mp[a[i]*2]==0)
                return {};
            ans.push_back(a[i]);
            mp[a[i]]--;
            mp[a[i]*2]--;
        }
        return ans;
    }
};