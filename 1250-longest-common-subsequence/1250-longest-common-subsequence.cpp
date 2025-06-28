class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        vector<int> cur(s2.size() + 1, 0),next(s2.size() + 1, 0);
        for (int i = s1.size() - 1; i >= 0; i--) {
            for (int j = s2.size() - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    cur[j] = 1 + next[j + 1];
                } else {
                    cur[j] = max(next[j], cur[j + 1]);
                }
            }
            next=cur;
        }
        return next[0];
    }
};