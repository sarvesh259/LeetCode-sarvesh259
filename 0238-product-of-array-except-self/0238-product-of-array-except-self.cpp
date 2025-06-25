class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        int sz=n.size();
        int noz=0;
        for(auto &i:n)
        {
            if(i==0)
                noz++;
        }
        vector<int> ans(sz,0);
        if(noz>1) return ans;
        long product=1;
        for(auto &i:n)
        {
            if(i!=0)
            {
                product*=i;
            }
        }
        for(int i=0;i<sz;i++)
        {
            if(noz==1)
            {
                if(n[i]==0)
                {
                    ans[i]=product;
                    return ans;
                }
            }
            else
            {
                ans[i]=product/n[i];
            }
        }
        return ans;
    }
};