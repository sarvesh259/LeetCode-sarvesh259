class Solution {
public:
 int f(int ind,int n,vector<int> & a,vector<int> &dp)
    {
        if(ind+a[ind]>=n-1)
        {
            // cout<<ind<<" ";
            return 1;
        }
        if(dp[ind]!=-1)
            return dp[ind];
        int temp=1e9;
        for(int i=1;i<=a[ind];i++)
        {
            temp=min(temp,1+f(ind+i,n,a,dp));
        }
        return dp[ind]=temp;
    }
    int jump(vector<int>& a) {
        int n=a.size();
        // if(a[0]==0)
        //     return 0;
        if(n==1)
            return 0;
         vector<int> dp(n,-1);
        int ans=f(0,n,a,dp);
        if(ans>=1e9)
            return -1;
        return ans;
        
    }
};