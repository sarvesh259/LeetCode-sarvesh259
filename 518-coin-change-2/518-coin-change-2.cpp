class Solution {
public:
    int dp[300][10010];
    int func(int ind,int amount, vector<int>& coins)
    {
        if(amount==0) return 1;
        if(ind<0) return 0;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int ans=0;
        for(int i=0;i<=amount;i+=coins[ind])
        {
            if(amount>=i)
            {
                ans=ans+func(ind-1,amount-i,coins);
            }
        }
        return dp[ind][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return func(coins.size()-1,amount,coins);
    }
};