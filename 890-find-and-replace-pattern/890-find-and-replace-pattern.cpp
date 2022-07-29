class Solution {
public:
    vector<int> f(string s)
    {
        vector<int> ans;
        if(s.length()==0)
            return {};
        unordered_map<char,int> a;
        int ind=0;
        for(int i=0;i<s.size();i++)
        {
            if(a[(s[i])]==0)
            {
                ind++;
                a[s[i]]=ind;
                ans.push_back(ind);
            }
            else{
                ans.push_back(a[s[i]]);
            }
        }
        return ans;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> req=f(pattern);
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            vector<int> temp=f(words[i]);
            if(temp==req)
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};