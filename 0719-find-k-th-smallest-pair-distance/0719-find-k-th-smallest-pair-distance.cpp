class Solution {
public:
    int countPairs(vector<int> &nums, int diff)
    {
        int left=0;
        int count=0;
        for(int right=0;right<nums.size();right++)
        {
            while(nums[right]-nums[left]>diff)
            {
                left++;
            }
            count+=right-left;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0,right =nums[n-1]-nums[0];
        while(left<right)
        {
            int mid=((right+left)/2);
            int count=countPairs(nums,mid);
            if(count>=k)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};