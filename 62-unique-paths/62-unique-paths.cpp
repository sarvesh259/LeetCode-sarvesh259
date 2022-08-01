class Solution {
public:
    int f(vector<vector<int>> &dp,int m,int n)
    {
        //cout<<m<<" "<<n<<endl;
        if(n==1&&m==1)
        {
            return 1;
        }
        if(m<1||n<1)
        {
            return 0;
        }
        if(dp[m][n]!=-1)
            return dp[m][n];
        int p=0,q=0;
        p+=f(dp,m,n-1);
        q+=f(dp,m-1,n);
        return dp[m][n]=p+q;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+2,vector<int>(n+2,-1));
        return f(dp,m,n);
    }
};