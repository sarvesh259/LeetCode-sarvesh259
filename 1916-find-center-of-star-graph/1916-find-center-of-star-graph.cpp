class Solution {
public:
    int findCenter(vector<vector<int>>& i) {
        unordered_set<int> st;
        int size=0;
        st.insert(i[0][0]);
        st.insert(i[0][1]);
        st.insert(i[1][0]);
        return st.size()==2?i[1][0]:i[1][1];
    }
};