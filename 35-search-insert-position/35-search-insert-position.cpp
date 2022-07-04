class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[nums.size()-1]<target) return nums.size();
        if(nums[0]>target) return 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<target&&nums[i+1]>=target)
            {
                return i+1;
            }
        }
        return 0;
    }
};