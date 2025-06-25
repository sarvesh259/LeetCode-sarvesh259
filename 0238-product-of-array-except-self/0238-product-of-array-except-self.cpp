class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n = nums.size();
        vector<int> result(n, 1);
        
        int prefix = 1;
        int postfix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = result[i]*prefix;
            result[n-1-i] = result[n-1-i] * postfix;
            prefix = prefix * nums[i];
            postfix = postfix * nums[n-1-i];
        }
        return result;
    }
};