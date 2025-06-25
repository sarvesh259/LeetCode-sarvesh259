class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')))
            {
                i++;
                continue;
            }
            if(!((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')||(s[j]>='0'&&s[j]<='9')))
            {
                j--;
                continue;
            }
            char a=s[i];
            char b=s[j];
            if(a>='A'&&a<='Z')
            {
                a=a-'A'+'a';
            }
            if(b>='A'&&b<='Z')
            {
                b=b-'A'+'a';
            }
            if(a!=b)
                return false;
            i++;
            j--;
        }
        return true;
    }
};