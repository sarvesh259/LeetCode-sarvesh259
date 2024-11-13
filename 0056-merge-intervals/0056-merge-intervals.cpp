class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),comp);
        vector<vector<int>> ans;
        int p=a[0][0],q=a[0][1];
        for(int i=1;i<a.size();i++)
        {
            if(a[i][0]<=q)
            {
                q=max(q,a[i][1]);
            }
            else
            {
                vector<int> temp;
                temp.push_back(p);
                temp.push_back(q);
                ans.push_back(temp);

                p=a[i][0];
                q=a[i][1];
            }
        }
        vector<int> temp;
        temp.push_back(p);
        temp.push_back(q);
        ans.push_back(temp);
        return  ans;
    }
};