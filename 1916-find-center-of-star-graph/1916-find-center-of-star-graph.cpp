class Solution {
public:
    int findCenter(vector<vector<int>>& i) {
        if(i[0][0]==i[1][0])
            return i[0][0];
        if(i[0][0]==i[1][1])
            return i[1][1];
        return i[0][1];
    }
};