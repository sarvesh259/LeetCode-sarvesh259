class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        long long ans=0;
        int mod=1e9+7;
        for(int i=0,j=0,k=0;i<n-2;i++)
        {
            while(j<=i||(j<n-1&&nums[j]<2*nums[i]))j++;
            while(k<j||(k<n-1&&nums[n-1]-nums[k]>=nums[k]-nums[i]))k++;
            ans=(ans+k-j)%mod;
        }
        return ans;
    }
};