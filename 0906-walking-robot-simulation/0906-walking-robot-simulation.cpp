class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int a[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        map<int,set<int>> v;
        for(auto i:obstacles)
        {
            v[i[0]].insert(i[1]);
        }
        int j=0;
        long long maxi=0;
        long long x=0,y=0;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]<0)
            {
                if(commands[i]==-1)
                {
                    j=(j+1)%4;
                }
                else{
                    j-=1;
                    if(j==-1)
                    {
                        j=3;
                    }
                }
            }
            else
            {
                for(int k=0;k<commands[i];k++)
                {
                    if(v[(x+a[j][0])].find((y+a[j][1]))!=v[x+a[j][0]].end())
                    {
                        break;
                    }
                    else
                    {
                        x+=a[j][0];
                        y+=a[j][1];
                    }
                }
            }
            maxi=max(maxi,(x*x)+(y*y));
        }
        return maxi;
    }
};