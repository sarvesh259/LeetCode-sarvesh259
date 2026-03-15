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
        double prev=(double)(target-vp[0].first)/vp[0].second;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            double cur=(double)(target-vp[i].first)/vp[i].second;
            if(cur>prev){
                prev=cur;
                ans++;
            }
        }
        return ans;
    }
};