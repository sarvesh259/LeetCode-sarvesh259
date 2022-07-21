class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            int target=-nums[i];
            int l=i+1;
            int r=nums.size()-1;
            while(l<r)
            {
                int s=nums[l]+nums[r];
                if(s<target)
                {
                    l++;
                }
                else if(s>target)
                {
                    r--;
                }
                else{
                    vector<int> temp={nums[i],nums[l],nums[r]};
                    ans.push_back(temp);
                    while(l<r&&nums[l]==temp[1])
                        l++;
                    while((l<r)&&nums[r]==temp[2])
                        r--;
                }
                 
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }
        return ans;
    }
};