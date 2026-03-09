class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,maxi=0;
        vector<int> mp(26,0);
        int res=0;
        for(int r=0;r<s.size();r++)
        {
            mp[s[r]-'A']++;
            maxi=max(maxi,mp[s[r]-'A']);

            while(r-l+1-maxi > k){
                mp[s[l]-'A']--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};