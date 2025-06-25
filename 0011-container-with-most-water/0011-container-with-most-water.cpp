class Solution {
public:
    int maxArea(vector<int>& h) {
        int mx=0;
        int l=0,r=h.size()-1;
        while(l<r)
        {
            mx=max(mx,(min(h[l],h[r])*(r-l)));
            if(h[l]<=h[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return mx;
    }
};