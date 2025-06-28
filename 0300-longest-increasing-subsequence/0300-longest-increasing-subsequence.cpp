class Solution {
public:
    // int f(int cur,int prev,vector<int> &nums,vector<vector<int>> &dp)
    // {
    //     if(cur==nums.size()) return 0;
    //     if(dp[cur][prev+1]!=-1)
    //         return dp[cur][prev+1];
    //     int ans=f(cur+1,prev,nums,dp);
    //     if(prev==-1||nums[prev]<nums[cur])
    //     {
    //         ans=max(ans,1+f(cur+1,cur,nums,dp));
    //     }
    //     return dp[cur][prev+1]=ans;
    // }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cur(nums.size()+1,0),prev(nums.size()+1,0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=i-1;j>=-1;j--)
            {
                int ans=cur[j+1];
                if(j==-1||nums[j]<nums[i])
                {
                    ans=max(ans,1+cur[i+1]);
                }
                prev[j+1]=ans;
            }
            cur=prev;
        }
        return prev[0];
    }
};