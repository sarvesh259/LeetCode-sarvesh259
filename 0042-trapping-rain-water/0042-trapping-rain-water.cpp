class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int l=0,lMax=0,rMax=0,r=n-1,ans=0;
        while(l<r)
        {
            if(h[l]<=h[r])
            {
                if(lMax>h[l])
                {
                    ans+=lMax-h[l];
                }
                else
                {
                    lMax=h[l];
                }
                l++;
            }
            else
            {
                if(rMax>h[r])
                {
                    ans+=rMax-h[r];
                }
                else
                {
                    rMax=h[r];
                }
                r--;
            }
        }
        return ans;
    }
};