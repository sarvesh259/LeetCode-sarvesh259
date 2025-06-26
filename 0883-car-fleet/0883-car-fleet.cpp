class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& s) {
        vector<pair<int,int>> vp;
        for(int i=0;i<s.size();i++)
        {
            vp.push_back({pos[i],s[i]});
        }
        sort(vp.rbegin(),vp.rend());
        vector<double> st;
        for(auto &i:vp)
        {
            st.push_back((double)(target-i.first)/i.second);
            if(st.size()>=2&&st.back()<=st[st.size()-2])
            {
                st.pop_back();
            }
        }
        return st.size();
    }
};