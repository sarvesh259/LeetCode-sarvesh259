class Solution {
public:
    int minPathSum(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> prev(n,0),cur(n,0);
        prev[0]=mat[0][0];
        for(int i=1;i<n;i++)
        {
            prev[i]=mat[0][i]+prev[i-1];
        }
        for(int i=1;i<m;i++)
        {
            cur[0]=prev[0]+mat[i][0];
            for(int j=1;j<n;j++)
            {
                cur[j]=mat[i][j]+min(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[n-1];
    }
};