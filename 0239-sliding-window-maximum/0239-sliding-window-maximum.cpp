class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1)
            return nums;

        vector<int> ans;
        deque<int> q;
        int n = nums.size();

        int l = 0, r = 0;

        while (r < n) {
            while (!q.empty() && (nums[q.back()] < nums[r])) {
                q.pop_back();
            }
            q.push_back(r);
            if (l > q.front()) {
                q.pop_front();
            }
            if (r + 1 >= k) {
                ans.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }
        return ans;
    }
};