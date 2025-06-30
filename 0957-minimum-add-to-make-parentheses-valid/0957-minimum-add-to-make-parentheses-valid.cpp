class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int i=0,cnt=0;
        while(i<s.size())
        {
            if(s[i]=='(')
            {
                st.push(1);
            }
            else
            {
                if(!st.empty())
                    st.pop();
                else
                    cnt++;
            }
            i++;
        }
        return st.size()+cnt;
    }
};