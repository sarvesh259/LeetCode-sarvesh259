class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a,b;
        vector<int> s;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    s.push_back(i);
                    s.push_back(j);
                    break;
                }
            }
        }
        return s;
    }
};