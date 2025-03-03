class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int temp=1;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0)
                    {
                        temp=0;
                    }
                    else
                    {
                        matrix[i][0]=0;
                    }
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<matrix[0].size();i++)
        {
            if(matrix[0][i]==0)
            {
                for(int j=0;j<matrix.size();j++)
                {
                    matrix[j][i]=0;
                }
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=0;j<matrix[0].size();j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(temp==0)
        {
            for(int j=0;j<matrix[0].size();j++)
                {
                    matrix[0][j]=0;
                }
                for(int j=0;j<matrix.size();j++)
                {
                    matrix[j][0]=0;
                }
        }
        // return matrix;
    }
};