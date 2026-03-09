class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lmax=0,rmax=n-1,l=0,r=n-1;
        int ans=0;
        while(l<=r)
        {
            if(height[l]>height[lmax]){
                lmax=l;
            }
            if(height[r]>height[rmax]){
                rmax=r;
            }
            if(height[l]<height[r]){
                ans+=min(height[lmax],height[rmax])-height[l];
                l++;
            }
            else{
                ans+=max(min(height[lmax],height[rmax])-height[r],0);
                r--;
            }
        }
        return ans;
    }
};