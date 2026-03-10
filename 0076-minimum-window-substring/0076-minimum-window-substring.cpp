class Solution {
public:
    bool isSubstring(map<char,int> &mp1,map<char,int> &mp2)
    {
        for(auto &i:mp1)
        {
            if(mp2[i.first]<mp1[i.first])
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        string res="";
        int l=0;
        map<char,int> mp1;
        map<char,int> mp2;
        for(char &c:t){
            mp1[c]++;
        }
        for(int r=0;r<s.size();r++)
        {
            mp2[s[r]]++;
            if(isSubstring(mp1,mp2)){
                while( mp1[s[l]] <= mp2[s[l]] - 1){
                    mp2[s[l]]--;
                    l++;
                }
                if(res=="" || res.size()>r-l+1){
                    res=s.substr(l,r-l+1);
                }
            }
        }
        return res;
    }
};