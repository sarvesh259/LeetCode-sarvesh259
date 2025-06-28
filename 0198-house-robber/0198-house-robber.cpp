class Solution {
public:
    int rob(vector<int>& nums) {
        int maxi=0,curr=0;
        for(auto &i:nums)
        {
            int temp=max(maxi,curr+i);
            curr=maxi;
            maxi=temp;
        }
        return maxi;
    }
};