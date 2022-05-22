class Solution {
public:
    #define LL long long
    int dp[10010];
    int coinchanges(int amount, vector<int>& coins)
    {
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int ans=INT_MAX;
        for(auto i: coins)
        {
            if(amount-i>=0)
            {
                 ans=min(ans+0LL,(coinchanges(amount-i,coins))+1LL);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans=coinchanges(amount,coins);
        if(ans==INT_MAX) return -1;
        else 
            return ans;
    }
};