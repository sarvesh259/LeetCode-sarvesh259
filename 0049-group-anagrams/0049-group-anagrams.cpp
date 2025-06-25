class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         map<string,vector<string>> mp;
        for(auto &i:strs)
        {
            vector<int> hash(26,0);
            for(auto &j:i)
            {
                hash[j-'a']++;
            }
            string temp="";
            for(int j=0;j<26;j++)
            {
                temp+=to_string(hash[j])+",";
            }
            mp[temp].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto &i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};