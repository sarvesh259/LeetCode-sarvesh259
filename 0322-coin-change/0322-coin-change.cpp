class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        vector<int> prev(amount+1,INT_MAX-1),cur(amount+1,0);
        prev[0]=0;
        // for (int j = 1; j < amount + 1; j++)
        //     dp[0][j] =  INT_MAX - 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]>j)
                    cur[j]=prev[j];
                else
                    cur[j]=min(prev[j],1+cur[j-coins[i-1]]);
            }
            prev=cur;
        }
        if(cur[amount]==INT_MAX-1)
            return -1;
        return cur[amount];
    }
};