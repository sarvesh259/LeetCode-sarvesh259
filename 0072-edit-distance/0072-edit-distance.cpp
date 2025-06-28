class Solution {
public:
    int minDistance(string s1, string s2) {
        // vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
        vector<int> cur(s2.size()+1,0);
        vector<int> prev(s2.size()+1,0);
        for(int i=0;i<=s2.size();i++) prev[i]=i;
        for (int i = 1; i <= s1.size(); i++) {
            cur[0]=i;
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i-1] == s2[j-1])
                    cur[j] = prev[j - 1];
                else
                    cur[j]= 1+min(prev[j],min(prev[j-1],cur[j-1]));
            }
            prev=cur;
        }
        return prev[s2.size()];
    }
};