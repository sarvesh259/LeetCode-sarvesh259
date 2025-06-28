class Solution {
public:
    int f(int ind,vector<int> &nums,vector<int> &dp)
    {
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        return dp[ind]=max(nums[ind]+f(ind+2,nums,dp),f(ind+1,nums,dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};