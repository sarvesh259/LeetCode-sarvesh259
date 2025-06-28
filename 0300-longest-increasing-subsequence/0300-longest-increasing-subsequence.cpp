class Solution {
public:
    int f(int cur,int prev,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(cur==nums.size()) return 0;
        if(dp[cur][prev+1]!=-1)
            return dp[cur][prev+1];
        int ans=f(cur+1,prev,nums,dp);
        if(prev==-1||nums[prev]<nums[cur])
        {
            ans=max(ans,1+f(cur+1,cur,nums,dp));
        }
        return dp[cur][prev+1]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return f(0,-1,nums,dp);
    }
};