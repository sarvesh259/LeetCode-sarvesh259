class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==0)
            return ans;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==1)
            return ans;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==2)
            return ans;
        for(int i=3;i<=numRows;i++)
        {
            temp.clear();
            for(int j=1;j<=i;j++)
            {
                if(j==1||j==i)
                    temp.push_back(1);
                else 
                    temp.push_back(ans[i-1-1][j-1]+ans[i-1-1][j-1-1]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};