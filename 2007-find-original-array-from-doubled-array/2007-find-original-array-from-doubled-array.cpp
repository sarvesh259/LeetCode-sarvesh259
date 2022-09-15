class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        vector<int> ans;
        map<int,int> mp;
        if(a.size()&1)
            return {};
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
        {
            mp[a[i]]++;
        }
        for(int i=0;i<a.size();i++)
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