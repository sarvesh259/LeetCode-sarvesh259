class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n);
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n);
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    temp[j]=1;
                }
                else{
                    int down=0,right=0;
                    if(i-1>=0)
                    {
                        down=cur[j];
                    }
                    if(j-1>=0)
                    {
                        right=temp[j-1];
                    }
                    temp[j]=right+down;
                }
                for(auto t:temp)
                {
                    cout<<t<<" ";
                }
                cout<<endl;
                
            }
            cur=temp;
        }
        return cur[n-1];
    }
};