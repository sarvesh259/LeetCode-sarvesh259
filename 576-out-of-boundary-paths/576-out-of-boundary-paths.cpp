class Solution {
public:
    long long int mod=1e9 + 7;
    int f(int m,int n,int s,int sr,int sc,vector<vector<vector<int>>> &dp)
    {
      //  int ans=0;
        if(s<0)
            return 0;
        if(sr<0||sc<0||sr>=m||sc>=n)
        {
            return 1;
        }
        if(dp[sr][sc][s]!=-1)
            return dp[sr][sc][s];
        //cout<<ans<<" ";
        int down=f(m,n,s-1,sr-1,sc,dp);
        //cout<<ans<<" ";
        int up=f(m,n,s-1,sr+1,sc,dp);
       // cout<<ans<<" ";
        int left=f(m,n,s-1,sr,sc-1,dp);
      //  cout<<ans<<" ";
        int right=f(m,n,s-1,sr,sc+1,dp);
      //  cout<<ans<<" ";
        return dp[sr][sc][s]=((down%mod)+(up%mod)+(left%mod)+(right%mod))%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return f(m,n,maxMove,startRow,startColumn,dp);
        
    }
};