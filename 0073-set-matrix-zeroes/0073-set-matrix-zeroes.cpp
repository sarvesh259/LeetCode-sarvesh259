class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int colSize=matrix.size(),rowSize=matrix[0].size(),col1=matrix[0][0];
        for(int i=0;i<colSize;i++)
        {
            for(int j=0;j<rowSize;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    if(j==0)
                    {
                        col1=0;
                    }
                    else
                    {
                        matrix[0][j]=0;
                    }

                }
            }
        }
        for(int i=1;i<colSize;i++)
        {   
            for(int j=1;j<rowSize;j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0)
        {
            for(int i=1;i<rowSize;i++)
            {
                matrix[0][i]=0;
            }
        }
        if(col1==0)
        {
            for(int i=0;i<colSize;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};