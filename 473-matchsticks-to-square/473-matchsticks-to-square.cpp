class Solution {
public:
    bool f(vector<int>& ans,vector<int>& m,int ind,int target)
    {
        if(ind==m.size())
        {
            return ans[0]==ans[1]&&ans[1]==ans[2]&&ans[2]==ans[3];
        }
        for(int i=0;i<4;++i)
        {
            if (ans[i] + m[ind] > target)
                continue;
            int j = i;
            while (--j >= 0)
                if (ans[i] == ans[j]) 
                    break;
            if (j != -1) continue;
            ans[i] += m[ind];
            if (f(ans, m, ind + 1, target))
                return true;
            ans[i] -= m[ind];
        }
        return false;
    }
    bool makesquare(vector<int>& m) {
        if(m.size()<4) return false;
        int sum=0,target;
        for(int i=0;i<m.size();i++)
        {
            sum+=m[i];
        }
        if(sum%4!=0) return false;
        target =sum/4;
        sort(m.begin(),m.end());
        if(m[m.size()-1]>target) return false;
        vector<int> ans(4,0);
        return f(ans,m,0,target);
    }
};
