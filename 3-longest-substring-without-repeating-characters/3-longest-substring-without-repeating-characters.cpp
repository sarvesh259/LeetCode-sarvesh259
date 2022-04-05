class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<const char,int> a;
        int ans=0;
        if(s.length()==1)
        {
            return 1;
        }
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                a[s[j]]++;
                if(a[s[j]]>1)
                {
                    int temp=a.size();
                    if(temp>ans)
                    {
                        ans=temp;
                    }
                    a.clear();
                    break;
                }
            }
        }
        return ans;
    }
};