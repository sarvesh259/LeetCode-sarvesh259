class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        //vector<vector<int>> ans;
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++)
        {
            int l=i+1;
            int r=nums.size()-1;
            while(l<r)
            {
                int s=nums[l]+nums[r]+nums[i];
                if(s<target)
                {
                    if(abs(s-target)<abs(ans-target))
                        ans=s;
                    l++;
                }
                else if(s>target)
                {
                    if(abs(s-target)<abs(ans-target))
                        ans=s;
                    r--;
                }
                else{
                    return target;
                }
                 
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }
        return ans;
    }
};