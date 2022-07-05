class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<1)
            return nums.size();
        sort(nums.begin(),nums.end());
        int maxi=1,temp=1;
         //for(int i=0;i<nums.size();i++)
           //  cout<<nums[i]<<" ";
        for(int i=1;i<nums.size();i++)
        {
          //  cout<<nums[i]<<" "<<(nums[i-1]+1)<<endl;
            cout<<temp<<" ";
            if(nums[i]==nums[i-1]+1)
            {
                temp++;
            }
            else if(nums[i]-nums[i-1]==0)
            {
                continue;
            }
            else{
                maxi=max(maxi,temp);
                temp=1;
            } 
        }
         maxi=max(maxi,temp);
        return maxi;
        
    }
};