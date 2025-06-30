class Solution {
public:
    int minAddToMakeValid(string s) {
        int i=0,c=0,cnt=0;
        while(i<s.size())
        {
            if(s[i]=='(')
            {
                c++;
            }
            else
            {
                if(c)
                    c--;
                else
                    cnt++;
            }
            i++;
        }
        return c+cnt;
    }
};