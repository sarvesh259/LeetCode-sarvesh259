class Solution {
public:
    bool isValidPlace(int i,int j,int n,vector<vector<bool>> &chess)
    {
        for(int k=0;k<i;k++)
        {
            if(chess[k][j])
                return false;
        }
        int tempi=i,tempj=j;
        while(tempi>=0&&tempj>=0)
        {
            if(chess[tempi][tempj]) return false;
            tempi--;
            tempj--;
        }
        tempi=i,tempj=j;
        while(tempi>=0&&tempj<n)
        {
            if(chess[tempi][tempj]) return false;
            tempi--;
            tempj++;
        }
        return true;
    }
    int backtrack(int i,int n,vector<vector<bool>> &chess)
    {
        if(i==n)
            return 1;
        int ans=0;
        for(int k=0;k<n;k++)
        {
            if(isValidPlace(i,k,n,chess))
            {
                chess[i][k]=true;
                ans+=backtrack(i+1,n,chess);
                chess[i][k]=false;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<vector<bool>> chess(n,vector<bool>(n,false));
        return backtrack(0,n,chess);
    }
};