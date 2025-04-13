class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto i:matrix)
        {
            if(i[0]<=target&&i[i.size()-1]>=target)
            {
                int p=0,q=i.size()-1;
                while(p<=q)
                {
                    int mid=p+((q-p)>>1);
                    if(i[mid]==target)
                    {
                        return true;
                    }
                    if(i[mid]<target)
                    {
                        p=mid+1;
                    }
                    else
                    {
                        q=mid-1;
                    }
                }
            }
        }
        return false;
    }
};