class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);int ans=0,sum=0;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            sum+=(nums[i]==0?-1:1);
            // cout<<sum<<endl;
            if(sum==0)
                ans=i+1;
            else
            {
                if(mp.find(sum)!=mp.end())
                    ans=max(ans,i-mp[sum]);
                else
                    mp[sum]=i;
            }
        }
        // for(auto i:mp)
        // cout<<i.first<<" "<<i.second<<endl;
       
        return ans;
    }
};