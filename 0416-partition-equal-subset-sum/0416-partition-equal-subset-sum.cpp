class Solution {
public:
    bool f(int i,int sum,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(sum==0)
            return true;
        if(i<0)
            return false;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        bool pick=0,notpick=0;
        if(sum>=nums[i])
            pick=f(i-1,sum-nums[i],nums,dp);
        notpick=f(i-1,sum,nums,dp);
        return dp[i][sum]=pick|notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2)
            return 0;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        return f(n-1,sum/2,nums,dp);
    }
};