class Solution {
public:
    int findAns(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(i==-1) return j+1;
        if(j==-1) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=findAns(i-1,j-1,s1,s2,dp);
        return dp[i][j]= 1+min({findAns(i-1,j,s1,s2,dp),findAns(i-1,j-1,s1,s2,dp),findAns(i,j-1,s1,s2,dp)});
    }
    int minDistance(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return findAns(s1.size()-1,s2.size()-1,s1,s2,dp);
    }
};