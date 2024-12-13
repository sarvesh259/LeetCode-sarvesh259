class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& s) {
        map<long long,long long> mp;
        for(auto i:s)
        {
            mp[i[0]]+=i[2];
            mp[i[1]]-=i[2];
        }
        long long col=0,last=-1;
        vector<vector<long long>> ans;
        for(auto i:mp)
        {
            if(col!=0&&last!=-1)
            {
                ans.push_back({last,i.first,col});
            }
            last=i.first;
            col+=i.second;
        }
        return ans;
    }
};