class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        int count = 0;

        for (int i = 0; i < s1.size(); i++) {
            mp1[s1[i] - 'a']++;
            mp2[s2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (mp1[i] == mp2[i]) {
                count++;
            }
        }

        int l = 0;
        for (int i = s1.size(); i < s2.size(); i++) {
            if (count == 26) {
                return true;
            }
            int ch = s2[i] - 'a';
            mp2[ch]++;
            if (mp2[ch] == mp1[ch]) {
                count++;
            } else if (mp2[ch] == mp1[ch] + 1) {
                count--;
            }
            ch = s2[l] - 'a';
            mp2[ch]--;
            if (mp2[ch] == mp1[ch]) {
                count++;
            } else if (mp2[ch] == mp1[ch] - 1) {
                count--;
            }
            l++;
        }
        return count == 26;
    }
};