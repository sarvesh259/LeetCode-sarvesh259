class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& s) {
        int n=s.size();
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({pos[i],s[i]});
        }
        sort(vp.rbegin(),vp.rend());
        stack<double> st;
        st.push((double)(target-vp[0].first)/vp[0].second);
        cout<<st.top()<<endl;
        for(int i=1;i<n;i++)
        {
            double temp=(double)(target-vp[i].first)/vp[i].second;
            cout<<temp<<endl;
            if(st.top()<temp){
                st.push(temp);
            }
        }
        return st.size();
    }
};