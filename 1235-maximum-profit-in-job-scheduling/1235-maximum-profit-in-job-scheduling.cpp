class Solution {
public:
    int bfs(int ind,vector<vector<int>> &v,vector<int> &dp)
    {
        if(ind>=v.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int res=bfs(ind+1,v,dp);
        int j = lower_bound(
            v.begin() + ind + 1, v.end(),
            vector<int>{v[ind][1], 0, 0}
        ) - v.begin();
        res=max(res,v[ind][2]+bfs(j,v,dp));
        return dp[ind]=res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        for(int i=0;i<startTime.size();i++)
        {
            vector<int> temp;
            temp.push_back(startTime[i]);
            temp.push_back(endTime[i]);
            temp.push_back(profit[i]);
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        vector<int> dp(startTime.size(),-1);
        return bfs(0,v,dp);
    }
};