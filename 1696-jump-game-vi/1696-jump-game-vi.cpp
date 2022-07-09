class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> dp(nums.size(), -1);
        
        dp[len-1] = nums[len-1];
        multiset<int> ms;
        ms.insert(dp[len-1]);
        
        for(int i=len-2;i>=0; --i) {
			// Erase the oldest value i.e. the one which was inserted the earliest => i+k+1
            if(ms.size() > k) {
                ms.erase(ms.find(dp[i+k+1]));
            }
            dp[i] = *ms.rbegin()+nums[i];
            ms.insert(dp[i]);
        }
        
        return dp[0];
    }
};