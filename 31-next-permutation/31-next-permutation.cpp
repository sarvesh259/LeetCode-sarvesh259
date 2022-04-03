class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        int i=size-2;
        for(;i>=0&&nums[i]>=nums[i+1];--i) ;
        
        int j=i+1;
        int k=size-1;
        while(j<k)
        {
            swap(nums[j],nums[k]);
            ++j;
            --k;
        }
        if(i==-1)
            return;
        
        for(j=i+1;j<size;++j)
        {
            if(nums[j]>nums[i])
            {
                swap(nums[i],nums[j]);
                break;
            }
        }
    }
};