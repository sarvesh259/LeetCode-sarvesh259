class Solution {
public:
    string shortestPalindrome(string s) {
        long long prefixHash = 0, reverseHash = 0;
        long long base = 29, mod = 1e9 + 7;
        long long power = 1;
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            int val = s[i] - 'a' + 1;

            prefixHash = (prefixHash * base + val) % mod;
            reverseHash = (reverseHash + val * power) % mod;

            if (prefixHash == reverseHash) {
                maxLen = i + 1;
            }

            power = (power * base) % mod;
        }

        string suffix = s.substr(maxLen);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};

// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         long long pre = 0;
//         long long suf = 0;
//         long long base = 29;
//         long long power = 29;
//         long long best = -1;
//         long long mod = 1e9 + 7;

//         for(int i=0;i<s.size();i++)
//         {
//             int front = s[i]-'a'+1;
//             int back = s[s.size()-1-i]-'a'+1;
            
//             pre = ((pre * base) + front) % mod;
//             suf = ((suf * base) + back) % mod;

//             if(pre==suf) best = i;

//             power = (power * base) % mod;
//         }
//         cout<<best;

//          if (best == s.size() - 1) {
//             return s;
//         }
//         string toAdd = s.substr(best + 1);
//         reverse(toAdd.begin(), toAdd.end());
//         return toAdd + s;
//     }
// };