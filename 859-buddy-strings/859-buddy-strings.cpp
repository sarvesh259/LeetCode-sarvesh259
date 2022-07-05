class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        int n=s.size()-1;
        string a=s,b=goal;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a!=b)
            return false;
        int ans=0;
        while(n>=0)
        {
            if(s[n]!=goal[n])
            {
                ans++;
            }
            n--;
        }
        if(ans==2)
          return true;
        sort(s.begin(),s.end());
        bool temp=false;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                temp=true;
                break;
            }
        }
        if(ans==0&&temp)
            return true;
        return false;
    }
};