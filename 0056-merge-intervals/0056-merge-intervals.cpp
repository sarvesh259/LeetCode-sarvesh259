class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int curr=0;
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            if(ans[curr][1]>=intervals[i][0])
            {
                ans[curr][1]=max(intervals[i][1],ans[curr][1]);
            }
            else{
                curr++;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};