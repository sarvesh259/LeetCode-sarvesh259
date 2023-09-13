class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> e(100001,0);
        int maxi=-1,freq=-1;
        for(auto i:edges)
        {
            e[i[0]]++;
            if(e[i[0]]>freq)
            {
                maxi=i[0];
                freq=e[i[0]];
            }
            e[i[1]]++;
            if(e[i[1]]>freq)
            {
                maxi=i[1];
                freq=e[i[1]];
            }
        }
        return maxi;
    }
};