class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)
            return;
        int k=-1;
        int sz=nums.size();
        for(int i=sz-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                k=i;
                break;
            }
        }
        if(k==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=sz-1;i>k;i--)
        {
            if(nums[i]>nums[k])
            {
                swap(nums[i],nums[k]);
                break;
            }
        }
        sort(nums.begin()+k+1,nums.end());
    }
};