class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int left=0,right=0;
        int sum=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int cur=nums[0];
        while(left<n&&right<n){
            if(cur<sum-x){
                
                right++;
                if(right==n)break;
                cur+=nums[right];
            }
            if(cur>sum-x){
                
                cur-=nums[left];
                
                left++;
            }
            if(cur==sum-x){
                ans=max(ans,right-left+1);
                right++;
                if(right==n)break;
                cur+=nums[right];
            }
        }
        return ans==-1?-1:n-ans;
    }
};