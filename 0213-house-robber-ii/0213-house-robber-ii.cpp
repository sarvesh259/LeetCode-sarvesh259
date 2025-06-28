class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int cur1=0,cur2=0,maxi1=0,maxi2=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            int temp1=max(maxi1,cur1+nums[i]);
            cur1=maxi1;
            maxi1=temp1;
            int temp2=max(maxi2,cur2+nums[i+1]);
            cur2=maxi2;
            maxi2=temp2;
        }
        return max(maxi1,maxi2);
    }
};