class Solution {
public:
    int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(i==s1.size()||j==s2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=1+f(i+1,j+1,s1,s2,dp);
        int ans=f(i+1,j,s1,s2,dp);
        ans=max(ans,f(i,j+1,s1,s2,dp));
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return f(0,0,s1,s2,dp);
    }
};