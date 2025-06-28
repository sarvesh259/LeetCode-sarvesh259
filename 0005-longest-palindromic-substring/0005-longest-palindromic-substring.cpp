class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int maxLen=0;
        for(int i=0;i<s.size();i++)
        {
            //odd
            int j=i,k=i;
            while(j>=0&&k<s.size()&&s[j]==s[k])
            {
                if(k-j+1>maxLen)
                {
                    maxLen=k-j+1;
                    ans=s.substr(j,k-j+1);
                }
                j--;
                k++;
            }
            //even
            j=i,k=i+1;
            while(j>=0&&k<s.size()&&s[j]==s[k])
            {
                if(k-j+1>maxLen)
                {
                    maxLen=k-j+1;
                    ans=s.substr(j,k-j+1);
                }
                j--;
                k++;
            }
        }
        return ans;
    }
};