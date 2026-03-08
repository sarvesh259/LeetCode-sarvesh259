class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int t=target-nums[i];
            if(mp[t]){
                return {mp[t],i};
            }
            if(t==nums[0]&&i!=0)
            {
                return {0,i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};