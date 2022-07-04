class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,n=haystack.size(),j=needle.size();
        while(i<n)
        {
            if(haystack[i]==needle[0])
            {
                for(int p=0;p<j;p++)
                {
                    if(haystack[i+p]!=needle[p])
                    {
                        break;
                    }
                    if(p+1==j)
                    {
                        return i;
                    }
                }
            }
            i++;
        }
        return -1;
        }
};