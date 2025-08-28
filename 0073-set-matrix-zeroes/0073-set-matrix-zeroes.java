class Solution {
    public void setZeroes(int[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;
        int[]row = new int[m];
        int[]col = new int[n];
        Arrays.fill(row,-1);
        Arrays.fill(col,-1);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(matrix[i][j]==0)
               {
                    row[i]=0;
                    col[j]=0;
               } 
            }
        }
        for(int i=0;i<m;i++)
        {
            if(row[i]==0)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(col[i]==0)
            {
                for(int j=0;j<m;j++)
                {
                    matrix[j][i]=0;
                }
            }
        }
    }
}