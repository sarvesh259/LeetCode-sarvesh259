class Solution {
public:
    int trap(vector<int>& h) {
        int total=0;
        int rMax=h[h.size()-1];
        int lMax=h[0];
        int l=0;
        int r=h.size()-1;
        while(l<r)
        {
            if(h[l]<=h[r])
            {
                if(lMax>h[l])
                {
                    total+=lMax-h[l];
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
                    total+=rMax-h[r];
                }
                else
                {
                    rMax=h[r];
                }
                r--;
            }
        }
        return total;
    }
};