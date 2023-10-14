class Solution {
public:
    int f(int ind,int n,vector<int> &cuts,int l,int r,vector<vector<int>> &dp)
    {
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int res=1e9;
        for(int i=l;i<=r;++i)
        {
            int lc=f(ind,cuts[i],cuts,l,i-1,dp);
            int rc=f(cuts[i],n,cuts,i+1,r,dp);
            int mini=n-ind+lc+rc;
            res=min(res,mini);
        }
        return dp[l][r]=res;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return f(0,n,cuts,0,cuts.size()-1,dp);
    }
};