class Solution {
public:
    bool isValid(int i,int j,vector<vector<char>>& n)
    {
        cout<<i<<" "<<j<<endl;
       for(int k=((i/3)*3);k<((i/3)*3)+3;k++)
       {
           for(int l=((j/3)*3);l<((j/3)*3)+3;l++)
           {
                if((i!=k&&j!=l)&&n[i][j]==n[k][l])
                    return false;
           }
       }
       for(int k=0;k<9;k++)
       {
            if(k!=i&&n[k][j]==n[i][j])
            {
                return false;
            }
            if(k!=j&&n[i][k]==n[i][j])
            {
                return false;
            }
       }
       return true; 
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(!isValid(i,j,board))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};