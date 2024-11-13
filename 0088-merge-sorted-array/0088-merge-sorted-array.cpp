class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap=((m+n)/2)+((m+n)%2);
        while(nums1.size()!=m)
            nums1.pop_back();
        int i=0,j=gap;
        while(gap>0)
        {
            while(j<m+n)
            {
                if(i<m&&j<m)
                {
                    if(nums1[i]>nums1[j])
                    {
                        swap(nums1[i],nums1[j]);
                    }
                }
                else if(i<m&&j>=m)
                {
                    if(nums1[i]>nums2[j-m])
                    {
                        swap(nums1[i],nums2[j-m]);
                    }
                }
                else
                {
                    if(nums2[i-m]>nums2[j-m])
                    {
                        swap(nums2[i-m],nums2[j-m]);
                    }
                }
                i++;
                j++;
            }
            i=0;
            if(gap==1) break;
            gap=(gap/2)+(gap%2);
            j=gap;
        }
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
    }
};