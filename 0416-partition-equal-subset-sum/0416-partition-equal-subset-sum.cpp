class Solution {
public:
    // bool f(int i,int sum,vector<int> &nums,vector<vector<int>> &dp)
    // {
    //     if(sum==0)
    //         return true;
    //     if(i<0)
    //         return false;
    //     if(dp[i][sum]!=-1)
    //         return dp[i][sum];
    //     bool pick=0,notpick=0;
    //     if(sum>=nums[i])
    //         pick=f(i-1,sum-nums[i],nums,dp);
    //     notpick=f(i-1,sum,nums,dp);
    //     return dp[i][sum]=pick|notpick;
    // }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2)
            return 0;
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>((sum/2)+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=(sum/2);j++)
            {
                bool pick=0,notpick=0;
                if(j>=nums[i])
                    pick=dp[i-1][j-nums[i]];
                notpick=dp[i-1][j];
                dp[i][j]=pick|notpick;
            }
        }
        return dp[n-1][sum/2];
    }
};