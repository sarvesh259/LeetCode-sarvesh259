class Solution {
public:
    void addo(string s,vector<int> &t)
    {
        vector<int> ti(26,0);
        for(int i=0;i<s.size();i++)
        {
            ti[s[i]-'a']++;
            t[s[i]-'a']=max(t[s[i]-'a'],ti[s[i]-'a']);
        }
    }
    void f(vector<int> &t,string s)
    {
        for(int i=0;i<s.length();i++)
        {
            t[s[i]-'a']++;
        }
    }
    bool comp(vector<int> &t1,vector<int> &t2)
    {
        for(int i=0;i<26;i++)
        {
            if(t1[i]>t2[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> req(26,0);
        for(int i=0;i<words2.size();i++)
        {
            addo(words2[i],req);
        }
        cout<<endl;
        vector<string> ans;
        for(int i=0;i<words1.size();i++)
        {
            vector<int> temp(26,0);
            f(temp,words1[i]);
            /*for(int i=0;i<26;i++)
            {
                cout<<temp[i]<<" ";
            }*/
            if(comp(req,temp))
            {
                ans.push_back(words1[i]);
            }
            
        }
        return ans;
    }
};