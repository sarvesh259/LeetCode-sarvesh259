class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        sort(nums.begin(),nums.end());
        int maxi=nums[j];
        if(j<2)
            return maxi;
        while(j--)
        {
            if(nums[j]<maxi)
            {
                maxi=nums[j];
                i++;
                if(i==2)
                    return maxi;
            }
        }        
        return nums[nums.size()-1];
    }
};