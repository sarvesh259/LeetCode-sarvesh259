class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int maxFreq=0;
        int i=0,j=0,ans=0;
        while(j<s.size())
        {
            freq[s[j]-'A']++;
            maxFreq=max(maxFreq,freq[s[j]-'A']);
            while(i<j&&j-i+1-maxFreq>k)
            {
                freq[s[i]-'A']--;
                maxFreq=max(maxFreq,freq[s[i]-'A']);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
            // cout<<ans<<" "<<freq[maxFreq]<<endl;
        }
        ans=max(ans,j-i);
        return ans;
    }
};