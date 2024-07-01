class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int t=0;
        for(auto i:arr)
        {
            if(t==3)
                return true;
            if(i&1)
                t++;
            else t=0;
        }
        return false;
    }
};