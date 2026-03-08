class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int i=0,j=height.size()-1;
        while(i<j)
        {
            int area=min(height[i],height[j])*(j-i);
            if(ans<area) ans=area;
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};