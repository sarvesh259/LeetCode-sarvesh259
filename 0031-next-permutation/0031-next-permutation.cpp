class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        int p=-1;
        for(int i=n;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                p=i-1;
                break;
            }
        }
        // cout<<p<<q<<endl;
        if(p==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n;i>0;i--)
        {
            if(nums[p]<nums[i])
            {
                swap(nums[i],nums[p]);
                break;
            }
        }
        // int temp=nums[p];
        // nums[p]=nums[q];
        // nums[q]=temp;
        reverse(nums.begin()+p+1,nums.end());
        return;
    }
};